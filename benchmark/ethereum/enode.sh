#!/bin/bash
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

ip_addr=$1
port=$2
echo Running: geth --datadir=$ETH_DATA --rpc --rpcaddr 0.0.0.0 --rpcport $RPCPORT --rpccorsdomain "*" --gasprice 0 --networkid 9119 --unlock 0 --password <(echo -n "${PWD}") js <(echo 'console.log(admin.nodeInfo.enode);') 2>/dev/null |grep enode | perl -pe "s/\[\:\:\]/$ip_addr:$port/g" | perl -pe "s/^/\"/; s/\s*$/\"/;"
geth --datadir=$ETH_DATA --rpc --rpcaddr 0.0.0.0 --rpcport $RPCPORT --rpccorsdomain "*" --gasprice 0 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") js <(echo 'console.log(admin.nodeInfo.enode);') 2>/dev/null | grep enode | sed -e "s/@127.0.0.1:30303/@$ip_addr:$port/"
#echo Running: geth --datadir=$ETH_DATA --gasprice 0 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") js <(echo 'console.log(admin.nodeInfo.enode);') 2>/dev/null | grep enode | sed -e "s/@127.0.0.1:30303/@$ip_addr/"
#geth --datadir=$ETH_DATA --gasprice 0 --networkid 9119 --unlock 0 --allow-insecure-unlock --password <(echo -n "${PWD}") js <(echo 'console.log(admin.nodeInfo.enode);') 2>/dev/null | grep enode | sed -e "s/@127.0.0.1:30303/@$ip_addr/"