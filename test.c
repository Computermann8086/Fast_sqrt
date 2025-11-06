#include <sqrt.c>
#include <stdio.h>
#include <windows.h>
#include <limits.h>

void print_long_bits(long num) {
    // Determine the number of bits in a long
    // sizeof(long) * CHAR_BIT gives the total number of bits
    int num_bits = sizeof(long) * CHAR_BIT;

    // Iterate from the most significant bit to the least significant bit
    for (int i = num_bits - 1; i >= 0; i--) {
        // Right shift the number by 'i' positions to bring the current bit to the LSB position
        // Then, perform a bitwise AND with 1 to isolate the LSB, which is the bit at position 'i'
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n"); // Print a newline after all bits are printed
}

int main(){
    float ret_val = fast_sqrt((float)17);
    long aret_val = *(long*)&ret_val;
    print_long_bits(aret_val);
    printf("%f", ret_val);

    LARGE_INTEGER start_time, end_time, frequency;
    double interval;
    int i = 0;

    // Get the frequency of the performance counter
    if (!QueryPerformanceFrequency(&frequency)) {
        fprintf(stderr, "Error: QueryPerformanceFrequency failed.\n");
        return 1;
    }

    // Get the starting time
    if (!QueryPerformanceCounter(&start_time)) {
        fprintf(stderr, "Error: QueryPerformanceCounter failed at start.\n");
        return 1;
    }

    // Call the function to be timed
    for (i=0;i<300000001;i++){
    fast_sqrt((float)1040);
    }
    

    // Get the ending time
    if (!QueryPerformanceCounter(&end_time)) {
        fprintf(stderr, "Error: QueryPerformanceCounter failed at end.\n");
        return 1;
    }

    // Calculate the elapsed time in seconds
    interval = (double)(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;

    printf("Execution time of my_function: %f seconds\n", interval);

    return 0;
    return 0;
}
