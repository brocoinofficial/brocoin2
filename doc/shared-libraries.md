Shared Libraries
================

## brocoinconsensus

The purpose of this library is to make the verification functionality that is critical to Brocoin's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `brocoinconsensus.h` located in `src/script/brocoinconsensus.h`.

#### Version

`brocoinconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`brocoinconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `brocoinconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/brocoin/bips/blob/master/bip-0016.mediawiki)) subscripts
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/brocoin/bips/blob/master/bip-0066.mediawiki)) compliance
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/brocoin/bips/blob/master/bip-0147.mediawiki))
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/brocoin/bips/blob/master/bip-0065.mediawiki))
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/brocoin/bips/blob/master/bip-0112.mediawiki))
- `brocoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/brocoin/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `brocoinconsensus_ERR_OK` - No errors with input parameters *(see the return value of `brocoinconsensus_verify_script` for the verification status)*
- `brocoinconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `brocoinconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `brocoinconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `brocoinconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NBrocoin](https://github.com/NicolasDorier/NBrocoin/blob/master/NBrocoin/Script.cs#L814) (.NET Bindings)
- [node-libbrocoinconsensus](https://github.com/bitpay/node-libbrocoinconsensus) (Node.js Bindings)
- [java-libbrocoinconsensus](https://github.com/dexX7/java-libbrocoinconsensus) (Java Bindings)
- [brocoinconsensus-php](https://github.com/Bit-Wasp/brocoinconsensus-php) (PHP Bindings)
