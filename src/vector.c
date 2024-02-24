#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* elements;
    char dimension;
} vector;


vector* init_vector(char dimension){
    int* elements = malloc(sizeof(int)*dimension);
    vector* vec = malloc(sizeof(vector));
    vec->elements = elements;
    vec->dimension = dimension;

    return vec;
}

void vector_update(vector* vec, char index, int value){
    if(index > vec->dimension || index < 1){
        printf("ERROR! Could not update Vector: Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
    vec->elements[index-1] = value;
}

int get_vector(vector* vec, char index){
        if(index > vec->dimension || index < 1){
        printf("ERROR! Could not get Vector: Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }
    return vec->elements[index-1];
}


vector* add_vectors(vector* vec1, vector* vec2){
    if(vec1->dimension != vec2->dimension){
        printf("ERROR! Could not add Vectors: Non matching Dimension!\n");
        exit(EXIT_FAILURE);
    }
    vector* vec3 = init_vector(vec1->dimension);
    for(int i = 1; i <= vec3->dimension; i++){
        int sum = get_vector(vec1, i) + get_vector(vec2, i);
        vector_update(vec3, i, sum);
    }
    return vec3;
}

vector* multiply_vector(vector* vec, int scaler){
    vector* vec_m = init_vector(vec->dimension);
    for(int i = 1; i <= vec_m->dimension; i++){
        vector_update(vec_m, i, get_vector(vec, i)*scaler);
    }
    return vec_m;
}

void print_vector(vector* vec){
    printf("(");
    for(int i = 0; i < vec->dimension; i++){
        printf(" %i ", vec->elements[i]);
    }
    printf(")\n");
}

void main(){
    vector* v1 = init_vector(10);
    vector_update(v1, 1, 100);
    
    vector* v1_ = multiply_vector(v1, 2);

    vector* v2 = init_vector(10);
    vector_update(v2, 1, 100);

    vector* v3 = add_vectors(v1_, v2);

    print_vector(v3);
}