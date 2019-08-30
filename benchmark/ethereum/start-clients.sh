#!/bin/bash
# args: threads clientID num_servers tx_rate
echo script start - start-clients.sh

cd `dirname ${BASH_SOURCE-$0}`
. env.sh

TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
LOG_DIR=$LOG_DIR/exp_$3"_"servers_$1"_"threads_$4"_"rates"_"$TIMESTAMP
mkdir -p $LOG_DIR
i=0
echo "iterating over hosts for clientID=$2"
for host in `cat $HOSTS`; do
  cd $EXE_HOME
  #both ycsbc and smallbank use the same driver
  rpcport=`expr $RPCPORT_INIT + $i`
  echo "Starting driver for endpoint " $host:$rpcport
  nohup ./driver -db ethereum -threads $1 -P workloads/workloada.spec -endpoint $host:$rpcport -txrate $4 -wt 60 > $LOG_DIR/client_$2"_"$host 2>&1 &
  let i=i+1
done