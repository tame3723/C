#include <stdio.h>

void Count(char str[]){
    int c=1;
    for (int i = 0; str[i]!= '\0'; i++){
        if (str[i] == ' '){
            c++;
        }
    }
    printf("Number of words : %d ", c);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    Count(str);
    return 0;
}