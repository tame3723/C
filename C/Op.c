#include <stdio.h>

int main(){
    int a;
    int b;
    printf("Enter a number:");
    scanf("%d",&a);
    printf("Enter second number:");
    scanf("%d",&b);
    printf("The first number is %d\n",a);
    printf("The second number is %d\n",b);

    if(a==b){
        printf("The numbers are equal\n");
    }
    else
    {
        printf("The numbers are not equal\n");
    }
    
    if(a>b){
        printf("%d",a);
        printf(" is greater than %d\n",b);
    }
    else if (b>a){
        printf("%d",b);
        printf(" is greater than %d\n",a);
    }
    if(a>b && a>100){
        printf("%d",a);
        printf(" is a large number");
    }
}