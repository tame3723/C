#include <stdio.h>
#include <ctype.h>
void Up(char str[]){
    for (int i = 0; str[i]!= '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}


int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    Up(str);
    printf("Uppercase string is : %s", str);
    return 0;
}