#include "tests.h"
#include <assert.h>
#include <stdio.h>
#include "linearform.h"

float round_float(float a, int order){
    for (int i = 0; i < order; i++){
        a = a * 10;
    }
    a = (float)(int)a / 10;
    for (int i = 0; i < order - 1; i++){
        a = a / 10;
    }
    return a;
}

void test_linearshape_create_int(){
    size_t demension = 5;
    int coef_int[] = {1, -2, 3, -4, 5};
    void *coefficients_int = (void*)coef_int;

    struct line_form *result_int = New_line_form(demension, (size_t)sizeof(int), coefficients_int, &int_functions);
    assert(result_int->element_size == sizeof(int));
    assert(result_int->coefficients == coefficients_int);
    assert(result_int->dimension == demension);
    assert(result_int->func->sum == sum_int);
    assert(result_int->func->dif == dif_int);
    assert(result_int->func->scalar_mult == scalar_mult_int);
    assert(result_int->func->invers == invers_int);
    assert(result_int->func->print == print_int);

    free(result_int);
}
void test_linearshape_create_float(){
    size_t demension = 5;
    float coef_float[] = {1.1f, -2.2f, 3.3f, -4.4f, 5.5f};
    void *coefficients_float = (void*)coef_float;

    struct line_form *result_float = New_line_form(demension, (size_t)sizeof(float), coefficients_float, &float_functions);
    assert(result_float->element_size == sizeof(float));
    assert(result_float->coefficients == coefficients_float);
    assert(result_float->dimension == demension);
    assert(result_float->func->sum == sum_float);
    assert(result_float->func->dif == dif_float);
    assert(result_float->func->scalar_mult == scalar_mult_float);
    assert(result_float->func->invers == invers_float);
    assert(result_float->func->print == print_float);

    free(result_float);
}
void test_linearshape_create_complex(){
    size_t demension = 5;
    struct complex coef_complex[] = {{1, 2},{-1.5f,9}, {0, 5.5f},{6.6f,0},{-5,-4}};
    void *coefficients_complex = (void*)coef_complex;

    struct line_form *result_complex = New_line_form(demension, (size_t)sizeof(struct complex), coefficients_complex, &complex_functions);
    assert(result_complex->element_size == sizeof(struct complex));
    assert(result_complex->coefficients == coefficients_complex);
    assert(result_complex->dimension == demension);
    assert(result_complex->func->sum == sum_complex);
    assert(result_complex->func->dif == dif_complex);
    assert(result_complex->func->scalar_mult == scalar_mult_complex);
    assert(result_complex->func->invers == invers_complex);
    assert(result_complex->func->print == print_complex);

    free(result_complex);
}


