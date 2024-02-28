#ifndef LIN_ARRAY_H
#define LIN_ARRAY_H

#include <stddef.h>

//init.c

#define M_TYPE float

typedef struct
{
    size_t m;
    size_t n;

    M_TYPE elements[];
} lin_matrix_t;


lin_matrix_t *lin_matrix(size_t m, size_t n, M_TYPE[m][n]);

lin_matrix_t *lin_matrix_zero(size_t m, size_t n);

lin_matrix_t *lin_matrix_unit(size_t n);

lin_matrix_t *lin_matrix_clone(lin_matrix_t *matrix);


int lin_get_matrix(lin_matrix_t *mp, int i, int j);
int lin_set_matrix(lin_matrix_t *mp, int i, int j, M_TYPE value);

#define LIN_1D_MATRIX(mp, i, j) ((i-1)*(mp)->m+(j-1)) // converts 2D Coordinates to 1D

#define LIN_LOOP_MATRIX(mp) \
    for(int i = 1; i <= mp->m; i++) for(int j = 1; j <= mp->n; j++) \



//basic.c

lin_matrix_t *lin_matrix_add(lin_matrix_t *mp1, lin_matrix_t *mp2);
lin_matrix_t *lin_matrix_smult(lin_matrix_t *mp, M_TYPE scaler);
lin_matrix_t *lin_matrix_mmult(lin_matrix_t *mp1, lin_matrix_t *mp2);


#endif