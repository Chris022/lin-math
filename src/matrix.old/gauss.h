#ifndef LIN_GAUSS_H
#define LIN_GAUSS_H

#include "matrix.h"

int lin_gauss_row_switching(lin_matrix_t *mp, int i1, int i2);
int lin_gauss_row_multiplication(lin_matrix_t *mp, int i, M_TYPE lambda);
int lin_gauss_row_addition(lin_matrix_t *mp, int i1, int i2, M_TYPE lambda);

lin_matrix_t * lin_gauss_elimination_algo(lin_matrix_t *mp);



#endif