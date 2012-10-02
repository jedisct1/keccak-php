Keccak-512 (SHA-3) for PHP
==========================

Usage:

    keccak_hash(message)

outputs `keccak-512(message)` as a 64-byte string.

Installation
============

    $ phpize
    $ ./configure --enable-keccak
    $ make install

And add `extension=keccak.so` to your php.ini configuration file.
