#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high, long long *swaps) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            (*swaps)++;
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    (*swaps)++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, long long *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, swaps);
        quickSort(arr, low, pi - 1, swaps);
        quickSort(arr, pi + 1, high, swaps);
    }
}

long long insertionSort(int arr[], int size) {
    long long swaps = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
    }
    return swaps;
}

long long bubbleSort(int arr[], int size) {
    long long swaps = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }
    return swaps;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], temp[MAX], n = 0, choice;
    clock_t start, end;
    double time_taken;
    long long swap_count;

    FILE *fp = fopen("sort.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open sort.txt\n");
        return 1;
    }

    while (fscanf(fp, "%d", &arr[n]) == 1 && n < MAX) n++;
    fclose(fp);

    while (1) {
        for (int i = 0; i < n; i++) temp[i] = arr[i];

        printf("\n===== SORTING MENU =====\n");
        printf("1. Merge Sort\n2. Quick Sort\n3. Insertion Sort\n4. Bubble Sort\n5. Exit\n6. Benchmark All\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start = clock();
                mergeSort(temp, 0, n - 1);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time taken (Merge Sort): %.6f seconds\n", time_taken);
                printf("Swaps (Merge Sort): Not applicable\n");
                break;

            case 2:
                swap_count = 0;
                start = clock();
                quickSort(temp, 0, n - 1, &swap_count);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time taken (Quick Sort): %.6f seconds\n", time_taken);
                printf("Swaps (Quick Sort): %lld\n", swap_count);
                break;

            case 3:
                start = clock();
                swap_count = insertionSort(temp, n);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time taken (Insertion Sort): %.6f seconds\n", time_taken);
                printf("Swaps (Insertion Sort): %lld\n", swap_count);
                break;

            case 4:
                start = clock();
                swap_count = bubbleSort(temp, n);
                end = clock();
                time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("Time taken (Bubble Sort): %.6f seconds\n", time_taken);
                printf("Swaps (Bubble Sort): %lld\n", swap_count);
                break;

            case 5:
                exit(0);
            
            case 6: {
                double times[4];
                long long swaps[4];

                // Merge Sort
                for (int i = 0; i < n; i++) temp[i] = arr[i];
                start = clock();
                mergeSort(temp, 0, n - 1);
                end = clock();
                times[0] = ((double)(end - start)) / CLOCKS_PER_SEC;
                swaps[0] = -1; // Not applicable

                // Quick Sort
                for (int i = 0; i < n; i++) temp[i] = arr[i];
                swaps[1] = 0;
                start = clock();
                quickSort(temp, 0, n - 1, &swaps[1]);
                end = clock();
                times[1] = ((double)(end - start)) / CLOCKS_PER_SEC;

                // Insertion Sort
                for (int i = 0; i < n; i++) temp[i] = arr[i];
                start = clock();
                swaps[2] = insertionSort(temp, n);
                end = clock();
                times[2] = ((double)(end - start)) / CLOCKS_PER_SEC;

                // Bubble Sort
                for (int i = 0; i < n; i++) temp[i] = arr[i];
                start = clock();
                swaps[3] = bubbleSort(temp, n);
                end = clock();
                times[3] = ((double)(end - start)) / CLOCKS_PER_SEC;

                // Print Table
                printf("\n%-15s | %-12s | %-15s\n", "Algorithm", "Time (s)", "Swaps");
                printf("-----------------|--------------|-----------------\n");
                printf("%-15s | %-12.6f | %-15s\n", "Merge Sort", times[0], "N/A");
                printf("%-15s | %-12.6f | %-15lld\n", "Quick Sort", times[1], swaps[1]);
                printf("%-15s | %-12.6f | %-15lld\n", "Insertion Sort", times[2], swaps[2]);
                printf("%-15s | %-12.6f | %-15lld\n", "Bubble Sort", times[3], swaps[3]);
                break;
            }

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}