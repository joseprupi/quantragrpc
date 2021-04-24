// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

import { FlowsWrapper } from '../quantra/flows-wrapper';


export class FixedRateBondResponse {
  bb: flatbuffers.ByteBuffer | null = null;
  bb_pos = 0;
  __init(i: number, bb: flatbuffers.ByteBuffer): FixedRateBondResponse {
    this.bb_pos = i;
    this.bb = bb;
    return this;
  }

  static getRootAsFixedRateBondResponse(bb: flatbuffers.ByteBuffer, obj?: FixedRateBondResponse): FixedRateBondResponse {
    return (obj || new FixedRateBondResponse()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
  }

  static getSizePrefixedRootAsFixedRateBondResponse(bb: flatbuffers.ByteBuffer, obj?: FixedRateBondResponse): FixedRateBondResponse {
    bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
    return (obj || new FixedRateBondResponse()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
  }

  npv(): number {
    const offset = this.bb!.__offset(this.bb_pos, 4);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  cleanPrice(): number {
    const offset = this.bb!.__offset(this.bb_pos, 6);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  dirtyPrice(): number {
    const offset = this.bb!.__offset(this.bb_pos, 8);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  accruedAmount(): number {
    const offset = this.bb!.__offset(this.bb_pos, 10);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  // yield():number {
  //   const offset = this.bb!.__offset(this.bb_pos, 12);
  //   return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  // }

  accruedDays(): number {
    const offset = this.bb!.__offset(this.bb_pos, 14);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  macaulayDuration(): number {
    const offset = this.bb!.__offset(this.bb_pos, 16);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  modifiedDuration(): number {
    const offset = this.bb!.__offset(this.bb_pos, 18);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  convexity(): number {
    const offset = this.bb!.__offset(this.bb_pos, 20);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  bps(): number {
    const offset = this.bb!.__offset(this.bb_pos, 22);
    return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
  }

  flows(index: number, obj?: FlowsWrapper): FlowsWrapper | null {
    const offset = this.bb!.__offset(this.bb_pos, 24);
    return offset ? (obj || new FlowsWrapper()).__init(this.bb!.__indirect(this.bb!.__vector(this.bb_pos + offset) + index * 4), this.bb!) : null;
  }

  flowsLength(): number {
    const offset = this.bb!.__offset(this.bb_pos, 24);
    return offset ? this.bb!.__vector_len(this.bb_pos + offset) : 0;
  }

  static startFixedRateBondResponse(builder: flatbuffers.Builder) {
    builder.startObject(11);
  }

  static addNpv(builder: flatbuffers.Builder, npv: number) {
    builder.addFieldFloat64(0, npv, 0.0);
  }

  static addCleanPrice(builder: flatbuffers.Builder, cleanPrice: number) {
    builder.addFieldFloat64(1, cleanPrice, 0.0);
  }

  static addDirtyPrice(builder: flatbuffers.Builder, dirtyPrice: number) {
    builder.addFieldFloat64(2, dirtyPrice, 0.0);
  }

  static addAccruedAmount(builder: flatbuffers.Builder, accruedAmount: number) {
    builder.addFieldFloat64(3, accruedAmount, 0.0);
  }

  // static addYield(builder:flatbuffers.Builder, yield:number) {
  //   builder.addFieldFloat64(4, yield, 0.0);
  // }

  static addAccruedDays(builder: flatbuffers.Builder, accruedDays: number) {
    builder.addFieldFloat64(5, accruedDays, 0.0);
  }

  static addMacaulayDuration(builder: flatbuffers.Builder, macaulayDuration: number) {
    builder.addFieldFloat64(6, macaulayDuration, 0.0);
  }

  static addModifiedDuration(builder: flatbuffers.Builder, modifiedDuration: number) {
    builder.addFieldFloat64(7, modifiedDuration, 0.0);
  }

  static addConvexity(builder: flatbuffers.Builder, convexity: number) {
    builder.addFieldFloat64(8, convexity, 0.0);
  }

  static addBps(builder: flatbuffers.Builder, bps: number) {
    builder.addFieldFloat64(9, bps, 0.0);
  }

  static addFlows(builder: flatbuffers.Builder, flowsOffset: flatbuffers.Offset) {
    builder.addFieldOffset(10, flowsOffset, 0);
  }

  static createFlowsVector(builder: flatbuffers.Builder, data: flatbuffers.Offset[]): flatbuffers.Offset {
    builder.startVector(4, data.length, 4);
    for (let i = data.length - 1; i >= 0; i--) {
      builder.addOffset(data[i]!);
    }
    return builder.endVector();
  }

  static startFlowsVector(builder: flatbuffers.Builder, numElems: number) {
    builder.startVector(4, numElems, 4);
  }

  static endFixedRateBondResponse(builder: flatbuffers.Builder): flatbuffers.Offset {
    const offset = builder.endObject();
    return offset;
  }

  static createFixedRateBondResponse(builder: flatbuffers.Builder, npv: number, cleanPrice: number, dirtyPrice: number, accruedAmount: number, accruedDays: number, macaulayDuration: number, modifiedDuration: number, convexity: number, bps: number, flowsOffset: flatbuffers.Offset): flatbuffers.Offset {
    FixedRateBondResponse.startFixedRateBondResponse(builder);
    FixedRateBondResponse.addNpv(builder, npv);
    FixedRateBondResponse.addCleanPrice(builder, cleanPrice);
    FixedRateBondResponse.addDirtyPrice(builder, dirtyPrice);
    FixedRateBondResponse.addAccruedAmount(builder, accruedAmount);
    //FixedRateBondResponse.addYield(builder, yield);
    FixedRateBondResponse.addAccruedDays(builder, accruedDays);
    FixedRateBondResponse.addMacaulayDuration(builder, macaulayDuration);
    FixedRateBondResponse.addModifiedDuration(builder, modifiedDuration);
    FixedRateBondResponse.addConvexity(builder, convexity);
    FixedRateBondResponse.addBps(builder, bps);
    FixedRateBondResponse.addFlows(builder, flowsOffset);
    return FixedRateBondResponse.endFixedRateBondResponse(builder);
  }

  serialize(): Uint8Array {
    return this.bb!.bytes();
  }

  static deserialize(buffer: Uint8Array): FixedRateBondResponse {
    return FixedRateBondResponse.getRootAsFixedRateBondResponse(new flatbuffers.ByteBuffer(buffer))
  }
}
