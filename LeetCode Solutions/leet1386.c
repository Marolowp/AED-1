#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int missingInteger(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = nums[numsSize - 1] + 1;
    return result;
}

int main(){
   int nums[5] = {1,2,3,2,5};
   int numsSize = 5;

   int result = missingInteger(nums, numsSize);

   printf("%d", result);
}