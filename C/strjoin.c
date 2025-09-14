#include<stdio.h>
int main(){
    char a[5]="hello";
    char b[5]="World";
    char c[11];
    for (int i=0;i<5;i++){
        c[i]=a[i];
        c[6+i]=b[i];
    printf("%s \n",c);
    }
    return 0;
}