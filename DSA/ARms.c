#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef unsigned long long ull;

/* O(n) power: */
ull Loop(int base, int exp) {
    ull result = 1ULL;
    for (int i = 0; i < exp; ++i) {
        result *= (ull)base;
    }
    return result;
}

/* O(log n) power: */
ull bitpow(int base, int exp) {
    ull result = 1ULL;
    ull b = (ull)base;
    while (exp) {
        if (exp & 1u) result *= b;
        b *= b;
        exp >>= 1;
    }
    return result;
}

/* Count digits in a number */
int count_digits(int num) {
    if (num == 0) return 1;
    int count = 0;
    while (num) {
        count++;
        num /= 10;
    }
    return count;
}

/* Check Armstrong using a given power function */
int is_armstrong(int num, ull (*power_func)(int, int)) {
    int digits = count_digits(num);
    int temp = num;
    ull sum = 0;
    while (temp) {
        int d = temp % 10;
        sum += power_func(d, digits);
        temp /= 10;
    }
    return sum == (ull)num;
}

double measure_time(int limit, ull (*power_func)(int, int)) {
    clock_t start = clock();
    for (int i = 1; i <= limit; ++i) {
        is_armstrong(i, power_func);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main(void) {
    int limits[] = {10, 100, 1000, 10000, 100000, 1000000,10000000,100000000};
    int size = sizeof(limits) / sizeof(limits[0]);

    printf("%-10s %-20s %-20s\n", "Limit", "Time (power_loop)", "Time (power_fast)");

    for (int i = 0; i < size; ++i) {
        int n = limits[i];
        double time_loop = measure_time(n, Loop);
        double time_bit = measure_time(n, bitpow);

        printf("%-10d %-20.6f %-20.6f\n", n, time_loop, time_bit);
    }

    return 0;
}