void test_set_get_int(){
    size_t demension = 5;
    int coef_int[] = {1, -2, 3, -4, 5};
    int val1 = 6;
    int val2 = -6;
    void *coefficients_int = (void*)coef_int;
    void *value1 = &val1;
    void *value2 = &val2;

    struct line_form *result_int = New_line_form(demension, (size_t)sizeof(int), coefficients_int, &int_functions);
    set_coefficient(result_int,1, value1);
    set_coefficient(result_int,2, value2);

    assert(*(int*)((int)result_int->coefficients + result_int->element_size * 0) == 1);
    assert(*(int*)((int)result_int->coefficients + result_int->element_size * 1) == 6);
    assert(*(int*)((int)result_int->coefficients + result_int->element_size * 2) == -6);
    assert(*(int*)((int)result_int->coefficients + result_int->element_size * 3) == -4);
    assert(*(int*)((int)result_int->coefficients + result_int->element_size * 4) == 5);

    void* a = malloc(result_int->element_size);
    get_coefficient(result_int, 0, a);
    void* b = malloc(result_int->element_size);
    get_coefficient(result_int, 1, b);
    void* c = malloc(result_int->element_size);
    get_coefficient(result_int, 2, c);
    void* d = malloc(result_int->element_size);
    get_coefficient(result_int, 3, d);
    void* e = malloc(result_int->element_size);
    get_coefficient(result_int, 4, e);

    assert(*(int*)a == 1);
    assert(*(int*)b == 6);
    assert(*(int*)c == -6);
    assert(*(int*)d == -4);
    assert(*(int*)e == 5);

    free(result_int); free(a); free(b); free(c); free(d); free(e);
}
void test_set_get_float(){
    size_t demension = 5;
    float coef_float[] = {1.1f, -2.2f, 3.3f, -4.4f, 5.5f};
    float val1 = 6.6f;
    float val2 = -6.6f;
    void *coefficients_float = (void*)coef_float;
    void *value1 = &val1;
    void *value2 = &val2;

    struct line_form *result_float = New_line_form(demension, (size_t)sizeof(float), coefficients_float, &complex_functions);
    set_coefficient(result_float,1, value1);
    set_coefficient(result_float,2, value2);

    assert(*(float*)((int)result_float->coefficients + result_float->element_size * 0) == 1.1f);
    assert(*(float*)((int)result_float->coefficients + result_float->element_size * 1) == 6.6f);
    assert(*(float*)((int)result_float->coefficients + result_float->element_size * 2) == -6.6f);
    assert(*(float*)((int)result_float->coefficients + result_float->element_size * 3) == -4.4f);
    assert(*(float*)((int)result_float->coefficients + result_float->element_size * 4) == 5.5f);

    void* a = malloc(result_float->element_size);
    get_coefficient(result_float, 0, a);
    void* b = malloc(result_float->element_size);
    get_coefficient(result_float, 1, b);
    void* c = malloc(result_float->element_size);
    get_coefficient(result_float, 2, c);
    void* d = malloc(result_float->element_size);
    get_coefficient(result_float, 3, d);
    void* e = malloc(result_float->element_size);
    get_coefficient(result_float, 4, e);

    assert(*(float*)a == 1.1f);
    assert(*(float*)b == 6.6f);
    assert(*(float*)c == -6.6f);
    assert(*(float*)d == -4.4f);
    assert(*(float*)e == 5.5f);

    free(result_float); free(a); free(b); free(c); free(d); free(e);
}
void test_set_get_complex(){
    size_t demension = 5;
    struct complex coef_complex[] = {{1, 2},{-1.5f,9}, {0, 5.5f},{6.6f, -6.6f},{-5,-4}};
    struct complex val1 = {6.6f, 0};
    struct complex val2 = {-5, 5.5f};
    void *coefficients_complex = (void*)coef_complex;
    void *value1 = &val1;
    void *value2 = &val2;

    struct line_form *result_complex = New_line_form(demension, (size_t)sizeof(struct complex), coefficients_complex, &complex_functions);
    set_coefficient(result_complex,1, value1);
    set_coefficient(result_complex,2, value2);

    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 0))->real_part == 1);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 0))->im_part == 2);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 1))->real_part == 6.6f);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 1))->im_part == 0);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 2))->real_part == -5);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 2))->im_part == 5.5);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 3))->real_part == 6.6f);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 3))->im_part == -6.6f);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 4))->real_part == -5);
    assert(((struct complex*)((int)result_complex->coefficients + result_complex->element_size * 4))->im_part == -4);

    void* a = malloc(result_complex->element_size);
    get_coefficient(result_complex, 0, a);
    void* b = malloc(result_complex->element_size);
    get_coefficient(result_complex, 1, b);
    void* c = malloc(result_complex->element_size);
    get_coefficient(result_complex, 2, c);
    void* d = malloc(result_complex->element_size);
    get_coefficient(result_complex, 3, d);
    void* e = malloc(result_complex->element_size);
    get_coefficient(result_complex, 4, e);

    assert(((struct complex*)a)->real_part== 1);
    assert(((struct complex*)a)->im_part == 2);
    assert(((struct complex*)b)->real_part == 6.6f);
    assert(((struct complex*)b)->im_part == 0);
    assert(((struct complex*)c)->real_part == -5);
    assert(((struct complex*)c)->im_part == 5.5);
    assert(((struct complex*)d)->real_part == 6.6f);
    assert(((struct complex*)d)->im_part == -6.6f);
    assert(((struct complex*)e)->real_part == -5);
    assert(((struct complex*)e)->im_part == -4);

    free(result_complex); free(a); free(b); free(c); free(d); free(e);
}


