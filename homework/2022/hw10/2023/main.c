#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct Book {
    char isbn[20];
    char title[100];
    char author[100];
    int publicationYear;
    int reserved;
    struct Book* next;
} Book;

typedef struct Student {
    char name[100];
    int id;
    struct Book* borrowedBooks;
    struct Student* next;
} Student;

// Function prototypes
void loadLibraryFromFile();
void saveLibraryToFile();
void displayStudentBorrowedBooks(int studentId);
void addBook(char* isbn, char* title, char* author, int publicationYear, int method);
void deleteBook(char* isbn);
void updateBook(char* isbn, char* feature, char* value);
void filterAndSortBooks(int filterChoice, char* filter, int sortChoice);
void reverseBookList();
void searchBooks(int searchChoice, char* searchValue);
void borrowBook(char* isbn);
void returnBook(char* isbn);

// Global variables
Book* bookList = NULL;
Student* studentList = NULL;

void loadLibraryFromFile() {
    FILE* file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("Unable to open library file.\n");
        return;
    }

    char line[256];
    char* token;

    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        if (strcmp(token, "Book") == 0) {
            Book* book = (Book*)malloc(sizeof(Book));
            strcpy(book->isbn, strtok(NULL, ","));
            strcpy(book->title, strtok(NULL, ","));
            strcpy(book->author, strtok(NULL, ","));
            book->publicationYear = atoi(strtok(NULL, ","));
            book->reserved = atoi(strtok(NULL, ","));
            book->next = NULL;

            if (bookList == NULL) {
                bookList = book;
            } else {
                Book* lastBook = bookList;
                while (lastBook->next != NULL) {
                    lastBook = lastBook->next;
                }
                lastBook->next = book;
            }
        } else if (strcmp(token, "Student") == 0) {
            Student* student = (Student*)malloc(sizeof(Student));
            strcpy(student->name, strtok(NULL, ","));
            student->id = atoi(strtok(NULL, ","));
            student->borrowedBooks = NULL;
            student->next = NULL;

            if (studentList == NULL) {
                studentList = student;
            } else {
                Student* lastStudent = studentList;
                while (lastStudent->next != NULL) {
                    lastStudent = lastStudent->next;
                }
                lastStudent->next = student;
            }
        }
    }

    fclose(file);
}

void saveLibraryToFile() {
    FILE* file = fopen("library.txt", "w");
    if (file == NULL) {
        printf("Unable to open library file for writing.\n");
        return;
    }

    Book* book = bookList;
    while (book != NULL) {
        fprintf(file, "Book,%s,%s,%s,%d,%d\n", book->isbn, book->title, book->author, book->publicationYear, book->reserved);
        book = book->next;
    }

    Student* student = studentList;
    while (student != NULL) {
        fprintf(file, "Student,%s,%d\n", student->name, student->id);
        student = student->next;
    }

    fclose(file);
}

void displayStudentBorrowedBooks(int studentId) {
    Student* student = studentList;
    while (student != NULL) {
        if (student->id == studentId) {
            Book* borrowedBook = student->borrowedBooks;
            if (borrowedBook == NULL) {
                printf("No books borrowed by student with ID %d.\n", studentId);
                return;
            }

            printf("Books borrowed by student with ID %d:\n", studentId);
            while (borrowedBook != NULL) {
                printf("ISBN: %s\n", borrowedBook->isbn);
                printf("Title: %s\n", borrowedBook->title);
                printf("Author: %s\n", borrowedBook->author);
                printf("Publication Year: %d\n", borrowedBook->publicationYear);
                printf("Reserved: %s\n\n", borrowedBook->reserved ? "Yes" : "No");

                borrowedBook = borrowedBook->next;
            }

            return;
        }
        student = student->next;
    }

    printf("Student with ID %d not found.\n", studentId);
}

