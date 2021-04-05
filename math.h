#include "mathComplex.h"

struct functions{
    void (*sum)(void* a, void* b, void* resultplace);
    void (*dif)(void* a, void* b, void* resultplace);
    void (*scalar_mult)(void* a, void* scalar, void* resultplace);
    void (*invers)(void* a, void* resultplace);
    void (*print)(void*a);
    void* (*zero_element)();
};

//int functions
void sum_int(void* a, void* b, void* resultplace);
void dif_int(void* a, void* b, void* resultplace);
void scalar_mult_int(void* a, void* scalar, void* resultplace);
void invers_int(void* a, void* resultplace);
void print_int(void*a);
void *zero_int();

//float functions
void sum_float(void* a, void* b, void* resultplace);
void dif_float(void* a, void* b, void* resultplace);
void scalar_mult_float(void* a, void* scalar, void* resultplace);
void invers_float(void* a, void* resultplace);
void print_float(void*a);
void *zero_float();

//complex functions
void sum_complex(void* a, void* b, void* resultplace);
void dif_complex(void* a, void* b, void* resultplace);
void scalar_mult_complex(void* a, void* scalar, void* resultplace);
void invers_complex(void* a, void* resultplace);
void print_complex(void*a);
void *zero_complex();

struct functions int_functions;
struct functions float_functions;
struct functions complex_functions;
