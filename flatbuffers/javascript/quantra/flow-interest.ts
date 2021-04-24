// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

export class FlowInterest {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
__init(i:number, bb:flatbuffers.ByteBuffer):FlowInterest {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsFlowInterest(bb:flatbuffers.ByteBuffer, obj?:FlowInterest):FlowInterest {
  return (obj || new FlowInterest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsFlowInterest(bb:flatbuffers.ByteBuffer, obj?:FlowInterest):FlowInterest {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new FlowInterest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

amount():number {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.readFloat64(this.bb_pos + offset) : 0.0;
}

accrualStartDate():string|null
accrualStartDate(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
accrualStartDate(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

accrualEndDate():string|null
accrualEndDate(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
accrualEndDate(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 8);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

discount():number {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? this.bb!.readFloat32(this.bb_pos + offset) : 0.0;
}

rate():number {
  const offset = this.bb!.__offset(this.bb_pos, 12);
  return offset ? this.bb!.readFloat32(this.bb_pos + offset) : 0.0;
}

price():number {
  const offset = this.bb!.__offset(this.bb_pos, 14);
  return offset ? this.bb!.readFloat32(this.bb_pos + offset) : 0.0;
}

static startFlowInterest(builder:flatbuffers.Builder) {
  builder.startObject(6);
}

static addAmount(builder:flatbuffers.Builder, amount:number) {
  builder.addFieldFloat64(0, amount, 0.0);
}

static addAccrualStartDate(builder:flatbuffers.Builder, accrualStartDateOffset:flatbuffers.Offset) {
  builder.addFieldOffset(1, accrualStartDateOffset, 0);
}

static addAccrualEndDate(builder:flatbuffers.Builder, accrualEndDateOffset:flatbuffers.Offset) {
  builder.addFieldOffset(2, accrualEndDateOffset, 0);
}

static addDiscount(builder:flatbuffers.Builder, discount:number) {
  builder.addFieldFloat32(3, discount, 0.0);
}

static addRate(builder:flatbuffers.Builder, rate:number) {
  builder.addFieldFloat32(4, rate, 0.0);
}

static addPrice(builder:flatbuffers.Builder, price:number) {
  builder.addFieldFloat32(5, price, 0.0);
}

static endFlowInterest(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createFlowInterest(builder:flatbuffers.Builder, amount:number, accrualStartDateOffset:flatbuffers.Offset, accrualEndDateOffset:flatbuffers.Offset, discount:number, rate:number, price:number):flatbuffers.Offset {
  FlowInterest.startFlowInterest(builder);
  FlowInterest.addAmount(builder, amount);
  FlowInterest.addAccrualStartDate(builder, accrualStartDateOffset);
  FlowInterest.addAccrualEndDate(builder, accrualEndDateOffset);
  FlowInterest.addDiscount(builder, discount);
  FlowInterest.addRate(builder, rate);
  FlowInterest.addPrice(builder, price);
  return FlowInterest.endFlowInterest(builder);
}
}
