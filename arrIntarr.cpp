#include <cstdlib>

int arrint(int* arr, size_t size){
    int ans = 0;
    for(int i = 0; i<size; i++){
        ans*=10;
        ans+=*(arr++);
    }
    return ans;
}

int* intarr(int num, int z){
    int* arr = (int*)malloc(sizeof(int) * z);
    for (int i = 0; i < z; i++) {
        *(arr++) = num % 10;
        num /= 10;
    }

    reverse(arr - z, arr);

    return arr - z;
}


