#ifndef KECCAK_IMPL_H
#define KECCAK_IMPL_H

#include <stdlib.h>

int keccak(unsigned char hash[64U], const unsigned char *message,
           size_t message_size);

#endif
