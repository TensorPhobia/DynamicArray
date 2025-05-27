#include "./DynamicArray.h"
#include <stdio.h>


int main(){
    DynamicArray arr = DynamicArray_constructor(0);
    for (char i = 'A'; i <= 'z'; i++) {
        printf("content: %c , capacity: %lu\n",i,arr.cap);
        DynamicArray_pushback(&arr, &i , 1);
    }
    printf("content: %c , capacity: %lu\n",'z',arr.cap);
    return 0;
}   
