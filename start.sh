#!/bin/bash
cd /root/quantragrpc
.  ./scripts/config_vars.sh
printenv
trap 'pkill -P $$' SIGINT SIGTERM
./build/jsonserver/json_server localhost:50051 8001 &
/root/quantragrpc/build/server/sync_server &
sleep infinity

