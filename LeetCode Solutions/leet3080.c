#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int x = *(const int*) a;
    int y = *(const int*) b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int maxTotalReward(int* rewardValues, int rewardValuesSize){
    qsort(rewardValues, rewardValuesSize, sizeof(int), compare);

    int x = 0;
    for (int i = 0; i < rewardValuesSize; i++){
        for ()
    }
    return x;
}

int main(){
    int rewardValues[5] = {1,6,4,3,2};
    int rewardValuesSize = 5;

    int result = maxTotalReward(rewardValues, rewardValuesSize);

    printf("%d", result);
}