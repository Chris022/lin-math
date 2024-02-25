#ifndef FILE_DIMENSION_SEEN
#define FILE_DIMENSION_SEEN

typedef struct
{
    int axis;
    int* dimensions;
} dimension;


dimension* dim_init(int axis, ...);

dimension* dim_cpy(dimension* dim);

int dim_cmp(dimension* dim1, dimension* dim2);

void dim_log(dimension* dimension);

int dim_flatten(dimension* dim);


#endif