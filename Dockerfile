FROM debian:buster AS builder

RUN apt-install cmake make git QuantLib-devel gcc


