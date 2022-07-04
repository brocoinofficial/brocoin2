// Copyright (c) 2010 Abhishek, Mohit Kumar
// Copyright (c) 2009-2019 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_NODE_COINSTATS_H
#define BROCOIN_NODE_COINSTATS_H

#include <amount.h>
#include <uint256.h>

#include <cstdint>

class CCoinsView;

struct CCoinsStats
{
    int nHeight;
    uint256 hashBlock;
    uint64_t nTransactions;
    uint64_t nTransactionOutputs;
    uint64_t nBogoSize;
    uint256 hashSerialized;
    uint64_t nDiskSize;
    CAmount nTotalAmount;

    CCoinsStats() : nHeight(0), nTransactions(0), nTransactionOutputs(0), nBogoSize(0), nDiskSize(0), nTotalAmount(0) {}
};

//! Calculate statistics about the unspent transaction output set
bool GetUTXOStats(CCoinsView* view, CCoinsStats& stats);

#endif // BROCOIN_NODE_COINSTATS_H
