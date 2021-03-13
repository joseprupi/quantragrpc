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

The main format of quantra is Flatbuffers which is used to communicate with the server. As the serialization to Flatbuffers can be tedious part of the client implementation translates from quantra defined C++ structs to Flatbuffers. 

See https://github.com/joseprupi/quantragrpc/blob/master/examples/data/fixed_rate_bond_request_quantra.h for a complete example on how to build a request to price a fixed rate bond. The snippet below shows how to create a deposit pillar to create a curve in C++ and JSON formats.

```c++
auto deposit_zc3m = std::make_shared<structs::DepositHelper>();
deposit_zc3m->rate = 0.0096;
deposit_zc3m->tenor_time_unit = TimeUnit_Months;
deposit_zc3m->tenor_number = 3;
deposit_zc3m->fixing_days = 3;
deposit_zc3m->calendar = Calendar_TARGET;
deposit_zc3m->business_day_convention = BusinessDayConvention_ModifiedFollowing;
deposit_zc3m->day_counter = DayCounter_Actual365Fixed;

auto deposit_zc3m_point = std::make_shared<structs::Point>();
deposit_zc3m_point->point_type = Deposit;
deposit_zc3m_point->deposit_helper = deposit_zc3m;
```

``` json
{
"point_wrapper_type": "DepositHelper",
"point_wrapper": {
  "tenor_time_unit": "Months",
  "tenor_number": 3,
  "fixing_days": 3,
  "calendar": "TARGET",
  "business_day_convention": "ModifiedFollowing",
  "day_counter": "Actual365Fixed"
}
}
```

Once the data has been serialized this can be stored in binary or JSON format, this is part of Flatbuffers core functionalities.

![Data](docs/data.jpg?raw=true "Data")

## Examples

## Install

### Requirements
* gRPC and Flatbuffers. Follow the instructions from Flatbuffers at https://github.com/google/flatbuffers/tree/master/grpc. 
  * Build gRPC with -DBUILD_SHARED_LIBS=ON for shared libraries.
  * When writing this Flatbuffers does not support gRPC, it used to but at some point gRPC broke its compatibility but hopefully it will be solved soon. Apply this manually to solve it https://github.com/google/flatbuffers/pull/6338 
* QuantLib. See https://www.quantlib.org/install.shtml
* CMake

### Build Quantra

After cloning the repository set the variables inside **config_vars.sh**.

```console
git clone https://github.com/joseprupi/quantragrpc
cd quantragrpc
. ./scripts/config_vars.sh
mkdir build
cd build
cmake ..
make -j
```

## Usage



## Formating data

## Nice to have

### Architecture

* A Python client for quantra. This is pending from Flatbuffers project to support gRPC for Python, [see this](https://github.com/google/flatbuffers/issues/4109). 
* Having a shared cache for interprocess communications to avoid repeated calculations such as curve bootstrapping (currently working on this)

![Arqchitecture](docs/architecture2.jpg?raw=true "Arqchitecture")

### Data

An implementation to translate from QuantLib native objects to Flatbuffers, this would make easy adapting to Quantra already existing developments in QuantLib. Also it would be possible to store QuantLib objects in Flatbuffers and JSON format (just the client library would be needed).

![Data](docs/data2.jpg?raw=true "Data")

