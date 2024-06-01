#include <stdio.h>

#define ALPHABET_SIZE 61

/* The alphabet consists of lowercase letters, symbols, and digits.*/
static char alphabet[ALPHABET_SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 
'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 
'w', 'x', 'y', 'z', '(', '<', '=', '+', ')', '[', '*', '/', ']', 
'{', '>', '!', '-', '}', '?', '\\', '&', '|', '%', '_', ';', '"', 
'#', '.', '\'', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


/* Function to calculate the Caesar cipher key from the student ID */
int calculateKey(long long studentID) 
{
    int key = 0;

    /* First loop: Summing up the digits of the student ID */
    while (studentID > 0) 
    {
        key += studentID % 10;
        studentID /= 10;
    }

    /* Second loop: Reducing the sum to a single-digit number */
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

/* Function to encrypt a character using Caesar's encryption */
char encryptChar(char ch, int key) 
{
    int index = findIndex(ch);
    char new_ch;
    if (index == -1)
        new_ch = ch;
    
    else
        new_ch = alphabet[(index + key) % ALPHABET_SIZE];
    
    return new_ch;
}

int main() 
{
    long long studentID = 1901042706;
    int key = calculateKey(studentID);

    char ch;
    int inComment = 0; /* Flag to track whether inside a comment */
    int commentLen = 0;

    while (scanf("%c", &ch) != EOF) 
    {
        if (ch == '/' && !inComment) 
        {
            char nextChar;
            scanf("%c", &nextChar);
            if (nextChar == '*')            /* begining of comment */
            {
                printf("@");
                inComment = 1; /* Set flag to indicate inside a comment */
            } 
            
            else 
                printf("/%c", encryptChar(nextChar,key));
        } 
        
        else if (ch == '*' && inComment) 
        {
            char nextChar;
            scanf("%c", &nextChar);
            if (nextChar == '/')                /* end of comment */
            {
                printf(" %d",commentLen);
                inComment = 0; /* Reset flag to indicate end of comment */
                commentLen = 0;
            } 

            else 
                printf("*%c", encryptChar(nextChar,key));
        } 
        
        else if (!inComment) 
            printf("%c", encryptChar(ch, key));

        else if (inComment)
        {
            if (findIndex(ch) != -1)
                commentLen++;
        }
    }

    return 0;
}