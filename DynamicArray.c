#include "./DynamicArray.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long logBase(unsigned long base ,unsigned long number){
    return ceil(log(number)/log(base));
}

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

int DynamicArray_overflow_handler(DynamicArray *arr , float growth_rate){
    assert(growth_rate > 1);
    int newCap = arr->cap * growth_rate;
    void * newMem = realloc(arr->raw,newCap);
    if(!newMem) return REALLOC_FAILURE;
    arr->cap = newCap;
    return REALLOC_SUCESS;
}

/*
    data_len = 100
    capacity = 10
    Growth_rate = 2
    capacity * Growth_rate ^ x >= data_len 
    Growth_rate ^ x = data_len / capacity
    we solve for x : x = LogBase(Growth_rate,data_len / capacity); 

*/

void DynamicArray_pushback(DynamicArray *arr , char *data , unsigned long data_len){
    assert(data);
    if(arr->cap - arr->len > data_len ){
        memcpy(arr->raw + arr->len, data, sizeof(data[0]) * data_len);
    }else{
        unsigned long x = logBase(GROWTH_RATE, data_len / arr->cap);
        assert(DynamicArray_overflow_handler(arr , pow(GROWTH_RATE,x)) == REALLOC_SUCESS);
        memcpy(arr->raw + arr->len, data, sizeof(data[0]) * data_len);
    }
    arr->len+=data_len;
}