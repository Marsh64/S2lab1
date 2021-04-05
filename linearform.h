#include "math.h"

struct line_form{
    size_t dimension;
    size_t element_size;
    void* coefficients;
    struct functions *func;
};

struct line_form* New_line_form(size_t dimension, size_t element_size, void* coefficients, struct functions *func);

//Работа с элементами линейной формы(декомкозиция)
void get_coefficient(struct line_form *a, size_t order, void* where);//отдает указатель на необходиый коэффицент
void set_coefficient(struct line_form *a, size_t order, void* value);//устанавливает коэффициент в нужную ячейку

//создает линейную форму большей длины
struct line_form* increase_lineform(struct line_form *a, size_t new_dimension);

//Функции с линейной формой
struct line_form* sum_lineform(struct line_form *a, struct line_form *b);
struct line_form* dif_lineform(struct line_form *a, struct line_form *b);
struct line_form* mult_lineform(struct line_form *a, void *b);
void* value_lineform_on_args(struct line_form *a, void* arguments);

//очищает линейную форму
void destroy_lineform(struct line_form *a);