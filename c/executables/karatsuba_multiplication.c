/**
 * Karatsuba Muliplication Implementation
 * 
 * Author: Jordan Yates ( jordan.yates.au@gmail.com )
 */

/* Includes ******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

/* Function Prototypes *******************************************************/

uint64_t karatsubaMultiplication(uint32_t x, uint32_t y);

/*****************************************************************************/

int main(int argc, char** argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: karatsuba.out x y\r\n");
        return -1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    fprintf(stdout, "%ld\r\n", karatsubaMultiplication(x, y));
    return 0;
}

/*****************************************************************************/

uint64_t karatsubaMultiplication(uint32_t x, uint32_t y)
{
    uint32_t lenX = 32 - __builtin_clz(x);
    uint32_t lenY = 32 - __builtin_clz(y);

    /* Terminating Case */
    if ((x < 2) || (y < 2)) {
        return x * y;
    }

    uint32_t n = lenX < lenY ? lenX : lenY;
    uint32_t n2 = n / 2;

    uint32_t mask = (1 << n2 ) - 1;
    /* Split x and y into two halves (a,b) and (c,d) */
    uint32_t a = x >> n2;
    uint32_t b = x & mask;
    uint32_t c = y >> n2;
    uint32_t d = y & mask;

    uint64_t ac = karatsubaMultiplication(a, c);
    uint64_t bd = karatsubaMultiplication(b, d);
    uint64_t middle = karatsubaMultiplication(a + b, c + d);
    uint64_t ad_bc = middle - ac - bd;

    return (ac << (n2 * 2)) + (ad_bc << n2) + bd;
}

/*****************************************************************************/

