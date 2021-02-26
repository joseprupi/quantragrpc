#!/bin/bash

trap "kill 0" EXIT

start_port=$QUANTRA_PORT
n_servers=$1

end_port=$[$start_port+$n_servers]

while [ $start_port -lt $end_port ]
do
/root/quantra/build/server/async_server $start_port &
start_port=$[$start_port+1]
done

python3 -c "from envoy_config import config; config($1, $2)"
envoy -c data.yaml &
python3 -c "from envoy_config import check_clusters_health; check_clusters_health()"

wait