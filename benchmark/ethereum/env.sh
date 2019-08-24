# folder that contains all benchmark scripts (this could be on a network share)
ETH_HOME=/home/ubuntu/blockbench/benchmark/ethereum
# file that contains ip addresses of servers that should be used for setting up the ethereum network
HOSTS=$ETH_HOME/hosts

# file that contains ip addresses of servers that should be used for running the benchmark clients
CLIENTS=$ETH_HOME/clients
# folder in which ethereum nodes should store the ethereum data
ETH_DATA=/home/$USER/eth
# folder in which benchmark clients should store their log files
LOG_DIR=$ETH_HOME/ycsb
# folder that contains the benchmark (client) executable (make sure that you have build the client) (this could be on a network share)
EXE_HOME=$ETH_HOME/../../src/macro/kvstore
# name/type of the benchmark
BENCHMARK=ycsb
# SSH user (with public key auth) to use to run the scripts on all machines
USER=ubuntu
# private key that should be used to create an account as ethereum coinbase
PRIVATEKEY=$ETH_HOME/privKey
# Password used for unlocking the above private key or for creating a new account as ethereum coinbase
PWD=""
# port used by clients and ethereum nodes
PORT_INIT=30001
# RPCport used by clients and ethereum nodes
RPCPORT_INIT=8001

##comment these out for smallbank
#EXE_HOME=$ETH_HOME/../../src/smallbank/ethereum/ycsb
#BENCHMARK=smallbank
