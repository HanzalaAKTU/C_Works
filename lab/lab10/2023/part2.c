#include <stdio.h>
#include <stdlib.h>

int* generateArray(int size) 
{
    int* arr = (int*)malloc(size * sizeof(int));  // Dynamically allocate memory for the array

    printf("Enter %d integers: ", size);

    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);  // Prompt the user to input integer values for each element
    }

    return arr;
}

int* calculateCumulativeSum(int* arr, int size) 
{
    int* cumSum = (int*)calloc(size, sizeof(int));  // Dynamically allocate memory for the cumulative sum array

    cumSum[0] = arr[0];  // First element of the cumulative sum array is the same as the first element of the original array

    for (int i = 1; i < size; i++) 
    {
        cumSum[i] = cumSum[i - 1] + arr[i];  // Calculate the cumulative sum
    }

    return cumSum;
}

void printArray(int* arr, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);  // Print the elements of the array
    }

    printf("\n");
}

int main() 
{
    int size;

    printf("Enter the number of integers: ");
    scanf("%d", &size);

    int* arr = generateArray(size);  // Generate the first array

    int* cumSum = calculateCumulativeSum(arr, size);  // Generate the cumulative sum array

    printf("First array: ");
    printArray(arr, size);

    printf("Second array (cumulative sum): ");
    printArray(cumSum, size);

    free(arr);      // Deallocate memory for the first array
    free(cumSum);   // Deallocate memory for the cumulative sum array

    return 0;
}