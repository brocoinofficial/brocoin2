// Copyright (c) 2009-2010 Abhishek, Mohit Kumar
// Copyright (c) 2009-2018 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_AMOUNT_H
#define BROCOIN_AMOUNT_H

#include <stdint.h>

/** Amount in bronees (Can be negative) */
typedef int64_t CAmount;

static const CAmount COIN = 100000000;

/** No amount larger than this (in bronee) is valid.
 *
 * Note that this constant is *not* the total money supply, which in Brocoin
 * currently happens to be less than 21,000,000 BRON for various reasons, but
 * rather a sanity check. As this sanity check is used by consensus-critical
 * validation code, the exact value of the MAX_MONEY constant is consensus
 * critical; in unusual circumstances like a(nother) overflow bug that allowed
 * for the creation of coins out of thin air modification could lead to a fork.
 * */
static const CAmount MAX_MONEY = 100000000 * COIN;
inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

#endif //  BROCOIN_AMOUNT_H
