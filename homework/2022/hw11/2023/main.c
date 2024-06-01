#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_FILE_NAME_LENGTH 100

// Struct representing a person
typedef struct Person {
    char Name[MAX_NAME_LENGTH];
    int Age;
    struct Person* Mother;
    struct Person* Father;
} Person;

// Function prototypes
void addFamilyTree();
void removeFamilyTree();
void addPerson(Person** root);
void removePerson(Person** root);
void loadFamilyTree();
void saveFamilyTreeToFile(Person* root, const char* fileName);
Person* loadFamilyTreeFromFile(const char* fileName);
void printNuclearFamily(Person* person);
void searchRelatives(Person* person);

int main() 
{
    int choice;

    while (1) 
    {
        printf("\nFamily Tree System Menu:\n");
        printf("1. Add Family Tree\n");
        printf("2. Remove Family Tree\n");
        printf("3. Load Family Tree\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                addFamilyTree();
                break;
            case 2:
                removeFamilyTree();
                break;
            case 3:
                loadFamilyTree();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addFamilyTree() 
{
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the text file for the family tree: ");
    scanf("%s", fileName);

    FILE* file = fopen(fileName, "w");
    if (file == NULL) 
    {
        printf("Error creating the text file.\n");
        return;
    }

    fclose(file);
    printf("%s has been created successfully.\n", fileName);
}

void removeFamilyTree()
{
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the text file of the family tree: ");
    scanf("%s", fileName);

    if (remove(fileName) == 0) 
    {
        printf("%s has been removed successfully.\n", fileName);
    } 
    else 
    {
        printf("Error removing the text file.\n");
    }
}

void addPerson(Person** root) {
    char name[MAX_NAME_LENGTH];
    int age;
    char motherName[MAX_NAME_LENGTH];
    char fatherName[MAX_NAME_LENGTH];

    printf("Enter the name of the person: ");
    scanf("%s", name);
    printf("Enter the age of the person: ");
    scanf("%d", &age);
    printf("Enter the name of the mother: ");
    scanf("%s", motherName);
    printf("Enter the name of the father: ");
    scanf("%s", fatherName);

    Person* person = (Person*)malloc(sizeof(Person));
    if (person == NULL) 
    {
        printf("Error allocating memory.\n");
        return;
    }

    strcpy(person->Name, name);
    person->Age = age;
    person->Mother = NULL;
    person->Father = NULL;

    if (*root == NULL) 
    {
        *root = person;
    }

    // Find mother and father in the family tree
    Person* mother = NULL;
    Person* father = NULL;
    if (*root != NULL) 
    {
        mother = *root;
        father = *root;

        while (mother != NULL && strcmp(mother->Name, motherName) != 0) 
        {
            mother = mother->Mother;
        }

        while (father != NULL && strcmp(father->Name, fatherName) != 0) 
        {
            father = father->Father;
        }
    }

    if (mother != NULL && strcmp(mother->Name, motherName) == 0) 
    {
        person->Mother = mother;
    } 
   
    else 
    {
        printf("Mother not found in the family tree.\n");
        free(person);
        return;
    }

    if (father != NULL && strcmp(father->Name, fatherName) == 0) 
    {
        person->Father = father;
    } 
   
    else 
    {
        printf("Father not found in the family tree.\n");
        free(person);
        return;
    }

    printf("Person added successfully.\n");
}

void removePerson(Person** root) 
{
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the person to remove: ");
    scanf("%s", name);

    if (*root == NULL) 
    {
        printf("Family tree is empty.\n");
        return;
    }

    Person* person = *root;
    Person* previousPerson = NULL;
    int found = 0;

    // Find the person to remove
    while (person != NULL && !found) 
    {
        if (strcmp(person->Name, name) == 0) 
        {
            found = 1;
        } 
       
        else 
        {
            previousPerson = person;
            person = person->Mother;
        }
    }

    if (!found) 
    {
        printf("Person not found in the family tree.\n");
        return;
    }

    // Remove the person from the family tree
    if (previousPerson != NULL) 
    {
        previousPerson->Mother = person->Mother;
        previousPerson->Father = person->Father;
    } 
    
    else 
    {
        *root = NULL;
    }

    free(person);
    printf("Person removed successfully.\n");
}

void loadFamilyTree() 
{
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the text file to load the family tree from: ");
    scanf("%s", fileName);

    Person* root = loadFamilyTreeFromFile(fileName);

    if (root != NULL)
     {
        printf("Family tree loaded successfully.\n");
        
        while (1) 
        {
            int choice;

            printf("\nFamily Tree Operations:\n");
            printf("1. Add Person\n");
            printf("2. Remove Person\n");
            printf("3. Save Family Tree to File\n");
            printf("4. Print Nuclear Family\n");
            printf("5. Search Relatives\n");
            printf("6. Return to Main Menu\n");
            printf("> ");
            scanf("%d", &choice);

            switch (choice) 
            {
                case 1:
                    addPerson(&root);
                    break;
                case 2:
                    removePerson(&root);
                    break;
                case 3:
                    saveFamilyTreeToFile(root, fileName);
                    break;
                case 4:
                    printNuclearFamily(root);
                    break;
                case 5:
                    searchRelatives(root);
                    break;
                case 6:
                    printf("Returning to Main Menu...\n");
                    return;
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
    } 
    
    else 
    {
        printf("Failed to load the family tree.\n");
    }
}

void saveFamilyTreeToFile(Person* root, const char* fileName) 
{
    FILE* file = fopen(fileName, "w");
    if (file == NULL) 
    {
        printf("Error opening the file.\n");
        return;
    }

    if (root != NULL) 
    {
        fprintf(file, "%s %d %s %s\n", root->Name, root->Age, root->Mother != NULL ? root->Mother->Name : "-", root->Father != NULL ? root->Father->Name : "-");
        saveFamilyTreeToFile(root->Mother, fileName);
        saveFamilyTreeToFile(root->Father, fileName);
    }

    fclose(file);
    printf("Family tree saved to file successfully.\n");
}

Person* loadFamilyTreeFromFile(const char* fileName) 
{
    FILE* file = fopen(fileName, "r");
    
    if (file == NULL) 
    {
        printf("Error opening the file.\n");
        return NULL;
    }

    Person* root = NULL;

    while (!feof(file)) 
    {
        char name[MAX_NAME_LENGTH];
        int age;
        char motherName[MAX_NAME_LENGTH];
        char fatherName[MAX_NAME_LENGTH];

        fscanf(file, "%s %d %s %s\n", name, &age, motherName, fatherName);

        Person* person = (Person*)malloc(sizeof(Person));
        if (person == NULL) 
        {
            printf("Error allocating memory.\n");
            fclose(file);
            return NULL;
        }

        strcpy(person->Name, name);
        person->Age = age;
        person->Mother = NULL;
        person->Father = NULL;

        if (root == NULL) 
        {
            root = person;
        }

        if (strcmp(motherName, "-") != 0) 
        {
            Person* mother = (Person*)malloc(sizeof(Person));
            if (mother == NULL) 
            {
                printf("Error allocating memory.\n");
                fclose(file);
                return NULL;
            }

            strcpy(mother->Name, motherName);
            mother->Age = -1;
            mother->Mother = NULL;
            mother->Father = NULL;

            person->Mother = mother;
        }

        if (strcmp(fatherName, "-") != 0) 
        {
            Person* father = (Person*)malloc(sizeof(Person));
            if (father == NULL) 
            {
                printf("Error allocating memory.\n");
                fclose(file);
                return NULL;
            }

            strcpy(father->Name, fatherName);
            father->Age = -1;
            father->Mother = NULL;
            father->Father = NULL;

            person->Father = father;
        }
    }

    fclose(file);
    return root;
}

void printNuclearFamily(Person* person) 
{
    if (person == NULL) 
    {
        return;
    }

    printf("Name: %s\n", person->Name);
    printf("Age: %d\n", person->Age);

    printf("Mother: ");
    if (person->Mother != NULL) 
    {
        printf("%s\n", person->Mother->Name);
    } 
    
    else 
    {
        printf("N/A\n");
    }

    printf("Father: ");
    if (person->Father != NULL) 
    {
        printf("%s\n", person->Father->Name);
    }
    
    else 
    {
        printf("N/A\n");
    }
}

void searchRelatives(Person* person) 
{
    if (person == NULL) 
    {
        return;
    }

    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the person to search relatives for: ");
    scanf("%s", name);

    if (strcmp(person->Name, name) == 0) 
    {
        printf("Relative found:\n");
        printNuclearFamily(person);
    } 
    
    else 
    {
        searchRelatives(person->Mother);
        searchRelatives(person->Father);
    }
}
