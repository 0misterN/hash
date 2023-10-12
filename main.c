#include "stdio.h"
#include "string.h"

unsigned int int_hash(unsigned int value);
unsigned int iteration(unsigned int lfsr);
int *char_list(char *charset);

unsigned long long int main_engine(unsigned long *ptr){
    unsigned int size = ptr[0];
    unsigned int *array = (unsigned long *) ptr[1];
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

int main(){
    char string[10] = "Hallo Welt";
    char *ptr = (char *) &string;
    unsigned long long final = main_engine(char_list(ptr));
    return 0;
}



int *char_list(char *charset){
    int size;
    size = strlen(charset);
    if (size == 1){
        printf("Error in memoryreading in charlist");
        exit(1);
    }
    int set[size];
    for (int i = 0;i<size;i++){
        set[i] = (int) charset[i];
    }
    int *ptr[size + 1];
    ptr[0] =  &size;
    for (int i=1;i<size+1;i++){
        ptr[i] = &set[i-1];
    }
    return ptr;
}

unsigned int iteration(unsigned  int lfsr){
    int shift_mask = 8;
    int max_bit = 4;
    lfsr = lfsr % 16;
    unsigned  int value = lfsr;
    unsigned int res = 0;
    int c =0;
    do {
        unsigned  int out = (lfsr & 1) << (max_bit-1);
        out ^= lfsr & shift_mask;
        res |= (out >> (max_bit-1)) << c;
        lfsr >>= 1;
        lfsr |= out;
        lfsr %= 16;
        printf("%u::", lfsr);
        c++;
        if (c>100) break;
    } while (lfsr != value);
    return res;
}

unsigned int int_hash(unsigned int value){
    unsigned int shift_mask = value >> 4;
    value ^= shift_mask;
    unsigned int value2 = !value;
    value = iteration(value);
    value2 = iteration(value2);
    return value ^ value2;
}

