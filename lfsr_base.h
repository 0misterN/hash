#ifndef BASE_lfsr_base_H
#define BASE_lfsr_base_H

#include <stdio.h>

unsigned int iteration(unsigned  int lfsr){
    int tap = 2;
    int shift_mask = 128;
    int max_bit = 8;
    lfsr = lfsr % 256;
    unsigned  int value = lfsr;
    unsigned int res = 0;
    do {
        unsigned  int out = (lfsr & shift_mask)>> (max_bit-1);
        out ^= lfsr & 1;
        lfsr ^= out << tap;
        lfsr <<= 1;
        lfsr |= out ;
        lfsr %= 256;
        res <<= 1;
        res |= out;
    } while (lfsr != res);
    return res;
}
#endif