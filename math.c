#include <string.h>
#include "math.h"
#include <stdio.h>

//int functions
void sum_int(void* a, void* b, void* resultplace){
    *(int*)resultplace = *(int*)a + *(int*)b;
}
void dif_int(void* a, void* b, void* resultplace){
    *(int*)resultplace = *(int*)a - *(int*)b;
}
void scalar_mult_int(void* a, void* scalar, void* resultplace){
    *(int*)resultplace = *(int*)a * *(int*)scalar;
}
void invers_int(void* a, void* resultplace){
    *(int*)resultplace = *(int*)a * -1;
}
void print_int(void*a){
    printf("%d", *(int*)a);
}
void *zero_int(){
    void *i = malloc(sizeof(int));
    *(int*)i = 0;
    return i;
}

//float functions
void sum_float(void* a, void* b, void* resultplace){
    *(float*)resultplace = *(float*)a + *(float*)b;
}
void dif_float(void* a, void* b, void* resultplace){
    *(float*)resultplace = *(float*)a - *(float*)b;
}
void scalar_mult_float(void* a, void* scalar, void* resultplace){
    *(float*)resultplace = *(float*)a * *(float*)scalar;
}
void invers_float(void* a, void* resultplace){
    *(float*)resultplace = *(float*)a * -1;
}
void print_float(void*a){
    printf("%f", *(float*)a);
}
void *zero_float(){
    void *i = malloc(sizeof(float));
    *(float*)i = 0;
    return i;
}

//complex functions
void sum_complex(void* a, void* b, void* resultplace){
    *(struct complex*)resultplace = *sum_of_complex((struct complex*)a, (struct complex*)b);
}
void dif_complex(void* a, void* b, void* resultplace){
    *(struct complex*)resultplace = *dif_of_complex((struct complex*)a, (struct complex*)b);
}
void scalar_mult_complex(void* a, void* scalar, void* resultplace){
    *(struct complex*)resultplace = *scalar_mult_of_complex((struct complex*)a, (struct complex*)scalar);
}
void invers_complex(void* a, void* resultplace){
    *(struct complex*)resultplace = *invers_of_complex((struct complex*)a);
}
void print_complex(void*a){
    print_of_complex((struct complex*)a);
}
void *zero_complex(){
    void *i = malloc(sizeof(struct complex));
    ((struct complex*)i)->real_part = 0;
    ((struct complex*)i)->im_part = 0;
    return i;
}

struct functions int_functions = {sum_int, dif_int, scalar_mult_int, invers_int, print_int, zero_int};
struct functions float_functions = {sum_float, dif_float, scalar_mult_float,invers_float, print_float, zero_float};
struct functions complex_functions = {sum_complex, dif_complex, scalar_mult_complex, invers_complex, print_complex, zero_complex};