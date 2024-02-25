#ifndef LIN_ARRAY_H
#define LIN_ARRAY_H

#include "dimension.h"
#include <stdarg.h>

typedef struct {
    dimension* dim;
    int* elements;
} lin_array_t;


int arr_flat_index(dimension* dim, va_list args);


// Constructors
array* arr_init(dimension* dim);

array* arr_vec(int len, int* elements);
array* arr_matrix(int len, int** elements);
array* arr_tensor(int len, int*** elements);


// Methods
array* arr_cpy(array* arr);

//OTHER FUNCTIONS
int arr_get(array* arr, ...);

void arr_set(array* arr, int value, ...);

array* add_array(array* arr1, array* arr2);

void arr_log(array* arr);

#endif
