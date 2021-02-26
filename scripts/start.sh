#!/bin/bash

trap "kill 0" EXIT

n_servers=$1
  
start_port="50055"
end_port=$[$start_port+$n_servers]

while [ $start_port -lt $end_port ]
do
/root/quantra/build/server/async_server $start_port &
start_port=$[$start_port+1]
done

wait