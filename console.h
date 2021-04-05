#include "linearform.h"

struct line_form* Create_int_line_form();//возвращает указатель на полноценную int линейную форму
struct line_form* Create_float_line_form();//возвращает указатель на полноценную float линейную форму
struct line_form* Create_complex_line_form();//возвращает указатель на полноценную complex линейную форму

void* Create_int_arguments(size_t dimension);//возвращает указатель на массив аргументов int
void* Create_float_arguments(size_t dimension);//возвращает указатель на массив аргументов float
void* Create_complex_arguments(size_t dimension);//возвращает указатель на массив аргументов complex

void output_line_form(struct line_form*);
void output_value_on_arguments(void* value, int type);

void first_page();

