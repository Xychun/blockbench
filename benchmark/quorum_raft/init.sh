#!/bin/bash
#args: number_of_nodes
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

echo "init.sh"
sudo mkdir -p $QUO_DATA/{keystore,geth}

let i=$1+1
echo "keys/key$i"
sudo cp keys/key$i $QUO_DATA/keystore
sudo cp raft/static-nodes$2.json $QUO_DATA/static-nodes.json
sudo cp raft/nodekey$i $QUO_DATA/geth/nodekey
${QUORUM} --datadir=$QUO_DATA init $QUO_HOME/genesis_quorum.json
