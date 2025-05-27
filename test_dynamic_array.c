#include "./DynamicArray.h"
#include <stdio.h>
#include <string.h>


int main(){
    DynamicArray arr = DynamicArray_constructor(3);
    printf("len: %lu cap: %lu\n",arr.len,arr.cap);
    char long_str[] = "The quick brown fox jumps over the lazy dog";
    DynamicArray_pushback(&arr,long_str , strlen(long_str));
    printf("len: %lu cap: %lu\n",arr.len,arr.cap);
    for (int  i = 0; i  < arr.len; i++) {
        printf("%c",arr.raw[i]);
    }
    puts("");
    return 0;
}   