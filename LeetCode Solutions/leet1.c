#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *arr = malloc(sizeof(int)* 2);
    *returnSize = 2; 
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target){
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    return NULL;
}
int main(){
    int nums[4] = {2, 5, 11, 15};
    int numsSize = 4;
    int target = 9; 
    int returnSize[2] = {0,0};

    int* result = twoSum(nums, numsSize, target, returnSize);
    
    if(result != NULL){
        printf("%d, %d", result[0], result[1]);
        free(result);
    }

    return 0;
}