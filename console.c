#include "console.h"
#include "stdio.h"
#include <stdlib.h>


struct line_form* Create_int_line_form(){
    int demension;
    printf("Введите размерность линейной формы:\n");
    scanf("%d", &demension);

    void* coefficients;
    coefficients = (int*) malloc(sizeof(int) * demension);
    for(int i = 0; i < demension; i++){
        printf("Введите %d коэффициент линейной формы:", i);
        scanf("%d", (int*)coefficients + i);
    }

    struct line_form *result = New_line_form((size_t)demension, (size_t)sizeof(int), coefficients, &int_functions);
    return result;
}
struct line_form* Create_float_line_form(){
    int demension;
    printf("Введите размерность линейной формы:\n");
    scanf("%d", &demension);

    void* coefficients;
    coefficients = (float*) malloc(sizeof(float) * demension);
    for(int i = 0; i < demension; i++){
        printf("Введите %d коэффициент линейной формы:", i);
        scanf("%f", (float*)coefficients + i);
    }

    struct line_form *result = New_line_form((size_t)demension, (size_t)sizeof(float), coefficients, &float_functions);
    return result;
}
struct line_form* Create_complex_line_form(){
    int demension;
    printf("Введите размерность линейной формы:\n");
    scanf("%d", &demension);

    void* coefficients;
    coefficients = (struct complex*) malloc(sizeof(struct complex) * demension);
    for(int i = 0; i < demension; i++){
        printf("Введите действительную часть %d коэффициента линейной формы:", i);
        scanf("%f", &(((struct complex*)coefficients + i)->real_part));
        printf("Введите мнимую часть %d коэффициента линейной формы:", i);
        scanf("%f", &(((struct complex*)coefficients + i)->im_part));
    }

    struct line_form *result = New_line_form((size_t)demension, (size_t)sizeof(struct complex), coefficients, &complex_functions);
    return result;
}

void* Create_int_arguments(size_t dimension){
    void* arguments;
    arguments = (int*) malloc(sizeof(int) * dimension);
    for (int i = 0; i < dimension; i++){
        printf("Введите %d аргумент линейной формы:", i);
        scanf("%d", (int*)arguments + i);
    }

    return arguments;
}
void* Create_float_arguments(size_t demension){
    void* arguments;
    arguments = (float*) malloc(sizeof(float) * demension);
    for (int i = 0; i < demension; i++){
        printf("Введите %d аргумент линейной формы:", i);
        scanf("%f", (float*)arguments + i);
    }

    return arguments;
}
void* Create_complex_arguments(size_t dimension){
    void* arguments;
    arguments = (struct complex*) malloc(sizeof(struct complex) * dimension);
    for(int i = 0; i < dimension; i++){
        printf("Введите действительную часть %d коэффициента линейной формы:", i);
        scanf("%f", &(((struct complex*)arguments + i)->real_part));
        printf("Введите мнимую часть %d коэффициента линейной формы:", i);
        scanf("%f", &(((struct complex*)arguments + i)->im_part));
    }

    return arguments;
}

void output_line_form(struct line_form* outputed){
    void *position;
    printf("Linear form -> [");
    for (int i = 0; i < outputed->dimension - 1; i++){
        position = (void*)((int)outputed->coefficients + i * outputed->element_size);
        outputed->func->print(position);
        printf(", ");
    }
    position = (void*)((int) outputed->coefficients + ((outputed->dimension) - 1) * outputed->element_size);
    outputed->func->print(position);
    printf("]");
}
void output_value_on_arguments(void* value,int type){
    switch (type) {
        case 1:
            printf("%d", *(int*)value);
            break;
        case 2:
            printf("%f", *(float*)value);
            break;
        case 3:
            print_of_complex(value);
            break;
    }
}

