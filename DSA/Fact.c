#include<stdio.h>
int fact(int n){
    if (n==1){
        return 1;
    }
    else if (n==0)
    {
        return 1;
    }
    else{
        return fact(n-1) * n;
    }
}

int main(){
    int a;
    printf("Enter number to print factorial");
    scanf("%d", &a);
    fact(a);
    printf("%d", fact(a));
    return 0;
}