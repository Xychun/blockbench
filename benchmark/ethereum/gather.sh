#!/bin/bash
#nnodes
echo script start - gather.sh
cd `dirname ${BASH_SOURCE-$0}`
. env.sh 

i=0
for host in `cat $HOSTS`; do
  if [[ $i -lt $1 ]]; then
    echo "adding peer to network, rpcport $RPCPORT"
    port=`expr $PORT_INIT + $i`
    echo "admin.addPeer("`ssh -i ~/.ssh/JDev.pem $USER@$host $ETH_HOME/enode.sh $host $port 2>/dev/null | grep enode`")" >> addPeer.txt
  fi
  let i=$i+1
  echo $i
done
echo script end - gather.sh