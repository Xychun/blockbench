#!/bin/bash
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

#nohup geth --datadir=$ETH_DATA --nodiscover --rpc --rpcaddr 0.0.0.0 --rpcport $RPCPORT --rpccorsdomain "*" --gasprice 0 --maxpeers 32 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") --mine --minerthreads 8 > $ETH_DATA/../eth_log 2>&1 &
nohup geth --datadir=$ETH_DATA --nodiscover -verbosity 5 --port 30301 --rpcport 8101 --gasprice 0 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") --mine --minerthreads 8 > $ETH_DATA/../eth_log 2>&1 &
echo host is mining
sleep 1

for com in `cat $ETH_HOME/addPeer.txt`; do
  echo calling $com
  geth --exec $com attach ipc:$ETH_DATA/geth.ipc
done