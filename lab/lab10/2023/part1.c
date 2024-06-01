#include <stdio.h>
#include <stdlib.h>

int* generateArray(int size) 
{
    int* arr = (int*)malloc(size * sizeof(int));  // Dynamically allocate memory for the array

    printf("Enter the elements of the array: ");

    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);  // Prompt the user to input integer values for each element
    }

    return arr;
}

int findMin(int* arr, int size) 
{
    int min = arr[0];  // Assume the first element as the minimum

    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < min) 
            min = arr[i];  // Update the minimum value if a smaller value is found
    }

    return min;
}

int main() 
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = generateArray(size);

    int min = findMin(arr, size);
    printf("Min of the array elements: %d\n", min);

    free(arr);  // Deallocate the memory for the array

    return 0;
}