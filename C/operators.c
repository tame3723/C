#include <stdio.h>

int main(){
    float a;
    float b;
    float c;
    a=5;
    b=8;
    if(a<b){
        printf("The Greater number is %f\n",b);
    }
    else{
        printf("The greater number is %f\n",a);
    }
    c=a+b;
    printf("the sum is: %f\n",c);
    printf("sum= %f",a+b);
    return 0;
}

