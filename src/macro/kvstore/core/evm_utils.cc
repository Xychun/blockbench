#include "evm_utils.h"
#include <iostream>

namespace BBUtils {
namespace EVMUtils {

const std::string REQUEST_HEADERS = "application/json";
const std::string UNLOCK_ACCOUNT_PREFIX =
    "{\
  \"jsonrpc\": \"2.0\", \
  \"method\": \"personal_unlockAccount\", \
  \"params\": [\"";

const std::string UNLOCK_ACCOUNT_SUFFIX =
    "\",\"\",null], \
      \"id\": 1}";

const std::string SEND_TXN_PREFIX =
    "{\
  \"jsonrpc\": \"2.0\", \
  \"method\": \"eth_sendTransaction\", \
  \"params\": [{ \"gas\": \"0x100000\", \
                \"gasPrice\": \"0x0\", \
                \"from\": \"";

const std::string CALL_PREFIX =
    "{\
  \"jsonrpc\": \"2.0\", \
  \"method\": \"eth_call\", \
  \"params\": [{ \"gas\": \"0x100000\",\
                \"gasPrice\": \"0x0\", \
                \"from\": \"";

const std::string GET_TXN_PREFIX =
    "{\
  \"jsonrpc\": \"2.0\", \
  \"method\": \"eth_getTransactionByHash\", \
  \"params\": [\"";

const std::string MIDDLE_PART_1 = "\", \"to\": \"";
const std::string MIDDLE_PART_2 = "\", \"data\": \"";
const std::string SEND_TXN_SUFFIX = "\"}],\"id\":1}";
const std::string CALL_SUFFIX = "\"},\"latest\"],\"id\":1}";
const std::string GET_TXN_SUFFIX = "\"],\"id\":1}";

const std::string GET_BLOCK_BY_NUMBER_PREFIX =
    "{\"jsonrpc\":\"2.0\", \
      \"method\":\"eth_getBlockByNumber\", \
      \"params\":[\"";

const std::string GET_BLOCK_BY_NUMBER_SUFFIX =
    "\", false], \
      \"id\": 1}";

const std::string GET_BLOCK_BY_HASH_PREFIX =
    "{\"jsonrpc\":\"2.0\", \
      \"method\":\"eth_getBlockByHash\", \
      \"params\":[\"";

const std::string GET_BLOCK_BY_HASH_SUFFIX =
    "\", false], \
      \"id\": 1}";

const std::string GET_BLOCKNUMBER =
    "{\"jsonrpc\":\"2.0\", \
      \"method\":\"eth_blockNumber\", \
      \"params\":[], \
      \"id\": 1}";

const std::string GET_ACCOUNTS =
    "{\"jsonrpc\":\"2.0\",\"method\":\"eth_accounts\",\"params\":[],\"id\":1}";

const std::string DEPLOY_SMARTCONTRACT_PREFIX =
    " {\"jsonrpc\":\"2.0\",\
  \"method\":\"eth_sendTransaction\",\
  \"params\": [{ \"gas\": \"0x100000\",\
                \"gasPrice\": \"0x0\", \
               \"from\": \"";

const std::string DEPLOY_DONOTHING_SMARTCONTRACT_SUFFIX =
    "\", \"data\": "
    "\"0x60606040523415600b57fe5b5b60788061001a6000396000f30060606040526000357c"
    "0100000000000000000000000000000000000000000000000000000000900463ffffffff16"
    "8063448f30a314603a575bfe5b3415604157fe5b60476049565b005b5b5600a165627a7a72"
    "30582006401d873570c51618d5e2963a0048502e8f49f465e30cf2624369a1c7db3fa00029"
    "\"}],\"id\":1}";

const std::string DEPLOY_KV_SMARTCONTRACT_SUFFIX =
    "\", \"data\": "
    "\"0x6060604052610398806100126000396000f360606040526000357c0100000000000000"
    "00"
    "000000000000000000000000000000000000000090048063693ec85e14610047578063e942"
    "b5161461010e57610042565b610002565b34610002576100a0600480803590602001908201"
    "8035906020019191908080601f016020809104026020016040519081016040528093929190"
    "8181526020018383808284378201915050505050509090919050506101b0565b6040518080"
    "60200182810382528381815181526020019150805190602001908083838290600060046020"
    "84601f0104600302600f01f150905090810190601f16801561010057808203805160018360"
    "20036101000a031916815260200191505b509250505060405180910390f35b346100025761"
    "01ae6004808035906020019082018035906020019191908080601f01602080910402602001"
    "60405190810160405280939291908181526020018383808284378201915050505050509090"
    "91908035906020019082018035906020019191908080601f01602080910402602001604051"
    "90810160405280939291908181526020018383808284378201915050505050509090919050"
    "506102aa565b005b6020604051908101604052806000815260200150600060005082604051"
    "808280519060200190808383829060006004602084601f0104600302600f01f15090500191"
    "50509081526020016040518091039020600050805460018160011615610100020316600290"
    "0480601f016020809104026020016040519081016040528092919081815260200182805460"
    "0181600116156101000203166002900480156102995780601f1061026e5761010080835404"
    "0283529160200191610299565b820191906000526020600020905b81548152906001019060"
    "200180831161027c57829003601f168201915b505050505090506102a5565b919050565b80"
    "600060005083604051808280519060200190808383829060006004602084601f0104600302"
    "600f01f1509050019150509081526020016040518091039020600050908051906020019082"
    "8054600181600116156101000203166002900490600052602060002090601f016020900481"
    "019282601f1061033557805160ff1916838001178555610366565b82800160010185558215"
    "610366579182015b8281111561036557825182600050559160200191906001019061034756"
    "5b5b5090506103919190610373565b8082111561038d576000818150600090555060010161"
    "0373565b5090565b50505b505056\"}],\"id\":1}";

const std::string DEPLOY_SB_SMARTCONTRACT_SUFFIX =
    "\", \"data\": "
    "\"0x0190808383829060006004602084601f0104600302600f01f150905090810190601f16"
    "80"
    "156101005780820380516001836020036101000a031916815260200191505b509250505060"
    "405180910390f35b34610002576101ae600480803590602001908201803590602001919190"
    "8080601f016020809104026020016040519081016040528093929190818152602001838380"
    "82843782019150505050505090909190803590602001908201803590602001919190808060"
    "1f016020809104026020016040519081016040528093929190818152602001838380828437"
    "8201915050505050509090919050506102aa565b005b602060405190810160405280600081"
    "5260200150600060005082604051808280519060200190808383829060006004602084601f"
    "0104600302600f01f150905001915050908152602001604051809103902060005080546001"
    "81600116156101000203166002900480601f01602080910402602001604051908101604052"
    "80929190818152602001828054600181600116156101000203166002900480156102995780"
    "601f1061026e57610100808354040283529160200191610299565b82019190600052602060"
    "0020905b81548152906001019060200180831161027c57829003601f168201915b50505050"
    "5090506102a5565b919050565b602060405190810160405280600081526020015060206040"
    "51908101604052806000815260200150602060405190810160405280600081526020015083"
    "600060005086604051808280519060200190808383829060006004602084601f0104600302"
    "600f01f1509050019150509081526020016040518091039020600050908051906020019082"
    "8054600181600116156101000203166002900490600052602060002090601f016020900481"
    "019282601f1061037157805160ff19168380011785556103a2565b82800160010185558215"
    "6103a2579182015b828111156103a157825182600050559160200191906001019061038356"
    "5b5b5090506103cd91906103af565b808211156103c9576000818150600090555060010161"
    "03af565b5090565b50508492507f6100000000000000000000000000000000000000000000"
    "0000000000000000008360008151811015610002579060200101907effffffffffffffffff"
    "ffffffffffffffffffffffffffffffffffffffffffff1916908160001a9053508291506000"
    "60005085604051808280519060200190808383829060006004602084601f0104600302600f"
    "01f15090500191505090815260200160405180910390206000508054600181600116156101"
    "000203166002900480601f0160208091040260200160405190810160405280929190818152"
    "602001828054600181600116156101000203166002900480156105075780601f106104dc57"
    "610100808354040283529160200191610507565b820191906000526020600020905b815481"
    "5290600101906020018083116104ea57829003601f168201915b5050505050905083600060"
    "005083604051808280519060200190808383829060006004602084601f0104600302600f01"
    "f1509050019150509081526020016040518091039020600050908051906020019082805460"
    "0181600116156101000203166002900490600052602060002090601f016020900481019282"
    "601f1061059957805160ff19168380011785556105ca565b828001600101855582156105ca"
    "579182015b828111156105c95782518260005055916020019190600101906105ab565b5b50"
    "90506105f591906105d7565b808211156105f157600081815060009055506001016105d756"
    "5b5090565b50507f6200000000000000000000000000000000000000000000000000000000"
    "0000008360018151811015610002579060200101907effffffffffffffffffffffffffffff"
    "ffffffffffffffffffffffffffffffff1916908160001a9053508291508150600060005082"
    "604051808280519060200190808383829060006004602084601f0104600302600f01f15090"
    "50019150509081526020016040518091039020600050805460018160011615610100020316"
    "6002900480601f016020809104026020016040519081016040528092919081815260200182"
    "80546001816001161561010002031660029004801561072e5780601f106107035761010080"
    "835404028352916020019161072e565b820191906000526020600020905b81548152906001"
    "019060200180831161071157829003601f168201915b505050505090508050836000600050"
    "83604051808280519060200190808383829060006004602084601f0104600302600f01f150"
    "90500191505090815260200160405180910390206000509080519060200190828054600181"
    "600116156101000203166002900490600052602060002090601f016020900481019282601f"
    "106107c257805160ff19168380011785556107f3565b828001600101855582156107f35791"
    "82015b828111156107f25782518260005055916020019190600101906107d4565b5b509050"
    "61081e9190610800565b8082111561081a5760008181506000905550600101610800565b50"
    "90565b50507f63000000000000000000000000000000000000000000000000000000000000"
    "008360018151811015610002579060200101907effffffffffffffffffffffffffffffffff"
    "ffffffffffffffffffffffffffff1916908160001a90535082915081506000600050826040"
    "51808280519060200190808383829060006004602084601f0104600302600f01f150905001"
    "91505090815260200160405180910390206000508054600181600116156101000203166002"
    "900480601f0160208091040260200160405190810160405280929190818152602001828054"
    "600181600116156101000203166002900480156109575780601f1061092c57610100808354"
    "040283529160200191610957565b820191906000526020600020905b815481529060010190"
    "60200180831161093a57829003601f168201915b5050505050905080508360006000508360"
    "4051808280519060200190808383829060006004602084601f0104600302600f01f1509050"
    "01915050908152602001604051809103902060005090805190602001908280546001816001"
    "16156101000203166002900490600052602060002090601f016020900481019282601f1061"
    "09eb57805160ff1916838001178555610a1c565b82800160010185558215610a1c57918201"
    "5b82811115610a1b5782518260005055916020019190600101906109fd565b5b509050610a"
    "479190610a29565b80821115610a435760008181506000905550600101610a29565b509056"
    "5b50507f640000000000000000000000000000000000000000000000000000000000000083"
    "60018151811015610002579060200101907effffffffffffffffffffffffffffffffffffff"
    "ffffffffffffffffffffffff1916908160001a905350829150815060006000508260405180"
    "8280519060200190808383829060006004602084601f0104600302600f01f1509050019150"
    "50908152602001604051809103902060005080546001816001161561010002031660029004"
    "80601f01602080910402602001604051908101604052809291908181526020018280546001"
    "8160011615610100020316600290048015610b805780601f10610b55576101008083540402"
    "83529160200191610b80565b820191906000526020600020905b8154815290600101906020"
    "01808311610b6357829003601f168201915b50505050509050805083600060005083604051"
    "808280519060200190808383829060006004602084601f0104600302600f01f15090500191"
    "50509081526020016040518091039020600050908051906020019082805460018160011615"
    "6101000203166002900490600052602060002090601f016020900481019282601f10610c14"
    "57805160ff1916838001178555610c45565b82800160010185558215610c45579182015b82"
    "811115610c44578251826000505591602001919060010190610c26565b5b509050610c7091"
    "90610c52565b808211\"}],\"id\":1}";

const std::string GET_SMART_CONTRACT_ADDRESS_PREFIX =
    "{\"jsonrpc\":\"2.0\",\
       \"method\":\"eth_getTransactionReceipt\",\
       \"params\":[\"";

const std::string GET_SMART_CONTRACT_ADDRESS_SUFFIX = "\"],\"id\":1}";

const std::string DONOTHING_METHOD_SIG = "0x448f30a3";
const std::string SET_METHOD_SIG =
    "0xe942b51600000000000000000000000000000000000000000000000000000000000000"
    "40";
const std::string GET_METHOD_SIG =
    "0x693ec85e00000000000000000000000000000000000000000000000000000000000000"
    "20";

std::string encode_set(const std::string &key, const std::string &value) {
  std::string ret = SET_METHOD_SIG;
  std::string argument_1 = encode_string(key);
  ret += left_padding_string(encode_hex(argument_1.length()));
  ret += argument_1 + encode_string(value);
  return ret;
}

std::string encode_get(const std::string &key) {
  return GET_METHOD_SIG + encode_string(key);
}

std::string compose_donothing_tx_data(const std::string &from_address,
                                      const std::string &to_address) {
  return SEND_TXN_PREFIX + from_address + MIDDLE_PART_1 + to_address +
         MIDDLE_PART_2 + DONOTHING_METHOD_SIG + SEND_TXN_SUFFIX;
}

std::string compose_read(const std::string &key,
                         const std::string &from_address,
                         const std::string &to_address) {
  return CALL_PREFIX + from_address + MIDDLE_PART_1 + to_address +
         MIDDLE_PART_2 + encode_get(key) + CALL_SUFFIX;
}

std::string compose_write(const std::string &key, const std::string &val,
                          const std::string &from_address,
                          const std::string &to_address) {
  return SEND_TXN_PREFIX + from_address + MIDDLE_PART_1 + to_address +
         MIDDLE_PART_2 + encode_set(key, val) + SEND_TXN_SUFFIX;
}

std::string compose_get_transaction(const std::string &txn_hash) {
  return GET_TXN_PREFIX + txn_hash + GET_TXN_SUFFIX;
}

unsigned int get_tip_block_number(const std::string &endpoint) {
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS, GET_BLOCKNUMBER);
  if (r.find("Failed") != std::string::npos) 
    return -1;

