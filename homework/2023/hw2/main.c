#include <stdio.h>

#define MAX_NGRAMS 100

int main() 
{
    FILE *inputFile, *outputFile;
    int ngrams[MAX_NGRAMS][2] = {0}; // Array to store 2-grams
    int counts[MAX_NGRAMS] = {0};   // Array to store counts
    int totalNgrams = 0;

    // Open input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) 
    {
        printf("Error opening input.txt\n");
        return 1;
    }

    // Read 2-grams from input.txt
    int num1, num2;
    while (fscanf(inputFile, "%d %d", &num1, &num2) == 2) 
    {
        int found = 0;

        // Check if this 2-gram is already in the array
        for (int i = 0; i < totalNgrams; i++) 
        {
            if (ngrams[i][0] == num1 && ngrams[i][1] == num2) 
            {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the array
        if (!found) 
        {
            if (totalNgrams < MAX_NGRAMS) 
            {
                ngrams[totalNgrams][0] = num1;
                ngrams[totalNgrams][1] = num2;
                counts[totalNgrams] = 1;
                totalNgrams++;
            } 
            else 
            {
                printf("Exceeded the maximum number of 2-grams\n");
                break;
            }
        }
    }

    // Close the input file
    fclose(inputFile);

    // Open output file for writing
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) 
    {
        printf("Error opening output.txt\n");
        return 1;
    }

    // Write 2-grams and their counts to output.txt
    for (int i = 0; i < totalNgrams; i++) 
    {
        fprintf(outputFile, "%d %d:%d\n", ngrams[i][0], ngrams[i][1], counts[i]);
    }

    // Close the output file
    fclose(outputFile);

    return 0;
}