void test_linearshape_func_int(){
    size_t demension1 = 5;
    size_t demension2 = 3;
    int coef1_int[] = {1, -2, 3, -4, 5};
    int coef2_int[] = {-1, 2, -3, 4, -5};
    int coef3_int[] = {0, 0, 0, 0, 0};
    int coef4_int[] = {1, -2, 3};
    int coef5_int[] = {0, 0, 0, 4, -5};
    int coef6_int[] = {5, -10, 15, -20, 25};
    int coef7_int[] = {-5, 10, -15, 20, -25};
    int args_int[] = {1, -1, 0, 2};
    int value1 = 5;
    int value2 = -5;
    int eval = 6;

    struct line_form *a = New_line_form(demension1, (size_t)sizeof(int), (void*)coef1_int, &int_functions);
    struct line_form *b = New_line_form(demension1, (size_t)sizeof(int), (void*)coef2_int, &int_functions);
    struct line_form *c = New_line_form(demension1, (size_t)sizeof(int), (void*)coef3_int, &int_functions);
    struct line_form *d = New_line_form(demension2, (size_t)sizeof(int), (void*)coef4_int, &int_functions);
    struct line_form *e = New_line_form(demension1, (size_t)sizeof(int), (void*)coef5_int, &int_functions);
    struct line_form *f = New_line_form(demension1, (size_t)sizeof(int), (void*)coef6_int, &int_functions);
    struct line_form *g = New_line_form(demension1, (size_t)sizeof(int), (void*)coef7_int, &int_functions);

    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)sum_lineform(a, b)->coefficients + a->element_size * i) == *(int*)((int)c->coefficients + a->element_size * i));
    }//с одинаковой длиной
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)sum_lineform(d, b)->coefficients + a->element_size * i) == *(int*)((int)e->coefficients + a->element_size * i));
    }
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)sum_lineform(b, d)->coefficients + a->element_size * i) == *(int*)((int)e->coefficients + a->element_size * i));
    }//с разной длиной
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)dif_lineform(c, a)->coefficients + a->element_size * i) == *(int*)((int)b->coefficients + a->element_size * i));
    }//с одинаковой размерностью
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)dif_lineform(e, d)->coefficients + a->element_size * i) == *(int*)((int)b->coefficients + a->element_size * i));
    }
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)dif_lineform(d, e)->coefficients + a->element_size * i) == *(int*)((int)a->coefficients + a->element_size * i));
    }//с разной длиной

    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)mult_lineform(a, (void*)&value1)->coefficients + a->element_size * i) == *(int*)((int)f->coefficients + a->element_size * i));
    }
    for (int i = 0; i < a->dimension; i++){
        assert(*(int*)((int)mult_lineform(a, (void*)&value2)->coefficients + a->element_size * i) == *(int*)((int)g->coefficients + a->element_size * i));
    }

    assert(*(int*)value_lineform_on_args(a, (void*)&args_int) == eval);

    free(a);free(b);free(c);free(d);free(e);free(f);free(g);
}
void test_linearshape_func_float(){
    size_t demension1 = 5;
    size_t demension2 = 3;
    float coef1_float[] = {1.1f, -2.2f, 3.3f, 0, 5};
    float coef2_float[] = {-1.1f, 2.2f, -3.3f, 0, -5};
    float coef3_float[] = {0, 0, 0, 0, 0};
    float coef4_float[] = {1.1f, -2.2f, 3.3f};
    float coef5_float[] = {0, 0, 0, 0, -5};
    float coef6_float[] = {6.05f, -12.1f, 18.15f, 0, 27.5f};
    float coef7_float[] = {-5.5f, 11.0f, -16.5f, 0, -25};
    float args_float[] = {1.1f, -5, 0, 4.4f};
    float value1 = 5.5f;
    float value2 = -5;
    float eval = 4.180000f;

    struct line_form *a = New_line_form(demension1, (size_t)sizeof(float), (void*)coef1_float, &float_functions);
    struct line_form *b = New_line_form(demension1, (size_t)sizeof(float), (void*)coef2_float, &float_functions);
    struct line_form *c = New_line_form(demension1, (size_t)sizeof(float), (void*)coef3_float, &float_functions);
    struct line_form *d = New_line_form(demension2, (size_t)sizeof(float), (void*)coef4_float, &float_functions);
    struct line_form *e = New_line_form(demension1, (size_t)sizeof(float), (void*)coef5_float, &float_functions);
    struct line_form *f = New_line_form(demension1, (size_t)sizeof(float), (void*)coef6_float, &float_functions);
    struct line_form *g = New_line_form(demension1, (size_t)sizeof(float), (void*)coef7_float, &float_functions);

    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)sum_lineform(a, b)->coefficients + a->element_size * i) == *(float*)((int)c->coefficients + a->element_size * i));
    }//с одинаковой длиной
    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)sum_lineform(d, b)->coefficients + a->element_size * i) == *(float*)((int)e->coefficients + a->element_size * i));
    }
    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)sum_lineform(b, d)->coefficients + a->element_size * i) == *(float*)((int)e->coefficients + a->element_size * i));
    }//с разной длиной

    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)dif_lineform(c, a)->coefficients + a->element_size * i) == *(float*)((int)b->coefficients + a->element_size * i));
    }//с одинаковой размерностью
    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)dif_lineform(e, d)->coefficients + a->element_size * i) == *(float*)((int)b->coefficients + a->element_size * i));
}
    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)dif_lineform(d, e)->coefficients + a->element_size * i) == *(float*)((int)a->coefficients + a->element_size * i));
    }//с разной длиной

    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)mult_lineform(a, (void*)&value1)->coefficients + a->element_size * i) == *(float*)((int)f->coefficients + a->element_size * i));
    }
    for (int i = 0; i < a->dimension; i++){
        assert(*(float*)((int)mult_lineform(a, (void*)&value2)->coefficients + a->element_size * i) == *(float*)((int)g->coefficients + a->element_size * i));
    }

    assert(round_float(*(float*)value_lineform_on_args(a, (void*)&args_float), 2) == eval);

    free(a);free(b);free(c);free(d);free(e);free(f);free(g);
}
void test_linearshape_func_complex(){
    size_t demension1 = 3;
    size_t demension2 = 2;
    struct complex coef1_complex[] = {{1.1f, 2},{-1.5f,0}, {0, 5.5f}};
    struct complex coef2_complex[] = {{-1.1f, -2},{1.5f,0}, {0, -5.5f}};
    struct complex coef3_complex[] = {{0, 0},{0,0}, {0, 0}};
    struct complex coef4_complex[] = {{1.1f, 2},{-1.5f,0}};
    struct complex coef5_complex[] = {{0, 0},{0,0}, {0, -5.5f}};
    struct complex coef6_complex[] = {{12.21f, -3.85f},{-1.65f,8.25f}, {30.25f, 6.05f}};
    struct complex args_complex[] = {{-1, 5.5f},{0,-6}};
    struct complex value = {1.1f, -5.5f};
    struct complex eval = {35.6f,-6.25f};

    struct line_form *a = New_line_form(demension1, (size_t)sizeof(struct complex), (void*)coef1_complex, &complex_functions);
    struct line_form *b = New_line_form(demension1, (size_t)sizeof(struct complex), (void*)coef2_complex, &complex_functions);
    struct line_form *c = New_line_form(demension1, (size_t)sizeof(struct complex), (void*)coef3_complex, &complex_functions);
    struct line_form *d = New_line_form(demension2, (size_t)sizeof(struct complex), (void*)coef4_complex, &complex_functions);
    struct line_form *e = New_line_form(demension1, (size_t)sizeof(struct complex), (void*)coef5_complex, &complex_functions);
    struct line_form *f = New_line_form(demension1, (size_t)sizeof(struct complex), (void*)coef6_complex, &complex_functions);


    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)sum_lineform(a, b)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)c->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)sum_lineform(a, b)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)c->coefficients + a->element_size * i)).im_part);
    }//с одинаковой длиной
    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)sum_lineform(d, b)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)e->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)sum_lineform(d, b)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)e->coefficients + a->element_size * i)).im_part);
    }
    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)sum_lineform(b, d)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)e->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)sum_lineform(b, d)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)e->coefficients + a->element_size * i)).im_part);
    }//с разной длиной

    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)dif_lineform(c, a)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)b->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)dif_lineform(c, a)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)b->coefficients + a->element_size * i)).im_part);
    }//с одинаковой размерностью
    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)dif_lineform(e, d)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)b->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)dif_lineform(e, d)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)b->coefficients + a->element_size * i)).im_part);
    }
    for (int i = 0; i < a->dimension; i++){
        assert((*(struct complex*)((int)dif_lineform(d, e)->coefficients + a->element_size * i)).real_part == (*(struct complex*)((int)a->coefficients + a->element_size * i)).real_part);
        assert((*(struct complex*)((int)dif_lineform(d, e)->coefficients + a->element_size * i)).im_part == (*(struct complex*)((int)a->coefficients + a->element_size * i)).im_part);
    }//с разной длиной

    for (int i = 0; i < a->dimension; i++){
        assert(round_float((*(struct complex*)((int)mult_lineform(a, (void*)&value)->coefficients + a->element_size * i)).real_part, 2) == round_float((*(struct complex*)((int)f->coefficients + a->element_size * i)).real_part, 2));
        assert(round_float((*(struct complex*)((int)mult_lineform(a, (void*)&value)->coefficients + a->element_size * i)).im_part, 2) == round_float((*(struct complex*)((int)f->coefficients + a->element_size * i)).im_part, 2));
    }

    assert(round_float((*(struct complex*)value_lineform_on_args(a, (void*)&args_complex)).real_part, 2) == round_float(eval.real_part , 2));
    assert(round_float((*(struct complex*)value_lineform_on_args(a, (void*)&args_complex)).im_part, 2) == round_float(eval.im_part , 2));

    free(a);free(b);free(c);free(d);free(e);free(f);
}

void test_all(){
    test_linearshape_create_int();
    test_linearshape_create_float();
    test_linearshape_create_complex();
    test_set_get_int();
    test_set_get_float();
    test_set_get_complex();
    test_linearshape_func_int();
    test_linearshape_func_float();
    test_linearshape_func_complex();
}