// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';

export class FlowPastInterest {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
__init(i:number, bb:flatbuffers.ByteBuffer):FlowPastInterest {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsFlowPastInterest(bb:flatbuffers.ByteBuffer, obj?:FlowPastInterest):FlowPastInterest {
  return (obj || new FlowPastInterest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsFlowPastInterest(bb:flatbuffers.ByteBuffer, obj?:FlowPastInterest):FlowPastInterest {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new FlowPastInterest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
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

rate():number {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? this.bb!.readFloat32(this.bb_pos + offset) : 0.0;
}

static startFlowPastInterest(builder:flatbuffers.Builder) {
  builder.startObject(4);
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

static addRate(builder:flatbuffers.Builder, rate:number) {
  builder.addFieldFloat32(3, rate, 0.0);
}

static endFlowPastInterest(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createFlowPastInterest(builder:flatbuffers.Builder, amount:number, accrualStartDateOffset:flatbuffers.Offset, accrualEndDateOffset:flatbuffers.Offset, rate:number):flatbuffers.Offset {
  FlowPastInterest.startFlowPastInterest(builder);
  FlowPastInterest.addAmount(builder, amount);
  FlowPastInterest.addAccrualStartDate(builder, accrualStartDateOffset);
  FlowPastInterest.addAccrualEndDate(builder, accrualEndDateOffset);
  FlowPastInterest.addRate(builder, rate);
  return FlowPastInterest.endFlowPastInterest(builder);
}
}
