#include <stdio.h>

int main(){
    long long a =99999999;
    printf("The size of an integer: %ld\n", sizeof(int)); /*%z is special type for sizeof function. %zu stands for unassigned %z.*/
    printf("The size of a is: %ld\n", sizeof(a));
    return(0);
}