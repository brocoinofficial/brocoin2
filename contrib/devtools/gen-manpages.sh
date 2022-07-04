#!/usr/bin/env bash

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BROCOIND=${BROCOIND:-$BINDIR/brocoind}
BROCOINCLI=${BROCOINCLI:-$BINDIR/brocoin-cli}
BROCOINTX=${BROCOINTX:-$BINDIR/brocoin-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/brocoin-wallet}
BROCOINQT=${BROCOINQT:-$BINDIR/qt/brocoin-qt}

[ ! -x $BROCOIND ] && echo "$BROCOIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a BRONVER <<< "$($BROCOINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for brocoind if --version-string is not set,
# but has different outcomes for brocoin-qt and brocoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$BROCOIND --version | sed -n '1!p' >> footer.h2m

for cmd in $BROCOIND $BROCOINCLI $BROCOINTX $WALLET_TOOL $BROCOINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BRONVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BRONVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
