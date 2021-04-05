#include <malloc.h>

struct complex{
    float real_part;
    float im_part;
};

struct complex* sum_of_complex(struct complex *a, struct complex *b);//сумма комплексных чисел
struct complex* dif_of_complex(struct complex *a, struct complex *b);//разность комплексных чисел
struct complex* scalar_mult_of_complex(struct complex *a, struct complex *b);//умножение комплексного числа
struct complex* invers_of_complex(struct complex *a);//умножает число на -1
void print_of_complex(struct complex *a);//вывод комплексных чисел
