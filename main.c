#include <stdlib.h>
#include <string.h>
#include "KeccakNISTInterface.h"

int main(void)
{
    unsigned char result[64];   
    char data[] = "testoy";
    size_t len = strlen(data);
    
    memset(result, 0, sizeof result);
    Hash(512, data, len * 8, result);
    printf("%02X%02X%02X%02X\n", result[0], result[1], result[2], result[3]);
    
    return 0;
}
