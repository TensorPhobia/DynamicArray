#define GROWTH_RATE 2
#define REALLOC_SUCESS 1
#define REALLOC_FAILURE -1
typedef struct{
    unsigned long len,cap;
    char *raw;
}DynamicArray;

//_______________[DynamicArray Operations]_______________
DynamicArray DynamicArray_constructor(unsigned long capacity);
void DynamicArray_destructor(DynamicArray *arr);
void DynamicArray_pushback(DynamicArray *arr , char *data , unsigned long data_len);
int DynamicArray_overflow_handler(DynamicArray *arr , float growth_rate);
//_______________[End DynamicArray Operations]_______________