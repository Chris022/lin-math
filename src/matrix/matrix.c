#include "matrix.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>

lin_matrix_t * lin_matrix(size_t m, size_t n, M_TYPE elements[m][n]){
    lin_matrix_t *mat = malloc(sizeof(lin_matrix_t)+sizeof(M_TYPE[m][n]));

    assert(mat != NULL);

    mat->m = m;
    mat->n = n;
    memcpy(mat->elements,elements,sizeof(M_TYPE[m][n]));

    return mat;
}

lin_matrix_t *lin_matrix_zero(size_t m, size_t n){
    M_TYPE elements[m][n];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++){
            elements[i][j] = 0;
        }
    }

    return lin_matrix(m, n, elements);
}

lin_matrix_t *lin_matrix_unit(size_t n){

    M_TYPE elements[n][n];

    memset(elements, 0, sizeof(elements));

    for(int i = 0; i < n; i++) {
        elements[i][i] = 1;
    }

    return lin_matrix(n, n, elements);
}

lin_matrix_t *lin_matrix_clone(lin_matrix_t *matrix){
    lin_matrix_t *mat = malloc(sizeof(lin_matrix_t)+sizeof(M_TYPE[matrix->m][matrix->n]));

    memcpy(mat,matrix,sizeof(lin_matrix_t)+sizeof(M_TYPE[matrix->m][matrix->n]));

    return mat;
}

int lin_get_matrix(lin_matrix_t *mp, int i, int j){
    //TODO: Check bounds
    return mp->elements[LIN_1D_MATRIX(mp, i, j)];
}

int lin_set_matrix(lin_matrix_t *mp, int i, int j, M_TYPE value){
    mp->elements[LIN_1D_MATRIX(mp, i, j)] = value;
}


lin_matrix_t *lin_matrix_add(lin_matrix_t *mp1, lin_matrix_t *mp2){
    //TODO: Check sizes
    M_TYPE elements[mp1->m][mp1->n];

    LIN_LOOP_MATRIX(mp1){
        elements[i-1][j-1] = lin_get_matrix(mp1, i, j) 
                                + lin_get_matrix(mp2, i, j);
    }

    return lin_matrix(mp1->m, mp1->n, elements);
}

lin_matrix_t *lin_matrix_smult(lin_matrix_t *mp, M_TYPE scaler){
    
    M_TYPE elements[mp->m][mp->n];


    LIN_LOOP_MATRIX(mp){
        elements[i-1][j-1] = lin_get_matrix(mp, i, j) * scaler;
    }

    return lin_matrix(mp->m, mp->n, elements);
}

lin_matrix_t *lin_matrix_mmult(lin_matrix_t *mp1, lin_matrix_t *mp2){
    //TODO: Check sizes
    M_TYPE elements[mp1->m][mp2->n];

    for(int i = 1; i <= mp1->m; i++) {
        for(int j = 1; j <= mp2->n; j++){
            elements[i-1][j-1] = 0;
            for(int x = 1; x <= mp1->n; x++){
                elements[i-1][j-1] += lin_get_matrix(mp1, i, x) * lin_get_matrix(mp2, x, j);
            }
        }
    }

    return lin_matrix(mp1->m, mp2->n, elements);
}