  return decode_hex(get_json_field(
      send_jsonrpc_request(endpoint, REQUEST_HEADERS, GET_BLOCKNUMBER),
      "result"));
}

unsigned int get_txn_block_number(const std::string &endpoint,
                                  const std::string &txn_hash) {
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                                compose_get_transaction(txn_hash));
  // in case this transaction haven't been mined, return MAXIMUM uint.
  if (r.find("\"blockNumber\":null") != std::string::npos) return -1;
  return decode_hex(get_json_field(r, "blockNumber"));
}

std::string get_from_address(const std::string &endpoint) {
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS, GET_ACCOUNTS);
  return get_json_field(r, "result");
}

std::vector<std::string> poll_txs_by_block_hash(const std::string &endpoint,
                                                std::string block_hash) {
  std::string request =
      GET_BLOCK_BY_HASH_PREFIX + block_hash + GET_BLOCK_BY_HASH_SUFFIX;
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS, request);
  auto ret = get_list_field(r, "transactions");
  return ret;
}

std::vector<std::string> poll_txs_by_block_number(const std::string &endpoint,
                                                  int block_number) {
  std::string request = GET_BLOCK_BY_NUMBER_PREFIX +
                        ("0x" + encode_hex(block_number)) +
                        GET_BLOCK_BY_NUMBER_SUFFIX;

  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS, request);

  std::vector<std::string> ret = get_list_field(r, "transactions");
  std::vector<std::string> uncles = get_list_field(r, "uncles");
  for (std::string uncle : uncles) {
    std::vector<std::string> uncletxs = poll_txs_by_block_hash(endpoint, uncle);
    for (std::string tx : uncletxs) ret.push_back(tx);
  }
  return ret;
}