void addBook(char* isbn, char* title, char* author, int publicationYear, int method) {
    Book* book = (Book*)malloc(sizeof(Book));
    strcpy(book->isbn, isbn);
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->publicationYear = publicationYear;
    book->reserved = 0;
    book->next = NULL;

    if (bookList == NULL) {
        bookList = book;
    } else {
        if (method == 0) {  // FIFO
            Book* lastBook = bookList;
            while (lastBook->next != NULL) {
                lastBook = lastBook->next;
            }
            lastBook->next = book;
        } else if (method == 1) {  // LIFO
            book->next = bookList;
            bookList = book;
        }
    }
}

void deleteBook(char* isbn) {
    Book* prevBook = NULL;
    Book* book = bookList;

    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (prevBook == NULL) {
                bookList = book->next;
            } else {
                prevBook->next = book->next;
            }

            free(book);
            printf("Book with ISBN %s deleted.\n", isbn);
            return;
        }

        prevBook = book;
        book = book->next;
    }

    printf("Book with ISBN %s not found.\n", isbn);
}

void updateBook(char* isbn, char* feature, char* value) {
    Book* book = bookList;

    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (strcmp(feature, "title") == 0) {
                strcpy(book->title, value);
                printf("Book title updated successfully.\n");
                return;
            } else if (strcmp(feature, "author") == 0) {
                strcpy(book->author, value);
                printf("Book author updated successfully.\n");
                return;
            } else if (strcmp(feature, "publication year") == 0) {
                book->publicationYear = atoi(value);
                printf("Book publication year updated successfully.\n");
                return;
            } else {
                printf("Invalid feature.\n");
                return;
            }
        }
        book = book->next;
    }

    printf("Book with ISBN %s not found.\n", isbn);
}

void filterAndSortBooks(int filterChoice, char* filter, int sortChoice) {
    Book* filteredBooks = NULL;
    Book* book = bookList;

    while (book != NULL) {
        if (filterChoice == 0) {  // Filter by author
            if (strcmp(book->author, filter) == 0) {
                Book* filteredBook = (Book*)malloc(sizeof(Book));
                strcpy(filteredBook->isbn, book->isbn);
                strcpy(filteredBook->title, book->title);
                strcpy(filteredBook->author, book->author);
                filteredBook->publicationYear = book->publicationYear;
                filteredBook->reserved = book->reserved;
                filteredBook->next = NULL;

                if (filteredBooks == NULL) {
                    filteredBooks = filteredBook;
                } else {
                    Book* lastFilteredBook = filteredBooks;
                    while (lastFilteredBook->next != NULL) {
                        lastFilteredBook = lastFilteredBook->next;
                    }
                    lastFilteredBook->next = filteredBook;
                }
            }
        } else if (filterChoice == 1) {  // Filter by publication year
            if (book->publicationYear == atoi(filter)) {
                Book* filteredBook = (Book*)malloc(sizeof(Book));
                strcpy(filteredBook->isbn, book->isbn);
                strcpy(filteredBook->title, book->title);
                strcpy(filteredBook->author, book->author);
                filteredBook->publicationYear = book->publicationYear;
                filteredBook->reserved = book->reserved;
                filteredBook->next = NULL;

                if (filteredBooks == NULL) {
                    filteredBooks = filteredBook;
                } else {
                    Book* lastFilteredBook = filteredBooks;
                    while (lastFilteredBook->next != NULL) {
                        lastFilteredBook = lastFilteredBook->next;
                    }
                    lastFilteredBook->next = filteredBook;
                }
            }
        }
        book = book->next;
    }

    // Sort the filtered books
    if (sortChoice == 0) {  // Sort by title
        filteredBooks = sortBooksByTitle(filteredBooks);
    } else if (sortChoice == 1) {  // Sort by author
        filteredBooks = sortBooksByAuthor(filteredBooks);
    } else if (sortChoice == 2) {  // Sort by publication year
        filteredBooks = sortBooksByPublicationYear(filteredBooks);
    }

    // Display the filtered and sorted books
    book = filteredBooks;
    while (book != NULL) {
        printf("ISBN: %s\n", book->isbn);
        printf("Title: %s\n", book->title);
        printf("Author: %s\n", book->author);
        printf("Publication Year: %d\n", book->publicationYear);
        printf("Reserved: %s\n\n", book->reserved ? "Yes" : "No");

        book = book->next;
    }

    // Free the memory allocated for filtered books
    book = filteredBooks;
    while (book != NULL) {
        Book* nextBook = book->next;
        free(book);
        book = nextBook;
    }
}

