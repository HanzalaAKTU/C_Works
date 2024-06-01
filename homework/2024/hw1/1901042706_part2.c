#include <stdio.h>

#define ALPHABET_SIZE 61

/* The alphabet consists of lowercase letters, symbols, and digits.*/
static char alphabet[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
'w', 'x', 'y', 'z', '(', '<', '=', '+', ')', '[', '*', '/', ']', 
'{', '>', '!', '-', '}', '?', '\\', '&', '|', '%', '_', ';', '"', 
'#', '.', '\'', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


/* Function to find the index of a character in the alphabet */
int findIndex(char ch)
{
    /* Loop to iterate through the alphabet */
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (alphabet[i] == ch)
            return i;
    }

    return -1;
}

/* Function to calculate the Caesar cipher key from the student ID */
int calculateKey(long long studentID) 
{
    int key = 0;
    while (studentID > 0) 
    {
        key += studentID % 10;
        studentID /= 10;
    }

    while (key >= 10) 
    {
        int sum = 0;
        while (key > 0) 
        {
            sum += key % 10;
            key /= 10;
        }
        
        key = sum;
    }

    return key;
}

/* Function to decrypt a character using Caesar's encryption */
char decryptChar(char ch, int key) 
{
    int index = findIndex(ch);
    char new_ch;
    if (index == -1)
        new_ch = ch;
    
    else
        new_ch = alphabet[(ALPHABET_SIZE + index - key) % ALPHABET_SIZE];
    
    return new_ch; 
}

int main() 
{
    long long studentID = 1901042706;
    int key = calculateKey(studentID);

    char ch, nextChar;
    while (scanf("%c", &ch) != EOF) 
    {
        if (ch == '@') /* Marker for comment */
        { 
            printf("/*there is ");
            scanf("%c", &nextChar);
            while (scanf("%c", &nextChar) != EOF && nextChar != ' ') 
            {
                if (nextChar >= '0' && nextChar <= '9') 
                    printf("%c", nextChar); /* Print the number of characters in the comment */
                else
                    break;
            }
           
            printf(" characters as comment.*/\n");
        } 
        
        else 
            printf("%c", decryptChar(ch, key));
    }

    return 0;
}