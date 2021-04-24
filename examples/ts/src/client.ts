import grpc from 'grpc';

import { PriceFixedRateBondRequest } from './quantra/price-fixed-rate-bond-request';
//import { PriceFixedRateBondResponse } from './quantra/price-fixed-rate-bond-response';
import { QuantraServerClient } from './quantraserver_grpc';
import { flatbuffers } from 'flatbuffers';

async function main(PORT: Number, name: String) {
    const _server = new QuantraServerClient(`localhost:${PORT}`, grpc.credentials.createInsecure());
    const builder = new flatbuffers.Builder();
    const offset = builder.createString(name);
    const offset2 = builder.createString(name);
    const root = PriceFixedRateBondRequest.createPriceFixedRateBondRequest(builder, offset, offset2);
    builder.finish(root);
    const buffer = PriceFixedRateBondRequest.getRootAsPriceFixedRateBondRequest(new flatbuffers.ByteBuffer(builder.asUint8Array()));

    _server.PriceFixedRateBond(buffer, (err, response) => {
        console.log(err);
    });
}

const args = process.argv.slice(2)
const PORT = Number(args[0]);
const name = String(args[1] ?? "flatbuffers");

if (PORT) {
    main(PORT, name);
} else {
    throw new Error("Requires a valid port number.")
}