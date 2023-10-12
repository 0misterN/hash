#include <stdlib.h>
#include "stdio.h"
#include "string.h"

unsigned int int_hash(unsigned int value);
unsigned int iteration(unsigned int lfsr);
unsigned int *char_list(char *charset);

unsigned long long int main_engine(unsigned long *ptr){
    unsigned int size = ptr[0];
    unsigned int *array = (unsigned int *) ptr[1];
    unsigned long long int res = 0x0000LL;
    int padding = 0x1001;
    unsigned int index = 0;
    for (int i = 0; i<size;i++){
        res |= int_hash(array[i]);
        res <<= 8;
        if (res >> 56) {
            index = i;
            break;
        }
    }
    while (!(res >> 60)){
        res |= padding;
        res <<= 4;
    }


    return res;
}

int tmp(){
    char string[11] = "Hallo Welt";
    char *ptr = (char *) &string[0];
    unsigned int * final = char_list(ptr);
    unsigned long size = sizeof(final);
    printf("%lu\n", size);
    for (int i=0; i<=10;i++){
        printf("%d::%u\n",i , final[i]);
    }

    return 0;
}


int main(){
    for (int i = 0;i<128;i++){
        printf("%d->%u\n", i, int_hash(i));
    }
    return 0;
}



unsigned int *char_list(char *charset){
    int buffer;
    unsigned long size;
    size = strlen(charset);
    if (size == 1){
        printf("Error in memoryreading in charlist");
        exit(1);
    }
    unsigned int *set = (unsigned int*) malloc(sizeof(int) * size);
    for (int i = 0;i<size;i++){
        buffer = (int) charset[i];
        set[i] = int_hash(buffer);
    }
    return set;
}

unsigned int iteration(unsigned  int lfsr){
    int tap = 2;
    int shift_mask = 2048;
    int max_bit = 12;
    lfsr = lfsr % 4096;
    unsigned  int value = lfsr;
    unsigned int res = 0;
    do {
        unsigned  int out = (lfsr & shift_mask)>> (max_bit-1);
        out ^= lfsr & 1;
        //lfsr ^= out << tap;
        lfsr <<= 1;
        lfsr |= out ;
        lfsr %= 4096;
        res <<= 1;
        res |= out;
    } while (lfsr != res);
    return res;
}


unsigned int int_hash(unsigned int value) {
    unsigned int shift_mask = value >> 4;
    printf("%u::", shift_mask);
    value ^= shift_mask;
    unsigned int value2 = ~shift_mask;
    if (value==value2) value | 0x100;
    value = iteration(value);
    value2 = iteration(value2);
    return value ^ value2;
}