#ifndef BASE_MK_CHAR_LIST_H
#define BASE_MK_CHAR_LIST_H
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
unsigned long *char_list(char *charset){
    int *ptr;
    unsigned int size;
    size = strlen(charset);
    if (size == 1){
        printf("Error in memoryreading in charlist");
        exit(1);
    }
    int set[size];
    for (int i = 0;i<size;i++){
        set[i] = (int) charset[i];
    }
    ptr = (int *) &set;
    unsigned int res[2];
    res[0] = size;
    res[1] = *ptr;
    unsigned long int *ptr2 = &res;
    return ptr2;
}
#endif //BASE_MK_CHAR_LIST_H
