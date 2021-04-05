//
// Created by adm on 22.02.2021.
//
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "linearform.h"

void destroy_lineform(struct line_form *a){
    free(a->coefficients);
    free(a);
}

void get_coefficient(struct line_form *a, size_t order, void* where){
    void* value = (void*) ((int) a->coefficients + (order * a->element_size));
    memcpy(where, value, a->element_size);
}
void set_coefficient(struct line_form *a, size_t order, void* value){
    void* where = (void*) ((int) a->coefficients + (order * a->element_size));
    memcpy(where, value, a->element_size);
}

struct line_form* New_line_form(size_t dimension, size_t element_size, void* coefficients, struct functions *func){
    struct line_form *result = malloc(sizeof(struct line_form));//память под массив коэффициентов я делаю в create_type
    result->dimension = dimension;
    result->element_size = element_size;
    result->coefficients = coefficients;
    result->func = func;
    return result;
}

struct line_form* increase_lineform(struct line_form *a, size_t new_dimension){
    struct line_form* result;
    if (a->dimension <= new_dimension) {
        result = malloc(sizeof(struct line_form));
        result->dimension = new_dimension;
        result->element_size = a->element_size;
        result->func = a->func;

        void *coefficients = malloc(a->element_size * new_dimension);
        result->coefficients = coefficients;
        for (int i = 0; i < a->dimension; i++) {
            void *where = (void *) ((int) result->coefficients + result->element_size * i);
            void *value = (void *) ((int) a->coefficients + a->element_size * i);
            memcpy(where, value, a->element_size);
        }
        for (int i = a->dimension; i < new_dimension; i++){
            void *where = (void *) ((int) result->coefficients + result->element_size * i);
            void *value = (a->func->zero_element());
            memcpy(where, value, a->element_size);
        }
    }else{
        printf("Ошибка с размерностью");
        result = NULL;
    }

    return result;
}

struct line_form* sum_lineform(struct line_form *a, struct line_form *b){
    struct line_form *result, *new_a, *new_b;
    if (a->func == b->func) {
        if (a->dimension > b->dimension) {
            new_a = a;
            new_b = increase_lineform(b, a->dimension);
        }else if(b->dimension > a->dimension) {
            new_a = increase_lineform(a, b->dimension);
            new_b = b;
        }else{
            new_a = a;
            new_b = b;
        }//получаются две линейные формы одинаковой длины

        void *coefficient;
        coefficient = (void*) malloc(new_a->element_size * new_a->dimension);
        result = New_line_form(new_a->dimension, new_a->element_size, coefficient, new_a->func);
        //создние результирующей структуры

        void *position, *from;
        for (size_t i = 0; i < new_a->dimension; i++) {
            void *coef1 = malloc(a->element_size);
            void *coef2 = malloc(a->element_size);
            position = (void*)((int)result->coefficients + i * result->element_size);
            get_coefficient(new_a, i, coef1);
            get_coefficient(new_b, i, coef2);
            result->func->sum(coef1, coef2, position);
            free(coef1); free(coef2);
        }
    } else {
        result = NULL;
    }

    return result;//возвращает адрес на линейную форму в которой лежит сумма
}
struct line_form* dif_lineform(struct line_form *a, struct line_form *b){
    struct line_form *result, *new_a, *new_b;
    if (a->func == b->func) {
        if (a->dimension > b->dimension) {
            new_a = a;
            new_b = increase_lineform(b, a->dimension);
        }else if(b->dimension > a->dimension) {
            new_a = increase_lineform(a, b->dimension);
            new_b = b;
        }else{
            new_a = a;
            new_b = b;
        }//получаются две линейные формы одинаковой длины

        void *coefficient;
        coefficient = (void*) malloc(new_a->element_size * new_a->dimension);
        result = New_line_form(new_a->dimension, new_a->element_size, coefficient, new_a->func);
        //создние результирующей структуры

        void *position, *from;
        for (size_t i = 0; i < new_a->dimension; i++) {
            void *coef1 = malloc(a->element_size);
            void *coef2 = malloc(a->element_size);
            position = (void*)((int)result->coefficients + i * result->element_size);
            get_coefficient(new_a, i, coef1);
            get_coefficient(new_b, i, coef2);
            result->func->dif(coef1, coef2, position);
            free(coef1); free(coef2);
        }
    } else {
        result = NULL;
    }

    return result;//возвращает адрес на линейную форму в которой лежит разность
}
struct line_form* mult_lineform(struct line_form *a, void *b){

    void *coefficients, *position, *from;
    coefficients = malloc(a->element_size * a->dimension);
    struct line_form *result = New_line_form(a->dimension, a->element_size, coefficients, a->func);

    for(int i = 0; i < result->dimension; i++){
        position = (void*)((int)result->coefficients + i * result->element_size);
        from = (void*)((int)a->coefficients + i * result->element_size);
        a->func->scalar_mult(from, b, position);
    }

    return result;
}
void* value_lineform_on_args(struct line_form *a, void* arguments){

    void *coefficients, *position, *from, *b;
    coefficients = malloc(a->element_size * a->dimension);
    struct line_form *result = New_line_form(a->dimension, a->element_size, coefficients, a->func);

    from = (void*)((int)a->coefficients + 0 * result->element_size);
    set_coefficient(result, 0, from);

    for(int i = 1; i < result->dimension; i++){
        position = (void*)((int)result->coefficients + i * result->element_size);
        from = (void*)((int)a->coefficients + i * result->element_size);
        b = (void*)((int)arguments + (i - 1) * a->element_size);
        a->func->scalar_mult(from, b, position);
    }
    //сейчас здесь линейная форма, у которой на местах не только коэффициенты, но и значения при них

    void* value;
    value = malloc(a->element_size);
    value = result->coefficients;

    for(int i = 1; i < result->dimension; i++){
        void* coef_mult_arg = malloc(a->element_size);
        get_coefficient(result, i, coef_mult_arg);
        result->func->sum(value, coef_mult_arg, value);
        free(coef_mult_arg);
    }

    return value;
}