#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

char first_initial(FILE *id_fp, int id);
char last_initial(FILE *id_fp, int id);
int get_id_fi(FILE *id_fp, char first_initial);
int get_id_li(FILE *id_fp, char last_initial);
int calculate_average_grade(FILE *info_fp, int id);
void print_course_result(FILE *info_fp, int course_id);
int get_num_classes(int id);
void print_department_by_role(FILE *id_fp, char role_initial);
void print_student_course_id(FILE *info_fp, int id);

int main() {
    FILE *id_fp = fopen("second.txt", "r");
    FILE *info_fp = fopen("first.txt", "r");

    if (id_fp == NULL || info_fp == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char choice;
    do {
        printf("\nMenu:\n");
        printf("p: Print all users pass or fail.\n");
        printf("n: Print only the user with a specific first initial.\n");
        printf("g: Calculate the GPA of a given student.\n");
        printf("c: Print whether each user passed or failed the same class.\n");
        printf("t: Print the number of classes for the instructor.\n");
        printf("d: Print the department of all persons according to the role.\n");
        printf("l: Print the course_id of a given student.\n");
        printf("e: Quit the program.\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'p': {
                rewind(info_fp);
                int id, midterm1, midterm2, final, course_id;

                while (fscanf(info_fp, "%d;%d;%d;%d;%d", &id, &midterm1, &midterm2, &final, &course_id) == 5) {
                    int average = (midterm1 + midterm2) / 2;

                    if ((midterm1 < 40 && average < (midterm1 + midterm2) / 2) || (midterm2 < 40 && average < (midterm1 + midterm2) / 2) || (final < 40 && final < average)) {
                        printf("Student ID: %d failed\n", id);
                    } else {
                        printf("Student ID: %d passed\n", id);
                    }
                }
                break;
            }

            case 'n': {
                char initial;
                printf("Enter the first initial: ");
                scanf(" %c", &initial);

                int id = get_id_fi(id_fp, initial);
            
                if (id == -1) {
                    printf("No user found with the given initial.\n");
                } else {
                    printf("User found with the initial '%c': ID %d\n", initial, id);
                }
                break;
            }

            case 'g': {
                int id;
                printf("Enter the student ID: ");
                scanf("%d", &id);

                int average_grade = calculate_average_grade(info_fp, id);
                printf("Average grade for student ID %d: %d\n", id, average_grade);
                break;
            }

            case 'c': {
                int course_id;
                printf("Enter the course ID: ");
                scanf("%d", &course_id);

                print_course_result(info_fp, course_id);
                break;
            }

            case 't': {
                int id;
                printf("Enter the instructor ID: ");
                scanf("%d", &id);

                int num_classes = get_num_classes(id);
                printf("Instructor with ID %d teaches %d classes.\n", id, num_classes);
                break;
            }

            case 'd': {
                char role_initial;
                printf("Enter the role initial: ");
                scanf(" %c", &role_initial);

                print_department_by_role(id_fp, role_initial);
                break;
            }

            case 'l': {
                int id;
                printf("Enter the student ID: ");
                scanf("%d", &id);

                print_student_course_id(info_fp, id);
                break;
            }
        
            case 'e': {
                printf("Exiting the program.\n");
                break;
            }
        
            default: {
                printf("Invalid choice! Please enter a valid option.\n");
                break;
            }

        }

    } while (choice != 'e');

    fclose(id_fp);
    fclose(info_fp);
    return 0;
}

char first_initial(FILE *id_fp, int id) {
    int id_read;
    char first_initial;
    char name, surname, role, department;
    rewind(id_fp); /* Go to the beginning of the file */

    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        if (id_read == id)
            return name;
    }

    return '\0'; /* Return null character if id not found */
}

char last_initial(FILE *id_fp, int id) {
    int id_read;
    char surname;
    char name, role, department;
    rewind(id_fp); /* Go to the beginning of the file */

    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        if (id_read == id)
            return surname;
    }

    return '\0'; /* Return null character if id not found */
}

