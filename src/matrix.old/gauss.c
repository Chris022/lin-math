#include "matrix.h"

#include <stdio.h>

int lin_gauss_row_switching(lin_matrix_t *mp, int i1, int i2){
    int buffer = 0;

    for(int j = 1; j <= mp->n; j++){
        buffer = lin_get_matrix(mp, i1, j);
        lin_set_matrix(mp, i1, j, lin_get_matrix(mp, i2, j));
        lin_set_matrix(mp, i2, j, buffer);
    }
}


int lin_gauss_row_multiplication(lin_matrix_t *mp, int i, M_TYPE lambda){
    if(lambda == 0){
        printf("ERROR. Can only multiply by non zero value.");
        return -1;
    }

    for(int j = 1; j <= mp->n; j++){
        lin_set_matrix(mp, i, j, lin_get_matrix(mp, i, j)*lambda);
    }
}


int lin_gauss_row_addition(lin_matrix_t *mp, int i1, int i2, M_TYPE lambda){
    for(int j = 1; j <= mp->n; j++){
        lin_set_matrix(mp, i2, j,  lin_get_matrix(mp, i2, j) + lin_get_matrix(mp, i1, j)*lambda);
    }
}

lin_matrix_t * lin_gauss_elimination_algo(lin_matrix_t *mp){
    for(int i = 1; i <= mp->m; i++){
        //Step 1: Check if element is 0 and if it is, swap row with last row
        //  Repeat until element is not 0 anymore
        while(lin_get_matrix(mp, i, i) == 0){
            //TODO: Swap

        }

        //Step 2: Now for every row below the current one, let e be the
        // current Element and a the current element in the row.
        // Subtract a/e * current row from the row
        int e = lin_get_matrix(mp, i, i);
        for(int i_ = i+1; i_ <= mp->m; i_++){
            int a = lin_get_matrix(mp, i_, i);
            lin_gauss_row_addition(mp, i, i_, (M_TYPE)-a/e);
        }

    }

}