void first_page() {
    int type, operation_type, wish;
    printf("Выберите цифру соответствующую типу линейных форм с которыми вы хотите работать:\n"
           "\t1: Если хотите использовать int\n"
           "\t2: Если хотите использовать float\n"
           "\t3: Если хотите использовать complex\n"
           "Введите число: ");
    scanf("%d", &type);

    printf("Выберите какую опреацию вы хотите совершить с линейными формами:\n"
           "\t1: Если хотите сложить линейные формы\n"
           "\t2: Если хотите вычесть одну линейную форму из другой\n"
           "\t3: Если хотите умножить линейную форму на скаляр\n"
           "\t4: Если хотите посчитать значение линейной формы на заданных знаниях аргументов\n"
           "Введите число: ");
    scanf("%d", &operation_type);
    //TODO здесь мы определим тип линейных форм и нужную операцию с ними

    struct line_form *a, *b;
    if (operation_type == 1 || operation_type == 2) {
        printf("Давайте для этого создадим две линейные формы\n");
        switch (type) {
            case 1:
                printf("Коэффициенты первой линейной формы->\n");
                a = Create_int_line_form();
                printf("Коэффициенты второй линейной формы->\n");
                b = Create_int_line_form();
                break;
            case 2:
                printf("Коэффициенты первой линейной формы->\n");
                a = Create_float_line_form();
                printf("Коэффициенты второй линейной формы->\n");
                b = Create_float_line_form();
                break;
            case 3:
                printf("Коэффициенты первой линейной формы->\n");
                a = Create_complex_line_form();
                printf("Коэффициенты второй линейной формы->\n");
                b = Create_complex_line_form();
                break;
        }
    }else if((operation_type == 3 || operation_type == 4)){
        printf("Давайте для этого создадим одну линейную форму\n");
        switch (type) {
            case 1:
                printf("Коэффициенты линейной формы->\n");
                a = Create_int_line_form();
                break;
            case 2:
                printf("Коэффициенты линейной формы:\n");
                a = Create_float_line_form();
                break;
            case 3:
                printf("Коэффициенты линейной формы:\n");
                a = Create_complex_line_form();
                break;
        }
    }//TODO здесь мы создадим необходимые для операций линейные формы

    printf("Хотите посмотреть на то, что ввели?\n"
           "\t1: Хочу\n"
           "\t2: Не хочу\n");
    scanf("%d", &wish);

    if ((operation_type == 1 || operation_type == 2) && wish == 1){
        output_line_form(a);
        printf("\n");
        output_line_form(b);
        printf("\n");
    }else if(((operation_type == 3 || operation_type == 4) && wish == 1)){
        output_line_form(a);
        printf("\n");
    }//TODO здесь просто предпросмотр того, что ввели

    struct line_form *c;
    c = (struct line_form*) malloc(sizeof(struct line_form));
    void* arguments;
    switch (operation_type) {
        case 1:
            printf("А вот и результат -> ");
            c = sum_lineform(a, b);
            output_line_form(c);
            destroy_lineform(a);
            destroy_lineform(b);
            break;
        case 2:
            printf("А вот и результат -> ");
            c = dif_lineform(a, b);
            output_line_form(c);
            destroy_lineform(a);
            destroy_lineform(b);
            break;
        case 3:
            int scalar_int;
            float scalar_float;
            struct complex scalar_complex;
            printf("Введите коэффициент, на который будем умножать:\n");
            switch (type) {
                case 1:
                    scanf("%d", &scalar_int);
                    c = mult_lineform(a, (void*)&scalar_int);
                    break;
                case 2:
                    scanf("%f", &scalar_float);
                    c = mult_lineform(a, (void*)&scalar_float);
                    break;
                case 3:
                    printf("Действительную часть:");
                    scanf("%f", &(scalar_complex.real_part));
                    printf("Мнимую часть:");
                    scanf("%f", &(scalar_complex.im_part));
                    c = mult_lineform(a, (void*)&scalar_complex);
                    break;
            }
            printf("А вот и результат -> ");
            output_line_form(c);
            destroy_lineform(a);
            destroy_lineform(c);
            break;
        case 4:
            printf("Давайте введем аргументы линейной формы\n");
            switch(type){
                case 1:
                    arguments = Create_int_arguments(a->dimension - 1);
                    break;
                case 2:
                    arguments = Create_float_arguments(a->dimension - 1);
                    break;
                case 3:
                    arguments = Create_complex_arguments(a->dimension - 1);
                    break;
            }
            void* value = value_lineform_on_args(a, arguments);
            printf("А вот и результат -> ");
            output_value_on_arguments(value, type);
            destroy_lineform(a);
            free(arguments);
            break;
    }
}



