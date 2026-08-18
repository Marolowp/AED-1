#include <stdio.h>
#include <stdlib.h>

int comparar(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), comparar); //organiza em ordem crescente

    int counter = 0;    //contador de numeros solitarios

    int* arr = NULL;
    int j = 0;    
    for (int i = 0; i < numsSize; i++){
        if (i == numsSize - 1 || nums[i] != nums[i+1]){
            arr = realloc(arr, sizeof(int) * (counter+1));
            arr[j] = nums[i];
            counter++;
            j++;
        }
        else{
            i++;
        }
    }

    *returnSize = counter;
    return arr;
}

int main(){
    int nums[6] = {1,2,1,3,2,5};
    int numsSize = 6;
    int returnSize[2] = {0,0};

    int* result = singleNumber(nums, numsSize, returnSize);

    for(int i = 0; i < 2; i++){
        printf("%d ", result[i]);
    }
    free(result);

}