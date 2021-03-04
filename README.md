Quantra is a pricing engine based on QuantLib that allows distributed compuations and serializing quantra objects to JSON and Flatbuffers binary format.

## Why

QuantLib is a quantitative finance library written in C++ and a standard in the industry. It can also be seen as a "low level" library that brings some drawbacks in terms of usability such as:

* Written in C++ (a Python extension exists that solves this problem)
* Not able to be executed in multithreading fashion to parallelize computations because of its design

## How

Quantra tries to solve these problems with the implementation of a high level API and allowing multiple process to be executed in parallel. The latter is done running different instances of QuantLib in separate processes that are executed as gRPC servers and communicate with the clients with Flatbuffers.

### Architecture

Quantra allows to execute different processes serving gRPC requests sent by the clients and serialized with Flatbuffers format.

These requests are being processed by an Envoy proxy that forwards them to each of the processes running in the background.

![Arqchitecture](docs/architecture.jpg?raw=true "Arqchitecture")

# Examples

## C++

## Formating data

flatc --raw-binary -t ../flatbuffers/fbs/requests.fbs --json --strict-json -- ./data/fixed_rate_bond_request.bin