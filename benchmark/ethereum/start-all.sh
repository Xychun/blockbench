#!/bin/bash
#nodes
echo script start - start-all.sh
cd `dirname ${BASH_SOURCE-$0}`
. env.sh

rm -rf addPeer.txt
./gather.sh $1
sleep 3
i=0
for host in `cat $HOSTS`; do
  if [[ $i -lt $1 ]]; then
    echo sharing peer list with $host
    scp -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no addPeer.txt $USER@$host:$ETH_HOME/
    echo start mining on node $host
    ssh -i ~/.ssh/JDev.pem -oStrictHostKeyChecking=no $USER@$host $ETH_HOME/start-mining.sh
    echo done node $host
  fi
  let i=$i+1
done
echo script end - start-all.sh