// Copyright (c) 2009-2010 Abhishek, Mohit Kumar
// Copyright (c) 2009-2018 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_POLICY_FEERATE_H
#define BROCOIN_POLICY_FEERATE_H

#include <amount.h>
#include <serialize.h>

#include <string>

extern const std::string CURRENCY_UNIT;

/**
 * Fee rate in bronees per kilobyte: CAmount / kB
 */
class CFeeRate
{
private:
    CAmount nBroneesPerK; // unit is bronees-per-1,000-bytes

public:
    /** Fee rate of 0 bronees per kB */
    CFeeRate() : nBroneesPerK(0) { }
    template<typename I>
    CFeeRate(const I _nBroneesPerK): nBroneesPerK(_nBroneesPerK) {
        // We've previously had bugs creep in from silent double->int conversion...
        static_assert(std::is_integral<I>::value, "CFeeRate should be used without floats");
    }
    /** Constructor for a fee rate in bronees per kB. The size in bytes must not exceed (2^63 - 1)*/
    CFeeRate(const CAmount& nFeePaid, size_t nBytes);
    /**
     * Return the fee in bronees for the given size in bytes.
     */
    CAmount GetFee(size_t nBytes) const;
    /**
     * Return the fee in bronees for a size of 1000 bytes
     */
    CAmount GetFeePerK() const { return GetFee(1000); }
    friend bool operator<(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK < b.nBroneesPerK; }
    friend bool operator>(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK > b.nBroneesPerK; }
    friend bool operator==(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK == b.nBroneesPerK; }
    friend bool operator<=(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK <= b.nBroneesPerK; }
    friend bool operator>=(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK >= b.nBroneesPerK; }
    friend bool operator!=(const CFeeRate& a, const CFeeRate& b) { return a.nBroneesPerK != b.nBroneesPerK; }
    CFeeRate& operator+=(const CFeeRate& a) { nBroneesPerK += a.nBroneesPerK; return *this; }
    std::string ToString() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(nBroneesPerK);
    }
};

#endif //  BROCOIN_POLICY_FEERATE_H
