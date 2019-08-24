#!/bin/bash
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

nohup geth --datadir=$ETH_DATA --nodiscover -verbosity 5 --port $1 --rpcport $2 --gasprice 0 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") --mine --minerthreads 8 > $ETH_DATA/../eth_log 2>&1 &
echo host is mining
sleep 1

for com in `cat $ETH_HOME/addPeer.txt`; do
  echo calling $com
  geth --exec $com attach ipc:$ETH_DATA/geth.ipc
done