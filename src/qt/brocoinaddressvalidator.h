// Copyright (c) 2011-2014 The Brocoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BROCOIN_QT_BROCOINADDRESSVALIDATOR_H
#define BROCOIN_QT_BROCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BrocoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BrocoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Brocoin address widget validator, checks for a valid brocoin address.
 */
class BrocoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BrocoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BROCOIN_QT_BROCOINADDRESSVALIDATOR_H
