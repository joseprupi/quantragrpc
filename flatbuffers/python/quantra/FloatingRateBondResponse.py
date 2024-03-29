# automatically generated by the FlatBuffers compiler, do not modify

# namespace: quantra

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class FloatingRateBondResponse(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = FloatingRateBondResponse()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsFloatingRateBondResponse(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # FloatingRateBondResponse
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # FloatingRateBondResponse
    def Npv(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def CleanPrice(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def DirtyPrice(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def AccruedAmount(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def Yield_(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(12))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def AccruedDays(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(14))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def MacaulayDuration(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(16))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def ModifiedDuration(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(18))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def Convexity(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(20))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def Bps(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(22))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float64Flags, o + self._tab.Pos)
        return 0.0

    # FloatingRateBondResponse
    def Flows(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(24))
        if o != 0:
            x = self._tab.Vector(o)
            x += flatbuffers.number_types.UOffsetTFlags.py_type(j) * 4
            x = self._tab.Indirect(x)
            from quantra.FlowsWrapper import FlowsWrapper
            obj = FlowsWrapper()
            obj.Init(self._tab.Bytes, x)
            return obj
        return None

    # FloatingRateBondResponse
    def FlowsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(24))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

    # FloatingRateBondResponse
    def FlowsIsNone(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(24))
        return o == 0

def Start(builder): builder.StartObject(11)
def FloatingRateBondResponseStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)
def AddNpv(builder, npv): builder.PrependFloat64Slot(0, npv, 0.0)
def FloatingRateBondResponseAddNpv(builder, npv):
    """This method is deprecated. Please switch to AddNpv."""
    return AddNpv(builder, npv)
def AddCleanPrice(builder, cleanPrice): builder.PrependFloat64Slot(1, cleanPrice, 0.0)
def FloatingRateBondResponseAddCleanPrice(builder, cleanPrice):
    """This method is deprecated. Please switch to AddCleanPrice."""
    return AddCleanPrice(builder, cleanPrice)
def AddDirtyPrice(builder, dirtyPrice): builder.PrependFloat64Slot(2, dirtyPrice, 0.0)
def FloatingRateBondResponseAddDirtyPrice(builder, dirtyPrice):
    """This method is deprecated. Please switch to AddDirtyPrice."""
    return AddDirtyPrice(builder, dirtyPrice)
def AddAccruedAmount(builder, accruedAmount): builder.PrependFloat64Slot(3, accruedAmount, 0.0)
def FloatingRateBondResponseAddAccruedAmount(builder, accruedAmount):
    """This method is deprecated. Please switch to AddAccruedAmount."""
    return AddAccruedAmount(builder, accruedAmount)
def AddYield_(builder, yield_): builder.PrependFloat64Slot(4, yield_, 0.0)
def FloatingRateBondResponseAddYield_(builder, yield_):
    """This method is deprecated. Please switch to AddYield_."""
    return AddYield_(builder, yield_)
def AddAccruedDays(builder, accruedDays): builder.PrependFloat64Slot(5, accruedDays, 0.0)
def FloatingRateBondResponseAddAccruedDays(builder, accruedDays):
    """This method is deprecated. Please switch to AddAccruedDays."""
    return AddAccruedDays(builder, accruedDays)
def AddMacaulayDuration(builder, macaulayDuration): builder.PrependFloat64Slot(6, macaulayDuration, 0.0)
def FloatingRateBondResponseAddMacaulayDuration(builder, macaulayDuration):
    """This method is deprecated. Please switch to AddMacaulayDuration."""
    return AddMacaulayDuration(builder, macaulayDuration)
def AddModifiedDuration(builder, modifiedDuration): builder.PrependFloat64Slot(7, modifiedDuration, 0.0)
def FloatingRateBondResponseAddModifiedDuration(builder, modifiedDuration):
    """This method is deprecated. Please switch to AddModifiedDuration."""
    return AddModifiedDuration(builder, modifiedDuration)
def AddConvexity(builder, convexity): builder.PrependFloat64Slot(8, convexity, 0.0)
def FloatingRateBondResponseAddConvexity(builder, convexity):
    """This method is deprecated. Please switch to AddConvexity."""
    return AddConvexity(builder, convexity)
def AddBps(builder, bps): builder.PrependFloat64Slot(9, bps, 0.0)
def FloatingRateBondResponseAddBps(builder, bps):
    """This method is deprecated. Please switch to AddBps."""
    return AddBps(builder, bps)
def AddFlows(builder, flows): builder.PrependUOffsetTRelativeSlot(10, flatbuffers.number_types.UOffsetTFlags.py_type(flows), 0)
def FloatingRateBondResponseAddFlows(builder, flows):
    """This method is deprecated. Please switch to AddFlows."""
    return AddFlows(builder, flows)
def StartFlowsVector(builder, numElems): return builder.StartVector(4, numElems, 4)
def FloatingRateBondResponseStartFlowsVector(builder, numElems):
    """This method is deprecated. Please switch to Start."""
    return StartFlowsVector(builder, numElems)
def End(builder): return builder.EndObject()
def FloatingRateBondResponseEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)