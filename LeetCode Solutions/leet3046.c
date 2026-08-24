#include <stdio.h>
#include <stdbool.h>

bool isPossibleToSplit(int* nums, int numsSize) {
    int counter = 1;
    int aux = 0;
    for (int i = 0; i < numsSize; i++){
        aux = nums[i];
        counter = 0;
        for (int j = i + 1; j < numsSize; j++){
            if (aux == nums[j]){
                counter++;
            } 
            if (counter >= 2){
              return false;  
            } 
        }
    }
    return true;
}

int main(){
    int nums[10] = {6,1,10,6,4,7,7,9,6,9};
    int numsSize = 10;
    
    bool resultado = isPossibleToSplit(nums, numsSize);

    printf("%s", resultado ? "true" : "false");
}