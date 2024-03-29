# automatically generated by the FlatBuffers compiler, do not modify

# namespace: quantra

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class DepositHelper(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = DepositHelper()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsDepositHelper(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # DepositHelper
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # DepositHelper
    def Rate(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # DepositHelper
    def TenorTimeUnit(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # DepositHelper
    def TenorNumber(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # DepositHelper
    def FixingDays(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # DepositHelper
    def Calendar(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # DepositHelper
    def BusinessDayConvention(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # DepositHelper
    def DayCounter(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

def Start(builder): builder.StartObject(7)
def DepositHelperStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)
def AddRate(builder, rate): builder.PrependFloat64Slot(0, rate, 0.0)
def DepositHelperAddRate(builder, rate):
    """This method is deprecated. Please switch to AddRate."""
    return AddRate(builder, rate)
def AddTenorTimeUnit(builder, tenorTimeUnit): builder.PrependInt8Slot(1, tenorTimeUnit, 0)
def DepositHelperAddTenorTimeUnit(builder, tenorTimeUnit):
    """This method is deprecated. Please switch to AddTenorTimeUnit."""
    return AddTenorTimeUnit(builder, tenorTimeUnit)
def AddTenorNumber(builder, tenorNumber): builder.PrependInt32Slot(2, tenorNumber, 0)
def DepositHelperAddTenorNumber(builder, tenorNumber):
    """This method is deprecated. Please switch to AddTenorNumber."""
    return AddTenorNumber(builder, tenorNumber)
def AddFixingDays(builder, fixingDays): builder.PrependInt32Slot(3, fixingDays, 0)
def DepositHelperAddFixingDays(builder, fixingDays):
    """This method is deprecated. Please switch to AddFixingDays."""
    return AddFixingDays(builder, fixingDays)
def AddCalendar(builder, calendar): builder.PrependInt8Slot(4, calendar, 0)
def DepositHelperAddCalendar(builder, calendar):
    """This method is deprecated. Please switch to AddCalendar."""
    return AddCalendar(builder, calendar)
def AddBusinessDayConvention(builder, businessDayConvention): builder.PrependInt8Slot(5, businessDayConvention, 0)
def DepositHelperAddBusinessDayConvention(builder, businessDayConvention):
    """This method is deprecated. Please switch to AddBusinessDayConvention."""
    return AddBusinessDayConvention(builder, businessDayConvention)
def AddDayCounter(builder, dayCounter): builder.PrependInt8Slot(6, dayCounter, 0)
def DepositHelperAddDayCounter(builder, dayCounter):
    """This method is deprecated. Please switch to AddDayCounter."""
    return AddDayCounter(builder, dayCounter)
def End(builder): return builder.EndObject()
def DepositHelperEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)