#ifndef BASE_ENGINE_H
#define BASE_ENGINE_H

unsigned int *engine(unsigned int *ptr){
    int size = ptr[0];
    unsigned int *array = &ptr[1];
    unsigned long long int res = 0x0000;
    int padding = 0x1001;
    int iterations = sizeof(array) % ;
    int rep_bool = 0;
    int index = 0
    for (int i = 0; i<size;i++){
        index = size % 64;
        res |= ptr[i];
        res <<= 4;
        if (res >> 60) {
            rep_bool = 1;
        }
    }
}

#endif //BASE_ENGINE_H
