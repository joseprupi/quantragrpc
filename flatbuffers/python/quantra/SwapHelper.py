# automatically generated by the FlatBuffers compiler, do not modify

# namespace: quantra

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class SwapHelper(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = SwapHelper()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsSwapHelper(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # SwapHelper
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # SwapHelper
    def Rate(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # SwapHelper
    def TenorTimeUnit(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def TenorNumber(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def Calendar(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def SwFixedLegFrequency(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def SwFixedLegConvention(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def SwFixedLegDayCounter(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def SwFloatingLegIndex(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # SwapHelper
    def Spread(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(20))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # SwapHelper
    def FwdStartDays(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(22))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

def Start(builder): builder.StartObject(10)
def SwapHelperStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)
def AddRate(builder, rate): builder.PrependFloat64Slot(0, rate, 0.0)
def SwapHelperAddRate(builder, rate):
    """This method is deprecated. Please switch to AddRate."""
    return AddRate(builder, rate)
def AddTenorTimeUnit(builder, tenorTimeUnit): builder.PrependInt8Slot(1, tenorTimeUnit, 0)
def SwapHelperAddTenorTimeUnit(builder, tenorTimeUnit):
    """This method is deprecated. Please switch to AddTenorTimeUnit."""
    return AddTenorTimeUnit(builder, tenorTimeUnit)
def AddTenorNumber(builder, tenorNumber): builder.PrependInt32Slot(2, tenorNumber, 0)
def SwapHelperAddTenorNumber(builder, tenorNumber):
    """This method is deprecated. Please switch to AddTenorNumber."""
    return AddTenorNumber(builder, tenorNumber)
def AddCalendar(builder, calendar): builder.PrependInt8Slot(3, calendar, 0)
def SwapHelperAddCalendar(builder, calendar):
    """This method is deprecated. Please switch to AddCalendar."""
    return AddCalendar(builder, calendar)
def AddSwFixedLegFrequency(builder, swFixedLegFrequency): builder.PrependInt8Slot(4, swFixedLegFrequency, 0)
def SwapHelperAddSwFixedLegFrequency(builder, swFixedLegFrequency):
    """This method is deprecated. Please switch to AddSwFixedLegFrequency."""
    return AddSwFixedLegFrequency(builder, swFixedLegFrequency)
def AddSwFixedLegConvention(builder, swFixedLegConvention): builder.PrependInt8Slot(5, swFixedLegConvention, 0)
def SwapHelperAddSwFixedLegConvention(builder, swFixedLegConvention):
    """This method is deprecated. Please switch to AddSwFixedLegConvention."""
    return AddSwFixedLegConvention(builder, swFixedLegConvention)
def AddSwFixedLegDayCounter(builder, swFixedLegDayCounter): builder.PrependInt8Slot(6, swFixedLegDayCounter, 0)
def SwapHelperAddSwFixedLegDayCounter(builder, swFixedLegDayCounter):
    """This method is deprecated. Please switch to AddSwFixedLegDayCounter."""
    return AddSwFixedLegDayCounter(builder, swFixedLegDayCounter)
def AddSwFloatingLegIndex(builder, swFloatingLegIndex): builder.PrependInt8Slot(7, swFloatingLegIndex, 0)
def SwapHelperAddSwFloatingLegIndex(builder, swFloatingLegIndex):
    """This method is deprecated. Please switch to AddSwFloatingLegIndex."""
    return AddSwFloatingLegIndex(builder, swFloatingLegIndex)
def AddSpread(builder, spread): builder.PrependFloat64Slot(8, spread, 0.0)
def SwapHelperAddSpread(builder, spread):
    """This method is deprecated. Please switch to AddSpread."""
    return AddSpread(builder, spread)
def AddFwdStartDays(builder, fwdStartDays): builder.PrependInt32Slot(9, fwdStartDays, 0)
def SwapHelperAddFwdStartDays(builder, fwdStartDays):
    """This method is deprecated. Please switch to AddFwdStartDays."""
    return AddFwdStartDays(builder, fwdStartDays)
def End(builder): return builder.EndObject()
def SwapHelperEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)