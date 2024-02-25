#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "array.h"



int arr_flat_index(dimension* dim, va_list args){
    int flattened_index = 0;

    for (int i = 0; i < dim->axis; ++i) {
        int index = va_arg(args, int);
        for(int j = i+1; j < dim->axis; j++){
            index *= dim->dimensions[j];
        }
        flattened_index += index;
    }

    // TODO Improve
    /*if(flattened_index > arr_len(dim)){
        printf("ERROR. Index out of bounds");
        exit(EXIT_FAILURE);
    }*/

    return flattened_index;
}

array* arr_init(dimension* dim){
    // calculate flattened length of array.
    int length = dim_flatten(dim);
    
    int* elements = malloc(sizeof(int)*length);
    array* arr = malloc(sizeof(array));

    arr->dim = dim;
    arr->elements = elements;

    return arr;
}

array* arr_vec(int len, int* elements){
    dimension* dim = dim_init(1, len );

    int* els = malloc(sizeof(int)*len);
    memcpy(els, elements, sizeof(int)*len);
    array* arr = malloc(sizeof(array));

    arr->dim = dim;
    arr->elements = els;
    return arr;
}

array* arr_cpy(array* arr){
    int length = dim_flatten(arr->dim);

    array* arr_n = malloc(sizeof(array));
    memcpy(arr_n, arr, sizeof(array));

    int* elements = malloc(sizeof(int)*length);
    memcpy(elements, arr->elements, sizeof(int)*length);

    return arr_n;
}




int arr_get(array* arr, ...){
    va_list args;

    va_start(args, arr);
    int flattened_index = arr_flat_index(arr->dim, args);
    va_end(args);

    return arr->elements[flattened_index];
}

void arr_set(array* arr, int value, ...){
    va_list args;

    va_start(args, value);
    arr->elements[arr_flat_index(arr->dim, args)] = value;
    va_end(args);
}

array* add_array(array* arr1, array* arr2){
    //check if dimensions are the same
    if(!dim_cmp(arr1->dim, arr2->dim)){
        printf("ERROR. Cannot add arrays of different dimension.");
    }

    array* arr3 = arr_cpy(arr1);

    for(int i = 0; i < dim_flatten(arr3->dim); i++){
        arr3->elements[i] = arr1->elements[i] + arr2->elements[i];
    }

}

void arr_log(array* arr){
    printf("[");
    for(int i = 0; i < dim_flatten(arr->dim); i++){
        printf(" %i ",arr->elements[i]);
    }
    printf("]\n");
}
