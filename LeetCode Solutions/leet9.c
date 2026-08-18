#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x < 0) return false;

    char str[20];
    int len = snprintf(str, sizeof(str), "%d", x);

    for(int i = 0; i < len / 2; i++){
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}
int main(){
    int x = 121;
  
    bool result = isPalindrome(x);

    printf("%s", result ? "true" : "false"  );
}