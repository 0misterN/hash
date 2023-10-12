#ifndef BASE_ENGINE_H
#define BASE_ENGINE_H

unsigned int *engine(unsigned int *ptr){
    int size = ptr[0];
    unsigned int *array = &ptr[1];
    unsigned long long int res = 0x0000;
    int padding = 0x1001;
    int iterations = sizeof(array) % ;
    for (int i = 0; i<size;i++){
        res |= ptr[i];
        res <<= 4;
        if (res >> 60) {

        }
    }
}

#endif //BASE_ENGINE_H
