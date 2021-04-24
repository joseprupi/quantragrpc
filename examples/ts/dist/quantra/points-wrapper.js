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
exports.PointsWrapper = void 0;
var flatbuffers = __importStar(require("flatbuffers"));
var point_1 = require("../quantra/point");
var PointsWrapper = /** @class */ (function () {
    function PointsWrapper() {
        this.bb = null;
        this.bb_pos = 0;
    }
    PointsWrapper.prototype.__init = function (i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    };
    PointsWrapper.getRootAsPointsWrapper = function (bb, obj) {
        return (obj || new PointsWrapper()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    PointsWrapper.getSizePrefixedRootAsPointsWrapper = function (bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new PointsWrapper()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    PointsWrapper.prototype.pointWrapperType = function () {
        var offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? this.bb.readUint8(this.bb_pos + offset) : point_1.Point.NONE;
    };
    PointsWrapper.prototype.pointWrapper = function (obj) {
        var offset = this.bb.__offset(this.bb_pos, 6);
        return offset ? this.bb.__union(obj, this.bb_pos + offset) : null;
    };
    PointsWrapper.startPointsWrapper = function (builder) {
        builder.startObject(2);
    };
    PointsWrapper.addPointWrapperType = function (builder, pointWrapperType) {
        builder.addFieldInt8(0, pointWrapperType, point_1.Point.NONE);
    };
    PointsWrapper.addPointWrapper = function (builder, pointWrapperOffset) {
        builder.addFieldOffset(1, pointWrapperOffset, 0);
    };
    PointsWrapper.endPointsWrapper = function (builder) {
        var offset = builder.endObject();
        return offset;
    };
    PointsWrapper.createPointsWrapper = function (builder, pointWrapperType, pointWrapperOffset) {
        PointsWrapper.startPointsWrapper(builder);
        PointsWrapper.addPointWrapperType(builder, pointWrapperType);
        PointsWrapper.addPointWrapper(builder, pointWrapperOffset);
        return PointsWrapper.endPointsWrapper(builder);
    };
    PointsWrapper.prototype.serialize = function () {
        return this.bb.bytes();
    };
    PointsWrapper.deserialize = function (buffer) {
        return PointsWrapper.getRootAsPointsWrapper(new flatbuffers.ByteBuffer(buffer));
    };
    return PointsWrapper;
}());
exports.PointsWrapper = PointsWrapper;
//# sourceMappingURL=points-wrapper.js.map