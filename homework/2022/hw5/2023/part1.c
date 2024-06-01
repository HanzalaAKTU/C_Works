#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define ALPHABET_SIZE 26

void countLetters(char *filename, int *letter_counts) 
{
    FILE *file_ptr;
    char c;

    file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) 
    {
        printf("Unable to open file.\n");
        return;
    }

    while ((c = fgetc(file_ptr)) != EOF) 
    {
        if (isalpha(c)) 
        {
            c = tolower(c);
            letter_counts[c - 'a']++;
        }
    }

    fclose(file_ptr);
}

void printTable(int *letter_counts) 
{
    printf("Letter frequency table:\n");
    printf("------------------------\n");
    for (int i = 0; i < ALPHABET_SIZE; i++) 
    {
        printf("%c: %d\n", 'a' + i, letter_counts[i]);
    }
}

int main() 
{
    int letter_counts[ALPHABET_SIZE] = {0};
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    countLetters(filename, letter_counts);
    printTable(letter_counts);

    return 0;
}
