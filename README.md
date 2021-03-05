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

### Data format

The main format of quantra is Flatbuffers which is used to communicate with the server.

As the serialization to Flatbuffers can be tedious part of the client implementation translates from quantra defined C++ structs to Flatbuffers. 

Once the data has been serialized this can be stored in binary or JSON format, this is part of Flatbuffers core functionalities.

![Data](docs/data.jpg?raw=true "Data")

# Examples

## C++

## Formating data

## Nice to have

### Architecture

* It would be nice to have a Python client for quantra. This is pending from Flatbuffers project to support gRPC for Python, [see this](https://github.com/google/flatbuffers/issues/4109). 
* Having a cache for interprocess communications for things such as bootstrapped curves and avoid recalculation (I am currently working on this)

![Arqchitecture](docs/architecture2.jpg?raw=true "Arqchitecture")

### Data

It would be nice to have an implementation to translate from QuantLib native objects to Flatbuffers. This way translating to Quantra the already existing implementation using QuantLib would be easier. Also, with something like this, and without the server, it would be possible to store QuantLib objects in Flatbuffers and JSON format.

![Data](docs/data2.jpg?raw=true "Data")

