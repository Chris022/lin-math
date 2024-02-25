#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "dimension.h"

dimension* dim_init(int axis, ...){
    if(axis < 0){
        printf("ERROR. Can not create 0 Dimension.");
        exit(EXIT_FAILURE);
    }
    dimension * d = malloc(sizeof(dimension));

    int* dimensions = malloc(sizeof(int)*axis);

    va_list args;

    va_start(args, axis);

    for (int i = 0; i < axis; ++i) {
        dimensions[i] = va_arg(args, int);
    }

    va_end(args);

    d->axis = axis;
    d->dimensions = dimensions;
}

dimension* dim_cpy(dimension* dim){
    dimension* dim_n = malloc(sizeof(dimension));
    memcpy(dim_n, dim,sizeof(dimension));

    int* dimensions = malloc(sizeof(int)*dim->axis);
    memcpy(dimensions, dim->dimensions,sizeof(int)*dim->axis);
    dim_n->dimensions = dimensions;

    return dim_n;
}

int dim_cmp(dimension* dim1, dimension* dim2){
    if(dim1->axis != dim2->axis){
        return -1;
    }

    for(int i = 0; i < dim1->axis; i++){
        if(dim1->dimensions[i] != dim2->dimensions[i]) return -1;
    }
    return 0;
}

void dim_log(dimension* dimension){
    printf("(");
    for(int i = 0; i < dimension->axis; i++){
        printf(" %i ", dimension->dimensions[i]);
    }
    printf(")\n");
}

int dim_flatten(dimension* dim){
    int length = 1;
    for(int i = 0; i < dim->axis; i++){
        length *= dim->dimensions[i];
    }
    return length;
}

