#include <stdio.h>
void rot(int arr[], int k, int n){
    for (int i = 0; i < k; i++){
        int temp = arr[0];
        int c=0;
        for(int j = 0; j < n; j++){
            arr[j] = arr[j + 1];
            c++;
        }
        arr[c] = temp;
    }
}
void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int k;
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, n);
    printf("Enter rotation: ");
    scanf("%d", &k);
    rot( arr, k, n);
    printArray(arr, n);
    return 0;
}