# PonyCoin [PONY]

## Overview

PonyCoin (PNY) is a global payment system where you can send to anywhere instantly. It has low transaction fees. There are no banks and no middleman.

## Stats

* Ticker: PNY
* Block Times: 2 Minutes
* POW Production 21,000,000 PNY
* POS Interest 33%/yr, decreasing 3% yearly
* Security
  * Algorithm: Scrypt
  * Fair launch POW blocks 10,800 (10,800 PNY)
  * Main POW blocks 10,801 - 30,239 (20,989,200 PNY)
  * POS bonus blocks (100x) 30,240 - 50,400
* Coinbase Maturity: 180 Blocks (6 hr)
* Stake Minimum COnfirmations: 240
* Difficulty Adjustment: DGW
* Min Transaction Fee: 0.0015 PONY
* Min Transaction: 0.01 PONY
* Peer-to-Peer Port: 14444
* RPC Port: 44441

## Mining

### Example: minerd

```./minerd -a scrypt -u ponycoinrpc -p PONYCOINRPCPASSWORD -o 127.0.0.1:44441 -t 1```

