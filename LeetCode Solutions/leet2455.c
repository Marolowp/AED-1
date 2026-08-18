#include <stdio.h>

int averageValue (int *nums, int numsSize){
    float value = 0;
    int counter = 0;

    for (int i = 0; i < numsSize; i++){
        if (nums[i]%3 == 0 && nums[i]%2 == 0){
            value += nums[i];
            counter++;
        }
    }

    if(value == 0 && counter == 0) return 0;
    
    value = value / counter;

    int integerPart = (int)value;
    return integerPart;
}

int main(){
    int nums[6] = {1,3,6,10,12,15};
    int numsSize = 6;

    int result = averageValue(nums, numsSize);

    printf("%d", result);
}