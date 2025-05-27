#include "./DynamicArray.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

DynamicArray DynamicArray_constructor(unsigned long capacity){
    DynamicArray arr;
    arr.raw = malloc(capacity * sizeof(arr.raw[0]));//should work because sizeof is compile time macro
    assert(arr.raw);
    arr.cap = capacity;
    arr.len = 0;
    return arr;
}
void DynamicArray_destructor(DynamicArray *arr){
    if(!arr->raw)return;
    arr->cap = arr->len = 0;
    free(arr->raw);
}

int DynamicArray_overflow_handler(DynamicArray *arr , unsigned long new_capacity){
    assert(new_capacity > 1);
    void * newMem = realloc(arr->raw,new_capacity * sizeof(arr->raw[0]));
    if(!newMem) return REALLOC_FAILURE;
    arr->cap = new_capacity;
    arr->raw = newMem;
    return REALLOC_SUCESS;
}

/*
    Scaling Formula Used
    new ArrCapacity = ArrCapacity  * GrowthRate ^ x
    such as new ArrCapacity >= DataLen +  ArrDataLen
    
*/

void DynamicArray_pushback(DynamicArray *arr , char *data , unsigned long data_len){
    assert(data);
    unsigned long total_len = arr->len + data_len;
    if(arr->cap  >= total_len ){
        memcpy(arr->raw + arr->len, data, sizeof(data[0]) * data_len);
    }else{
        unsigned long new_capacity = arr->cap == 0? 1 : arr->cap;
        while(new_capacity <= total_len)  new_capacity*=GROWTH_RATE;
        assert(DynamicArray_overflow_handler(arr ,new_capacity ) == REALLOC_SUCESS);
        memcpy(arr->raw + arr->len, data, sizeof(data[0]) * data_len);
    }
    arr->len+=data_len;
}
