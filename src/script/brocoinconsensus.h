// Copyright (c) 2009-2010 Abhishek, Mohit Kumar
// Copyright (c) 2009-2018 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_SCRIPT_BROCOINCONSENSUS_H
#define BROCOIN_SCRIPT_BROCOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_BROCOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/brocoin-config.h>
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBBROCOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define BROCOINCONSENSUS_API_VER 1

typedef enum brocoinconsensus_error_t
{
    brocoinconsensus_ERR_OK = 0,
    brocoinconsensus_ERR_TX_INDEX,
    brocoinconsensus_ERR_TX_SIZE_MISMATCH,
    brocoinconsensus_ERR_TX_DESERIALIZE,
    brocoinconsensus_ERR_AMOUNT_REQUIRED,
    brocoinconsensus_ERR_INVALID_FLAGS,
} brocoinconsensus_error;

/** Script verification flags */
enum
{
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    brocoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = brocoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | brocoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               brocoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | brocoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int brocoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, brocoinconsensus_error* err);

EXPORT_SYMBOL int brocoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, brocoinconsensus_error* err);

EXPORT_SYMBOL unsigned int brocoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // BROCOIN_SCRIPT_BROCOINCONSENSUS_H