Book* sortBooksByTitle(Book* books) {
    int swapped;
    Book* ptr1 = NULL;
    Book* lptr = NULL;

    if (books == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = books;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->title, ptr1->next->title) > 0) {
                swapBooks(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return books;
}

Book* sortBooksByAuthor(Book* books) {
    int swapped;
    Book* ptr1 = NULL;
    Book* lptr = NULL;

    if (books == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = books;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->author, ptr1->next->author) > 0) {
                swapBooks(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return books;
}

Book* sortBooksByPublicationYear(Book* books) {
    int swapped;
    Book* ptr1 = NULL;
    Book* lptr = NULL;

    if (books == NULL)
        return NULL;

    do {
        swapped = 0;
        ptr1 = books;

        while (ptr1->next != lptr) {
            if (ptr1->publicationYear > ptr1->next->publicationYear) {
                swapBooks(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return books;
}

void swapBooks(Book* book1, Book* book2) {
    Book temp = *book1;
    *book1 = *book2;
    *book2 = temp;
}

void reverseBookList() {
    Book* prevBook = NULL;
    Book* currBook = bookList;
    Book* nextBook = NULL;

    while (currBook != NULL) {
        nextBook = currBook->next;
        currBook->next = prevBook;
        prevBook = currBook;
        currBook = nextBook;
    }

    bookList = prevBook;
}

void searchBooks(int searchChoice, char* searchValue) {
    Book* book = bookList;
    int found = 0;

    while (book != NULL) {
        if (searchChoice == 0) {  // Search by ISBN
            if (strcmp(book->isbn, searchValue) == 0) {
                printf("ISBN: %s\n", book->isbn);
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Publication Year: %d\n", book->publicationYear);
                printf("Reserved: %s\n\n", book->reserved ? "Yes" : "No");
                found = 1;
                break;
            }
        } else if (searchChoice == 1) {  // Search by title
            if (strcmp(book->title, searchValue) == 0) {
                printf("ISBN: %s\n", book->isbn);
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Publication Year: %d\n", book->publicationYear);
                printf("Reserved: %s\n\n", book->reserved ? "Yes" : "No");
                found = 1;
                break;
            }
        } else if (searchChoice == 2) {  // Search by author
            if (strcmp(book->author, searchValue) == 0) {
                printf("ISBN: %s\n", book->isbn);
                printf("Title: %s\n", book->title);
                printf("Author: %s\n", book->author);
                printf("Publication Year: %d\n", book->publicationYear);
                printf("Reserved: %s\n\n", book->reserved ? "Yes" : "No");
                found = 1;
                break;
            }
        }

        book = book->next;
    }

    if (!found) {
        printf("No books found.\n");
    }
}

void borrowBook(char* isbn) {
    Book* book = bookList;
    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (book->reserved) {
                printf("Book with ISBN %s is already reserved.\n", isbn);
                return;
            }

            book->reserved = 1;

            // Add the borrowed book to the student's list
            int studentId;
            printf("Enter student ID: ");
            scanf("%d", &studentId);

            Student* student = studentList;
            while (student != NULL) {
                if (student->id == studentId) {
                    Book* borrowedBook = (Book*)malloc(sizeof(Book));
                    strcpy(borrowedBook->isbn, book->isbn);
                    strcpy(borrowedBook->title, book->title);
                    strcpy(borrowedBook->author, book->author);
                    borrowedBook->publicationYear = book->publicationYear;
                    borrowedBook->reserved = 1;
                    borrowedBook->next = student->borrowedBooks;
                    student->borrowedBooks = borrowedBook;

                    printf("Book with ISBN %s borrowed by student with ID %d.\n", isbn, studentId);
                    return;
                }
                student = student->next;
            }

            printf("Student with ID %d not found.\n", studentId);
            return;
        }
        book = book->next;
    }

    printf("Book with ISBN %s not found.\n", isbn);
}

void returnBook(char* isbn) {
    Book* book = bookList;
    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (!book->reserved) {
                printf("Book with ISBN %s is not currently borrowed.\n", isbn);
                return;
            }

            book->reserved = 0;

            // Remove the returned book from the student's list
            int studentId;
            printf("Enter student ID: ");
            scanf("%d", &studentId);

            Student* student = studentList;
            while (student != NULL) {
                if (student->id == studentId) {
                    Book* borrowedBook = student->borrowedBooks;
                    Book* prevBook = NULL;

                    while (borrowedBook != NULL) {
                        if (strcmp(borrowedBook->isbn, isbn) == 0) {
                            if (prevBook == NULL) {
                                student->borrowedBooks = borrowedBook->next;
                            } else {
                                prevBook->next = borrowedBook->next;
                            }

                            free(borrowedBook);
                            printf("Book with ISBN %s returned by student with ID %d.\n", isbn, studentId);
                            return;
                        }

                        prevBook = borrowedBook;
                        borrowedBook = borrowedBook->next;
                    }

                    printf("Book with ISBN %s not borrowed by student with ID %d.\n", isbn, studentId);
                    return;
                }
                student = student->next;
            }

            printf("Student with ID %d not found.\n", studentId);
            return;
        }
        book = book->next;
    }

    printf("Book with ISBN %s not found.\n", isbn);
}

int main() {
    int choice;
    char isbn[20], title[100], author[100], feature[20], value[100];
    int publicationYear, method;
    int filterChoice, sortChoice;
    char filter[100];
    int searchChoice;
    char searchValue[100];
    int studentId;

    while (1) {
        printf("Library Management System\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Update Book\n");
        printf("4. Filter and Sort Books\n");
        printf("5. Reverse Book List\n");
        printf("6. Search Books\n");
        printf("7. Borrow Book\n");
        printf("8. Return Book\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                printf("Enter Title: ");
                scanf("%s", title);
                printf("Enter Author: ");
                scanf("%s", author);
                printf("Enter Publication Year: ");
                scanf("%d", &publicationYear);
                printf("Enter Method (0 for FIFO, 1 for LIFO): ");
                scanf("%d", &method);
                addBook(isbn, title, author, publicationYear, method);
                break;
            case 2:
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                deleteBook(isbn);
                break;
            case 3:
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                printf("Enter Feature (title, author, publication year): ");
                scanf("%s", feature);
                printf("Enter Value: ");
                scanf("%s", value);
                updateBook(isbn, feature, value);
                break;
            case 4:
                printf("Filter and Sort Books\n");
                printf("0. Filter by Author\n");
                printf("1. Filter by Publication Year\n");
                printf("Enter Filter Choice: ");
                scanf("%d", &filterChoice);
                printf("Enter Filter Value: ");
                scanf("%s", filter);
                printf("0. Sort by Title\n");
                printf("1. Sort by Author\n");
                printf("2. Sort by Publication Year\n");
                printf("Enter Sort Choice: ");
                scanf("%d", &sortChoice);
                filterAndSortBooks(filterChoice, filter, sortChoice);
                break;
            case 5:
                reverseBookList();
                printf("Book List Reversed.\n");
                break;
            case 6:
                printf("Search Books\n");
                printf("0. Search by ISBN\n");
                printf("1. Search by Title\n");
                printf("2. Search by Author\n");
                printf("Enter Search Choice: ");
                scanf("%d", &searchChoice);
                printf("Enter Search Value: ");
                scanf("%s", searchValue);
                searchBooks(searchChoice, searchValue);
                break;
            case 7:
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                borrowBook(isbn);
                break;
            case 8:
                printf("Enter ISBN: ");
                scanf("%s", isbn);
                returnBook(isbn);
                break;
            case 9:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}
