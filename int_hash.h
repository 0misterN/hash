#ifndef BASE_int_hash_H
#define BASE_int_hash_H
#include "stdio.h"
#include "lfsr_base.h"

unsigned int int_hash(unsigned int value){
    unsigned int shift_mask = value >> 4;
    value ^= shift_mask;
    unsigned int value2 = !value;
    value = iteration(value);
    value2 = iteration(value2);
    return value ^ value2;
}
#endif