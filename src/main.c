#include "matrix/matrix.h"

#include <stdlib.h>
#include <stdio.h>



void main(){

    lin_matrix_t *mat_1 = lin_matrix_unit(2);
    lin_matrix_t *mat_2 = lin_matrix_clone(mat_1);

    lin_set_matrix(mat_1,1,1,100);

    lin_matrix_t *mat_3 = lin_matrix_add(mat_1,mat_2);

    printf("%i\n", lin_get_matrix(mat_1,1,1));
    printf("%i\n", lin_get_matrix(mat_2,1,1));
    printf("%i\n", lin_get_matrix(mat_3,1,1));
}