int get_id_fi(FILE *id_fp, char first_initial) {
    int id_read;
    char name, surname, role, department;
    rewind(id_fp); /* Go to the beginning of the file */

    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        /* Convert both the search character and the character read from the file to lowercase */
        char lowercase_first_initial = first_initial >= 'A' && first_initial <= 'Z' ? first_initial + 32 : first_initial;
        char lowercase_name = name >= 'A' && name <= 'Z' ? name + 32 : name;
        
        if (lowercase_name == lowercase_first_initial)
            return id_read;
    }

    return -1; /* Return -1 if the specified initial is not found */
}



int get_id_li(FILE *id_fp, char last_initial) {
    int id_read;
    char initial;
    char name, surname, role, department;
    rewind(id_fp); /* Go to the beginning of the file */

    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        if (surname == last_initial)
            return id_read;
    }

    return -1; /* Return -1 if initial not found */
}

int calculate_average_grade(FILE *info_fp, int id) {
    FILE *info_temp = fopen("temp.txt", "w+");
    if (info_temp == NULL) {
        printf("Error: Unable to open temporary file.\n");
        return -1;
    }

    int id_read, midterm1, midterm2, final, course_id;
    int total_grades = 0, num_grades = 0;
    rewind(info_fp);

    while (fscanf(info_fp, "%d;%d;%d;%d;%d", &id_read, &midterm1, &midterm2, &final, &course_id) == 5) {
        if (id_read == id) {
            int avg_midterm = (midterm1 + midterm2) / 2;
            int avg_final = final;

            if (midterm1 < 40 && avg_midterm < (midterm1 + midterm2) / 2) 
                avg_midterm = 0;
            
            if (final < 40 && avg_final < final) 
                avg_final = 0;
            
            total_grades += (avg_midterm + avg_final) / 2;
            num_grades++;
        }
    }

    fclose(info_temp);
    remove("temp.txt");

    if (num_grades > 0) 
        return total_grades / num_grades;
    else 
        return -1;
}

void print_course_result(FILE *info_fp, int course_id) {
    rewind(info_fp);
    int id, midterm1, midterm2, final, id_course;
    while (fscanf(info_fp, "%d;%d;%d;%d;%d", &id, &midterm1, &midterm2, &final, &id_course) == 5) {
        if (id_course == course_id) {
            if ((midterm1 >= 40 && midterm2 >= 40 && final >= 40) && (midterm1 + midterm2 + final) / 3 >= 50) 
                printf("Student ID: %d passed the course.\n", id);
            else 
                printf("Student ID: %d failed the course.\n", id);
        }
    }
}

int get_num_classes(int id) {
    FILE *id_fp = fopen("second.txt", "r");
    if (id_fp == NULL) {
        printf("Error: Unable to open file.\n");
        return -1;
    }

    rewind(id_fp);
    int id_read, count = 0;
    char name, surname, role, department;
    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        if (id_read == id && role == 'i') {
            count++;
        }
    }

    fclose(id_fp);
    return count;
}

void print_department_by_role(FILE *id_fp, char role_initial) {
    rewind(id_fp);
    int id_read;
    char name, surname, role, department;
    while (fscanf(id_fp, "%d;%c;%c;%c;%c", &id_read, &name, &surname, &role, &department) == 5) {
        if (role == role_initial) {
            printf("ID: %d, Department: %c\n", id_read, department);
        }
    }
}

void print_student_course_id(FILE *info_fp, int id) {
    rewind(info_fp);
    int id_read, midterm1, midterm2, final, course_id;
    while (fscanf(info_fp, "%d;%d;%d;%d;%d", &id_read, &midterm1, &midterm2, &final, &course_id) == 5) {
        if (id_read == id) {
            printf("Student ID: %d, Course ID: %d\n", id_read, course_id);
        }
    }
}
