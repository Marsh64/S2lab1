#include "mathComplex.h"
#include "stdio.h"

struct complex;

struct complex* sum_of_complex(struct complex *a, struct complex *b){
    struct complex *c = (struct complex *) malloc(sizeof(struct complex));
    c->im_part = a->im_part + b->im_part;
    c->real_part = a->real_part + b->real_part;
    return c;
}
struct complex* dif_of_complex(struct complex *a, struct complex *b){
    struct complex *c = (struct complex *) malloc(sizeof(struct complex));
    c->im_part = a->im_part - b->im_part;
    c->real_part = a->real_part - b->real_part;
    return c;
}
struct complex* scalar_mult_of_complex(struct complex *a, struct complex *b){
    struct complex *c = (struct complex *) malloc(sizeof(struct complex));
    c->im_part = a->im_part * b->real_part + a->real_part * b->im_part;
    c->real_part = a->real_part * b->real_part - a->im_part * b->im_part;
    return c;
}
struct complex* invers_of_complex(struct complex *a){
    struct complex *c = (struct complex *) malloc(sizeof(struct complex));
    c->im_part = a->im_part * -1;
    c->real_part = a->real_part * -1;
    return c;
}

void print_of_complex(struct complex *a){
    if (a->real_part != 0 && a->im_part > 0){
        printf("%.2f + i%.2f", a->real_part, a->im_part);
    }else if(a->real_part != 0 && a->im_part < 0){
        printf("%.2f - i%.2f", a->real_part, a->im_part * -1);
    }else if(a->real_part == 0 && a->im_part > 0){
        printf("i%.2f",a->im_part);
    }else if(a->real_part == 0 && a->im_part < 0){
        printf("-i%.2f",a->im_part * -1);
    }else if(a->real_part != 0 && a->im_part == 0){
        printf("%.2f", a->real_part);
    }else{
        printf("0");
    }
}

