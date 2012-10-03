
#include "KeccakNISTInterface.h"
#include "keccak-impl.h"

int
keccak(unsigned char hash[64U], const unsigned char *message,
       size_t message_size)
{
    if (Hash(512, (const BitSequence *) message,
             (DataLength) message_size * 8ULL, hash) != SUCCESS) {
        return -1;
    }
    return 0;
}
