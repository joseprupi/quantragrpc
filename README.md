# Introduction

Quantra is a pricing engine based on QuantLib that allows distributed compuations and serializing QuantLib objects to JSON and Flatbuffers binary format.

## Why

QuantLib is a quantitative finance library written in C++ and a standard in the industry but it could also be seen as a low level library that brings some drawbacks in terms of usability such as:

* Written in C++ (an active Python extension being developed that solves this problem)
* Not able to be executed in multithreading fashion to parallelize computations because of its design

## How

Quantra tries to solve this problems running different instances of QuantLib in separate processes that are executed as gRPC servers that communicate with the clients using Flatbuffers binary format.

### Architecture

Quantra allows to execute different processes serving gRPC requests sent by the clients and serialized with Flatbuffers format.

These requests are being processed by an Envoy proxy that forwards them to each of the processes running in the background in a Round Robin fashion.

![Arqchitecture](docs/architecture.jpg?raw=true "Arqchitecture")

