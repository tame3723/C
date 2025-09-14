#include <stdio.h>

int main() {
    int n, i;
    // Accept the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n]; // Declare an array of size n
    // Accept n integers
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the array elements
    printf("Array elements are: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Find the largest and smallest elements
    int largest = arr[0], smallest = arr[0], sum = 0;
    
    for(i = 0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
        sum += arr[i];
    }
    
    // Compute the average
    float average = (float)sum / n;
    
    // Print results
    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of all elements: %d\n", sum);
    printf("Average of all elements: %.2f\n", average);
    
    return 0;
}