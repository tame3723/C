#include <stdio.h>

int main(){
    int i;
    int sum;
    int num;
    for(i=0;i<=10;i++){
        printf("Enter number \n");
        scanf("%d",&num);
        if(num<0){
            printf("You have entered a negative number");
            break;
        }
        sum+=num;
    }
    printf("%d",sum);
    return 0;
}