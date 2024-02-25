#include "dimension.h"
#include "array.h"

int main(){
    dimension* dim = dim_init(2, 2, 2);
    dim_log(dim);

    int els[2] = {1, 2};
    array* arr = arr_vec(2,els);
    arr_log(arr);
}