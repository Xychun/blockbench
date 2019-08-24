#!/bin/bash
#num_clients num_nodes threads tx_rate [-drop]
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

clients=$1
servers=$2

let i=0
let IDX=$(( clients / 2 )) #$1 is #clients, we take only half of them 
echo script start - start-multi-clients.sh
for client in `cat $CLIENTS`; do
  if [[ $i -lt $IDX ]]; then
    echo starting client $client  threads=$3 clientNo=$i nservers=$2 txrate=$4
    ssh -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no $client $ETH_HOME/start-clients.sh $3 $i $2 $4
  fi
  let i=$i+1
done

if [[ $5 == "-drop" ]]; then
  let M=$2*10+240
  let SR=$M-150
  sleep 250 
  let idx=$2-4
  let i=0
  for server in `cat $HOSTS`; do
    if [[ $i -ge $idx ]]; then
      ssh -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no $server killall -KILL geth peer java 
      echo "Dropped "$server
    fi
    let i=$i+1
  done
  sleep $SR
  for client in `cat $CLIENTS`; do
    echo $client index $i
    ssh -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no $client 'killall -KILL driver' 
    let i=$i+1
  done
else
  let M=$(( servers * 10 + 240 ))
  echo "sleeping $M seconds before killing drivers (clients)"
  sleep $M
  for client in `cat $CLIENTS`; do
    echo killing client $client
    ssh -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no $client 'killall -KILL driver' 
    let i=$i+1
  done
fi
