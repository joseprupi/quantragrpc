# automatically generated by the FlatBuffers compiler, do not modify

# namespace: quantra

import flatbuffers
from flatbuffers.compat import import_numpy
np = import_numpy()

class Error(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAs(cls, buf, offset=0):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Error()
        x.Init(buf, n + offset)
        return x

    @classmethod
    def GetRootAsError(cls, buf, offset=0):
        """This method is deprecated. Please switch to GetRootAs."""
        return cls.GetRootAs(buf, offset)
    # Error
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Error
    def ErrorMessage(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.String(o + self._tab.Pos)
        return None

def Start(builder): builder.StartObject(1)
def ErrorStart(builder):
    """This method is deprecated. Please switch to Start."""
    return Start(builder)
def AddErrorMessage(builder, errorMessage): builder.PrependUOffsetTRelativeSlot(0, flatbuffers.number_types.UOffsetTFlags.py_type(errorMessage), 0)
def ErrorAddErrorMessage(builder, errorMessage):
    """This method is deprecated. Please switch to AddErrorMessage."""
    return AddErrorMessage(builder, errorMessage)
def End(builder): return builder.EndObject()
def ErrorEnd(builder):
    """This method is deprecated. Please switch to End."""
    return End(builder)