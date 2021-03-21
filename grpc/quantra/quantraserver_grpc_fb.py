# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!

import grpc

class QuantraServerStub(object):
  """ Interface exported by the server. """  
  
  def __init__(self, channel):
    """ Constructor. 
    
    Args: 
    channel: A grpc.Channel. 
    """
    
    self.PriceFixedRateBond = channel.unary_unary(
      "/quantra.QuantraServer/PriceFixedRateBond"
      )
    

class QuantraServerServicer(object):
  """ Interface exported by the server. """  
  
  def PriceFixedRateBond(self, request, context):
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')
  
  

def add_QuantraServerServicer_to_server(servicer, server):
  rpc_method_handlers = {
    'PriceFixedRateBond': grpc.unary_unary_rpc_method_handler(
      servicer.PriceFixedRateBond
    ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
    'quantra.QuantraServer', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))

