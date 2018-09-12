#include <stdio.h>
#include <string.h>

int main() {
    char inputStr[16];
    scanf("%s", inputStr);
    for(int i;i<strlen(inputStr);i++) {
        if(65 <= inputStr[i] && inputStr[i] <= 90) {
            inputStr[i] += 32;
        } else {
            inputStr[i] -=32;
        }
    }
    printf("%s\n", inputStr);
    return 0;
}

