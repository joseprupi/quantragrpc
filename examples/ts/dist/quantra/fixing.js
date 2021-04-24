"use strict";
// automatically generated by the FlatBuffers compiler, do not modify
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    Object.defineProperty(o, k2, { enumerable: true, get: function() { return m[k]; } });
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.Fixing = void 0;
var flatbuffers = __importStar(require("flatbuffers"));
var Fixing = /** @class */ (function () {
    function Fixing() {
        this.bb = null;
        this.bb_pos = 0;
    }
    Fixing.prototype.__init = function (i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    };
    Fixing.getRootAsFixing = function (bb, obj) {
        return (obj || new Fixing()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    Fixing.getSizePrefixedRootAsFixing = function (bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new Fixing()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    Fixing.prototype.date = function (optionalEncoding) {
        var offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
    };
    Fixing.prototype.rate = function () {
        var offset = this.bb.__offset(this.bb_pos, 6);
        return offset ? this.bb.readFloat32(this.bb_pos + offset) : 0.0;
    };
    Fixing.startFixing = function (builder) {
        builder.startObject(2);
    };
    Fixing.addDate = function (builder, dateOffset) {
        builder.addFieldOffset(0, dateOffset, 0);
    };
    Fixing.addRate = function (builder, rate) {
        builder.addFieldFloat32(1, rate, 0.0);
    };
    Fixing.endFixing = function (builder) {
        var offset = builder.endObject();
        return offset;
    };
    Fixing.createFixing = function (builder, dateOffset, rate) {
        Fixing.startFixing(builder);
        Fixing.addDate(builder, dateOffset);
        Fixing.addRate(builder, rate);
        return Fixing.endFixing(builder);
    };
    Fixing.prototype.serialize = function () {
        return this.bb.bytes();
    };
    Fixing.deserialize = function (buffer) {
        return Fixing.getRootAsFixing(new flatbuffers.ByteBuffer(buffer));
    };
    return Fixing;
}());
exports.Fixing = Fixing;
//# sourceMappingURL=fixing.js.map