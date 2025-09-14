#include <stdio.h>
void missingno(int arr[], int n, int max){
    int present[max+1];
    for(int i=0;i<=max;i++){
        present[i]=0;
    }
    for(int i=0;i<n;i++){
        present[arr[i]]=1;
    }
    for(int i=1;i<=max;i++){
        if(present[i]==0){
            printf("Missing number is: %d\n",i);
        }
    }
}
int main() {
    int arr[] = {1, 2, 4, 6, 3, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 10;
    missingno(arr, n, max);
    return 0;
}