void unlock_address(const std::string &endpoint, const std::string &address) {
  send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                       UNLOCK_ACCOUNT_PREFIX + address + UNLOCK_ACCOUNT_SUFFIX);
}

std::string deploy_smart_contract(const std::string &endpoint,
                                  const std::string &from_address,
                                  SmartContractType type) {
  std::string txn_data = DEPLOY_SMARTCONTRACT_PREFIX + from_address;
  switch (type) {
    case SmartContractType::KVStore:
      txn_data += DEPLOY_KV_SMARTCONTRACT_SUFFIX;
      break;
    case SmartContractType::SmallBank:
      txn_data += DEPLOY_SB_SMARTCONTRACT_SUFFIX;
      break;
    case SmartContractType::DoNothing:
      txn_data += DEPLOY_DONOTHING_SMARTCONTRACT_SUFFIX;
      break;
  }
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS, txn_data);
  std::cout << "txn_data: " << txn_data << std::endl;
  std::cout << "endpoint: " << endpoint << " from address: " << from_address << std::endl;
  std::cout << "r: " << r << std::endl;
  return get_json_field(r, "result");
}

std::string lookup_smart_contract_address_or_die(const std::string &endpoint,
                                                 const std::string &receipt) {
  
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                                GET_SMART_CONTRACT_ADDRESS_PREFIX + receipt +
                                    GET_SMART_CONTRACT_ADDRESS_SUFFIX);

  std::cout << "endpoint: " << endpoint << " receipt: " << receipt << " r: " << r << std::endl;
  assert(r.find("\"result\":null") == std::string::npos);
  return get_json_field(r, "contractAddress");
}

std::string submit_do_nothing_txn(const std::string &endpoint,
                                  const std::string &from_address,
                                  const std::string &to_address) {
  auto r =
      send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                           compose_donothing_tx_data(from_address, to_address));
  return get_json_field(r, "result");
}

std::string submit_set_txn(const std::string &endpoint, const std::string &key,
                           const std::string &val,
                           const std::string &from_address,
                           const std::string &to_address) {
  auto r =
      send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                           compose_write(key, val, from_address, to_address));
  return get_json_field(r, "result");
}

std::string submit_get_txn(const std::string &endpoint, const std::string &key,
                           const std::string &from_address,
                           const std::string &to_address) {
  auto r = send_jsonrpc_request(endpoint, REQUEST_HEADERS,
                                compose_read(key, from_address, to_address));
  return get_json_field(r, "result");
}

}  // EVMUtils
}  // BBUtils
