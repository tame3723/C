#include <stdio.h>

int main(){
    int a=5;
    int b=86;
    int c=55;
    int d=445;
    int l;
    l=a>b? (a>c? (a>d)? a:d : c>d ? c:d) : (b>c? (b>d)? b:d : (d>c)? d:c);
    printf("%d",l);
    return 0;
}