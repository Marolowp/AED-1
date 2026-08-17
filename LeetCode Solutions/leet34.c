#include <stdio.h>
#include <stdlib.h>

int *searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *arr = malloc(sizeof(int) * 2);
    *returnSize = 2;
    int i = 0;
    arr[0] = -1;
    arr[1] = -1;
    for (i = 0; i < numsSize; i++){
        if(nums[i] == target){
            arr[0] = i;
            break;
        }
    }
    
    for(i = i + 1; i < numsSize; i++){
        if (nums[i] == target){
            arr[1] = i;
            break;
        }
    }

    return arr;
    
}
int main(){
    int nums[6] = {5, 7, 7, 8 , 8, 10};
    int numsSize = 6;
    int target = 8;
    int returnSize [2] = {0, 0};
    
    int *result = searchRange(nums, numsSize, target, returnSize);

    printf("%d, %d", result[0], result[1]);
    free(result);
}