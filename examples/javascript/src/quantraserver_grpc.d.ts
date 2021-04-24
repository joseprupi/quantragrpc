// Generated GRPC code for FlatBuffers TS *** DO NOT EDIT ***
import { flatbuffers } from 'flatbuffers';
import { PriceFixedRateBondResponse as quantra_PriceFixedRateBondResponse } from './quantra/price-fixed-rate-bond-response';
import { PriceFixedRateBondRequest as quantra_PriceFixedRateBondRequest } from './quantra/price-fixed-rate-bond-request';

import * as grpc from 'grpc';

interface IQuantraServerService extends grpc.ServiceDefinition<grpc.UntypedServiceImplementation> {
  PriceFixedRateBond: IQuantraServerService_IPriceFixedRateBond;
}
interface IQuantraServerService_IPriceFixedRateBond extends grpc.MethodDefinition<quantra_PriceFixedRateBondRequest, quantra_PriceFixedRateBondResponse> {
  path: string; // /quantra.QuantraServer/PriceFixedRateBond
  requestStream: boolean; // false
  responseStream: boolean; // false
  requestSerialize: grpc.serialize<quantra_PriceFixedRateBondRequest>;
  requestDeserialize: grpc.deserialize<quantra_PriceFixedRateBondRequest>;
  responseSerialize: grpc.serialize<quantra_PriceFixedRateBondResponse>;
  responseDeserialize: grpc.deserialize<quantra_PriceFixedRateBondResponse>;
}


export const QuantraServerService: IQuantraServerService;

export interface IQuantraServerServer {
  PriceFixedRateBond: grpc.handleUnaryCall<quantra_PriceFixedRateBondRequest, quantra_PriceFixedRateBondResponse>;
}

export interface IQuantraServerClient {
  PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
  PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
  PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
}

export class QuantraServerClient extends grpc.Client implements IQuantraServerClient {
  constructor(address: string, credentials: grpc.ChannelCredentials, options?: object);  public PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
  public PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, metadata: grpc.Metadata, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
  public PriceFixedRateBond(request: quantra_PriceFixedRateBondRequest, metadata: grpc.Metadata, options: Partial<grpc.CallOptions>, callback: (error: grpc.ServiceError | null, response: quantra_PriceFixedRateBondResponse) => void): grpc.ClientUnaryCall;
}

