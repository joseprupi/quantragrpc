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
exports.FRAHelper = void 0;
var flatbuffers = __importStar(require("flatbuffers"));
var business_day_convention_1 = require("../quantra/enums/business-day-convention");
var calendar_1 = require("../quantra/enums/calendar");
var day_counter_1 = require("../quantra/enums/day-counter");
var FRAHelper = /** @class */ (function () {
    function FRAHelper() {
        this.bb = null;
        this.bb_pos = 0;
    }
    FRAHelper.prototype.__init = function (i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    };
    FRAHelper.getRootAsFRAHelper = function (bb, obj) {
        return (obj || new FRAHelper()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    FRAHelper.getSizePrefixedRootAsFRAHelper = function (bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new FRAHelper()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    };
    FRAHelper.prototype.rate = function () {
        var offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? this.bb.readFloat32(this.bb_pos + offset) : 0.0;
    };
    FRAHelper.prototype.monthsToStart = function () {
        var offset = this.bb.__offset(this.bb_pos, 6);
        return offset ? this.bb.readInt32(this.bb_pos + offset) : 0;
    };
    FRAHelper.prototype.monthsToEnd = function () {
        var offset = this.bb.__offset(this.bb_pos, 8);
        return offset ? this.bb.readInt32(this.bb_pos + offset) : 0;
    };
    FRAHelper.prototype.fixingDays = function () {
        var offset = this.bb.__offset(this.bb_pos, 10);
        return offset ? this.bb.readInt32(this.bb_pos + offset) : 0;
    };
    FRAHelper.prototype.calendar = function () {
        var offset = this.bb.__offset(this.bb_pos, 12);
        return offset ? this.bb.readInt8(this.bb_pos + offset) : calendar_1.Calendar.Argentina;
    };
    FRAHelper.prototype.businessDayConvention = function () {
        var offset = this.bb.__offset(this.bb_pos, 14);
        return offset ? this.bb.readInt8(this.bb_pos + offset) : business_day_convention_1.BusinessDayConvention.Following;
    };
    FRAHelper.prototype.dayCounter = function () {
        var offset = this.bb.__offset(this.bb_pos, 16);
        return offset ? this.bb.readInt8(this.bb_pos + offset) : day_counter_1.DayCounter.Actual360;
    };
    FRAHelper.startFRAHelper = function (builder) {
        builder.startObject(7);
    };
    FRAHelper.addRate = function (builder, rate) {
        builder.addFieldFloat32(0, rate, 0.0);
    };
    FRAHelper.addMonthsToStart = function (builder, monthsToStart) {
        builder.addFieldInt32(1, monthsToStart, 0);
    };
    FRAHelper.addMonthsToEnd = function (builder, monthsToEnd) {
        builder.addFieldInt32(2, monthsToEnd, 0);
    };
    FRAHelper.addFixingDays = function (builder, fixingDays) {
        builder.addFieldInt32(3, fixingDays, 0);
    };
    FRAHelper.addCalendar = function (builder, calendar) {
        builder.addFieldInt8(4, calendar, calendar_1.Calendar.Argentina);
    };
    FRAHelper.addBusinessDayConvention = function (builder, businessDayConvention) {
        builder.addFieldInt8(5, businessDayConvention, business_day_convention_1.BusinessDayConvention.Following);
    };
    FRAHelper.addDayCounter = function (builder, dayCounter) {
        builder.addFieldInt8(6, dayCounter, day_counter_1.DayCounter.Actual360);
    };
    FRAHelper.endFRAHelper = function (builder) {
        var offset = builder.endObject();
        return offset;
    };
    FRAHelper.createFRAHelper = function (builder, rate, monthsToStart, monthsToEnd, fixingDays, calendar, businessDayConvention, dayCounter) {
        FRAHelper.startFRAHelper(builder);
        FRAHelper.addRate(builder, rate);
        FRAHelper.addMonthsToStart(builder, monthsToStart);
        FRAHelper.addMonthsToEnd(builder, monthsToEnd);
        FRAHelper.addFixingDays(builder, fixingDays);
        FRAHelper.addCalendar(builder, calendar);
        FRAHelper.addBusinessDayConvention(builder, businessDayConvention);
        FRAHelper.addDayCounter(builder, dayCounter);
        return FRAHelper.endFRAHelper(builder);
    };
    return FRAHelper;
}());
exports.FRAHelper = FRAHelper;
//# sourceMappingURL=f-r-a-helper.js.map