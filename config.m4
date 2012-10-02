dnl $Id$
dnl config.m4 for extension keccak

PHP_ARG_ENABLE(keccak, whether to enable keccak support,
[  --enable-keccak         Enable keccak support])

if test "$PHP_KECCAK" != "no"; then
  PHP_NEW_EXTENSION(keccak, keccak-impl.c keccak.c KeccakF-1600-opt64.c KeccakNISTInterface.c KeccakSponge.c, $ext_shared)
fi
