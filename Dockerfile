FROM debian:bookworm AS builder

RUN     apt-get update && \
        apt-get install -y apt-transport-https ca-certificates curl gnupg2 software-properties-common && \
        curl -sL https://apt.envoyproxy.io/signing.key | gpg --dearmor -o /etc/apt/keyrings/envoy-keyring.gpg && \
        echo "deb [signed-by=/etc/apt/keyrings/envoy-keyring.gpg] https://apt.envoyproxy.io bookworm main" | tee /etc/apt/sources.list.d/envoy.list && \
        apt-get update && \
        apt-get install -y \
        git python3-pip build-essential autoconf libtool pkg-config cmake libssl-dev libboost-all-dev tar wget envoy \
	python3-requests python3-yaml flatbuffers-compiler libflatbuffers-dev \
	libprotobuf-dev libasio-dev

# gRPC
RUN     cd root && \
        git clone -b v1.67.1 https://github.com/grpc/grpc && \
        cd grpc && \
        git submodule update --init && \
        mkdir -p "third_party/abseil-cpp/cmake/build" && \
        cd ./third_party/abseil-cpp/cmake/build && \
        cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE ../.. && \
        make -j install && \
        cd /root/grpc && \
        mkdir install && \
        mkdir -p cmake/build && \
        cd cmake/build && \
        cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DgRPC_INSTALL=ON \
        -DgRPC_BUILD_TESTS=OFF \
        -DgRPC_ABSL_PROVIDER=package \
        -DgRPC_SSL_PROVIDER=package \
        -DBUILD_SHARED_LIBS=ON \
        ../.. && \
        make -j$((`nproc`*2)) && \
        make install && \
	rm -rf /root/grpc

RUN     cd /root && \
        wget https://github.com/lballabio/QuantLib/releases/download/v1.36/QuantLib-1.36.tar.gz && \
        tar -zxvf QuantLib-1.36.tar.gz && \
        cd QuantLib-1.36 && \
        ./configure --enable-std-pointers && \
        make -j$((`nproc`*2)) && \
        make install && \
        ldconfig && \
	cd .. && \
	rm -rf QuantLib-1.36 QuantLib-1.36.tar.gz

# Quantra
RUN     cd /root && \
        git clone https://github.com/joequant/quantragrpc && \
        cd quantragrpc && \
        . ./scripts/config_vars.sh && \
        mkdir build && \
        cd build && \
        cmake ../ && \ 
        make -j$((`nproc`*2))

COPY ./start.sh /root/quantragrpc
CMD /bin/bash /root/quantragrpc/start.sh
