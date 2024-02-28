#include "matrix/matrix.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void printm(lin_matrix_t *mp){
    int n_digits[mp->n];

    for(int j = 0; j < mp->n; j++){
        n_digits[j] = 0;
        for(int i = 0; i < mp->m; i++){
            int count = snprintf(NULL, 0, "%i", lin_get_matrix(mp, i+1 , j+1));
            if(count > n_digits[j]){
                n_digits[j] = count;
            }
            
        }
    }

    for(int i = 1; i <= mp->m; i++){
        printf("|");
        for(int j = 1; j <= mp->n; j++){
            printf(" %*i ",n_digits[j-1], lin_get_matrix(mp, i , j));
        }
        printf("|\n");
    }
}


void main(){

    lin_matrix_t *mat_1 = lin_matrix_unit(2);
    lin_matrix_t *mat_2 = lin_matrix_clone(mat_1);

    lin_set_matrix(mat_1,1,1,100);

    lin_matrix_t *mat_3 = lin_matrix_add(mat_1,mat_2);
    lin_matrix_t *mat_4 = lin_matrix_smult(mat_3,2);
    lin_matrix_t *mat_5 = lin_matrix_mmult(mat_1, mat_4);

    printm(mat_1);
    printm(mat_2);
    printm(mat_3);
}