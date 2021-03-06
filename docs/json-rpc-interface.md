<!-- SPDX-License-Identifier: (GPL-3.0-only OR CC-BY-4.0) -->

# JSON-RPC Interface Compatibility 

| Method                                  |       Status        | Comments                                                                      |
|:--------------------------------------- |:-------------------:|:----------------------------------------------------------------------------- |
| web3_clientVersion                      |      Supported      |                                                                               |
| web3_sha3                               |      Supported      |                                                                               |
| net_version                             |      Supported      | Returns ChainID from config.json.                                             |
| net_listening                           |      Supported      |                                                                               |
| net_peerCount                           | Partially supported | Always returns 0                                                              |
| eth_protocolVersion                     |      Supported      |                                                                               |
| eth_syncing                             |      Supported      |                                                                               |
| eth_coinbase                            |      Supported      | Returns sChainOwner address from config.json (it is used as coinbase address) |
| eth_mining                              | Partially supported | There is no mining for SKALE s-chains, always returns false                   |
| eth_hashrate                            | Partially supported | There is no hashrate for SKALE s-chains, always returns 0                     |
| eth_gasPrice                            |      Supported      | Gas price is dynamically adjusted from 1000 wei and above as load grows       |
| eth_accounts                            |      Supported      |                                                                               |
| eth_blockNumber                         |      Supported      |                                                                               |
| eth_getBalance                          | Partially supported | Second parameter is ignored and always set to "latest"                        |
| eth_getStorageAt                        | Partially supported | Third parameter is ignored and always set to "latest"                         |
| eth_getTransactionCount                 | Partially supported | Second parameter is ignored and always set to "latest"                        |
| eth_getBlockTransactionCountByHash      |      Supported      |                                                                               |
| eth_getBlockTransactionCountByNumber    |      Supported      |                                                                               |
| eth_getUncleCountByBlockHash            |      Supported      | There are no uncles in SKALE s-chains                                         |
| eth_getUncleCountByBlockNumber          |      Supported      | There are no uncles in SKALE s-chains                                         |
| eth_getCode                             | Partially supported | Second parameter is ignored and always set to "latest"                        |
| eth_sign                                |    Not supported    |                                                                               |
| eth_sendTransaction                     |      Supported      |                                                                               |
| eth_sendRawTransaction                  |      Supported      |                                                                               |
| eth_call                                | Partially supported | Second parameter is ignored and always set to "latest"                        |
| eth_estimateGas                         |      Supported      | But does not use binary search                                                |
| eth_getBlockByHash                      |      Supported      | Old blocks are "rotated out"                                                  |
| eth_getBlockByNumber                    |      Supported      | Raises "block not found" error if block is "rotated out"                      |
| eth_getTransactionByHash                |      Supported      |                                                                               |
| eth_getTransactionByBlockHashAndIndex   |      Supported      |                                                                               |
| eth_getTransactionByBlockNumberAndIndex |      Supported      |                                                                               |
| eth_getTransactionReceipt               |      Supported      |                                                                               |
| eth_getUncleByBlockHashAndIndex         |      Supported      | There are no uncles in SKALE s-chains                                         |
| eth_getUncleByBlockNumberAndIndex       |      Supported      | There are no uncles in SKALE s-chains                                         |
| eth_getCompilers                        |    Not supported    |                                                                               |
| eth_compileSolidity                     |    Not supported    |                                                                               |
| eth_compileLLL                          |    Not supported    |                                                                               |
| eth_compileSerpent                      |    Not supported    |                                                                               |
| eth_newFilter                           | Partially supported | Ignores logs that originated from blocks that were "rotated out"              |
| eth_newBlockFilter                      |      Supported      |                                                                               |
| eth_newPendingTransactionFilter         |      Supported      |                                                                               |
| eth_uninstallFilter                     |      Supported      |                                                                               |
| eth_getFilterChanges                    |      Supported      |                                                                               |
| eth_getFilterLogs                       |      Supported      |                                                                               |
| eth_getLogs                             | Partially supported | Ignores logs that originated from blocks that were "rotated out"              |
| eth_getWork                             |      Supported      |                                                                               |
| eth_submitWork                          |    Not supported    |                                                                               |
| eth_submitHashrate                      |      Supported      |                                                                               |
| eth_getProof                            |    Not supported    |                                                                               |
| db_putString                            |    Not supported    |                                                                               |
| db_getString                            |    Not supported    |                                                                               |
| db_putHex                               |    Not supported    |                                                                               |
| db_getHex                               |    Not supported    |                                                                               |
| shh_version                             |    Not supported    |                                                                               |
| shh_post                                |    Not supported    |                                                                               |
| shh_newIdentity                         |    Not supported    |                                                                               |
| shh_hasIdentity                         |    Not supported    |                                                                               |
| shh_newGroup                            |    Not supported    |                                                                               |
| shh_addToGroup                          |    Not supported    |                                                                               |
| shh_newFilter                           |    Not supported    |                                                                               |
| shh_uninstallFilter                     |    Not supported    |                                                                               |
| shh_getFilterChanges                    |    Not supported    |                                                                               |
| shh_getMessages                         |    Not supported    |                                                                               |
