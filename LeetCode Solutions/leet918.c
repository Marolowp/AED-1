#include <stdio.h>
#include <stdlib.h>

int comparar (const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int maxSubarraySumCircular(int *nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comparar);
    int soma = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] > 0){
            soma += nums[i];
        }
    }
    return soma;
    
}

int main(){
    int nums[3] = {5,-3,5};
    int numsSize = 3;

    int result = maxSubarraySumCircular(nums, numsSize);

    printf("%d", result);
}