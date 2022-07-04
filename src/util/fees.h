// Copyright (c) 2009-2010 Abhishek, Mohit Kumar
// Copyright (c) 2009-2018 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BROCOIN_UTIL_FEES_H
#define BROCOIN_UTIL_FEES_H

#include <string>

enum class FeeEstimateMode;
enum class FeeReason;

bool FeeModeFromString(const std::string& mode_string, FeeEstimateMode& fee_estimate_mode);
std::string StringForFeeReason(FeeReason reason);

#endif // BROCOIN_UTIL_FEES_H
