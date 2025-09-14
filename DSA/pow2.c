#include <stdio.h>
#include <stdbool.h>

bool pow2(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if ( pow2(n)==1) {
        printf("%d is a power of 2", n);
    }
    else {
        printf("%d is not a power of 2 ", n);
    }
    return 0;
}