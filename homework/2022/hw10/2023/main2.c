#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define ISBN_LENGTH 20
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 100
#define FEATURE_LENGTH 100
#define VALUE_LENGTH 100
#define FILTER_LENGTH 100
#define SEARCH_LENGTH 100

// Book Structure
struct Book {
    char isbn[20];
    char title[100];
    char author[100];
    int publicationYear;
    int reserved;
    struct Book* next;
};

// Student Structure
struct Student {
    char name[100];
    int id;
    struct Book* borrowedBooks;
    struct Student* next;
};

// Global Variables
struct Student* studentList = NULL;
struct Book* bookList = NULL;

// Function Prototypes
void loadLibraryData();
void saveLibraryData();
void addBook(char* isbn, char* title, char* author, int publicationYear, int method);
void deleteBook(char* isbn);
void updateBook(char* isbn, char* feature, char* value);
void filterAndSortBooks(int filterChoice, char* filter, int sortChoice);
void reverseBookList();
void searchBooks(int searchChoice, char* searchValue);
void borrowBook(char* isbn);
void returnBook(char* isbn);
void displayBorrowedBooks(int studentId);

// Function to load library data from a text file
void loadLibraryData() {
    FILE* file = fopen("library.txt", "r");
    if (file != NULL) {
        // Load student data
        int studentCount;
        fscanf(file, "%d", &studentCount);
        for (int i = 0; i < studentCount; i++) {
            struct Student* student = (struct Student*)malloc(sizeof(struct Student));
            fscanf(file, "%s %d", student->name, &student->id);
            student->borrowedBooks = NULL;
            student->next = studentList;
            studentList = student;
        }

        // Load book data
        int bookCount;
        fscanf(file, "%d", &bookCount);
        for (int i = 0; i < bookCount; i++) {
            struct Book* book = (struct Book*)malloc(sizeof(struct Book));
            fscanf(file, "%s %s %s %d %d", book->isbn, book->title, book->author, &book->publicationYear, &book->reserved);
            book->next = bookList;
            bookList = book;
        }

        fclose(file);
    }
}

// Function to save library data to a text file
void saveLibraryData() {
    FILE* file = fopen("library.txt", "w");
    if (file != NULL) {
        // Save student data
        int studentCount = 0;
        struct Student* student = studentList;
        while (student != NULL) {
            studentCount++;
            student = student->next;
        }
        fprintf(file, "%d\n", studentCount);

        student = studentList;
        while (student != NULL) {
            fprintf(file, "%s %d\n", student->name, student->id);
            student = student->next;
        }

        // Save book data
        int bookCount = 0;
        struct Book* book = bookList;
        while (book != NULL) {
            bookCount++;
            book = book->next;
        }
        fprintf(file, "%d\n", bookCount);

        book = bookList;
        while (book != NULL) {
            fprintf(file, "%s %s %s %d %d\n", book->isbn, book->title, book->author, book->publicationYear, book->reserved);
            book = book->next;
        }

        fclose(file);
    }
}

// Function to add a new book to the library
void addBook(char* isbn, char* title, char* author, int publicationYear, int method) {
    struct Book* book = (struct Book*)malloc(sizeof(struct Book));
    strcpy(book->isbn, isbn);
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->publicationYear = publicationYear;
    book->reserved = 0;

    if (method == 0) { // FIFO
        book->next = NULL;
        if (bookList == NULL) {
            bookList = book;
        } else {
            struct Book* currentBook = bookList;
            while (currentBook->next != NULL) {
                currentBook = currentBook->next;
            }
            currentBook->next = book;
        }
    } else { // LIFO
        book->next = bookList;
        bookList = book;
    }

    printf("Book added successfully.\n");
}

// Function to delete a book from the library
void deleteBook(char* isbn) {
    struct Book* currentBook = bookList;
    struct Book* previousBook = NULL;

    while (currentBook != NULL) {
        if (strcmp(currentBook->isbn, isbn) == 0) {
            if (previousBook != NULL) {
                previousBook->next = currentBook->next;
            } else {
                bookList = currentBook->next;
            }
            free(currentBook);
            printf("Book deleted successfully.\n");
            return;
        }

        previousBook = currentBook;
        currentBook = currentBook->next;
    }

    printf("Book not found.\n");
}

// Function to update the information of a book in the library
void updateBook(char* isbn, char* feature, char* value) {
    struct Book* book = bookList;
    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (strcmp(feature, "title") == 0) {
                strcpy(book->title, value);
                printf("Book title updated successfully.\n");
            } else if (strcmp(feature, "author") == 0) {
                strcpy(book->author, value);
                printf("Book author updated successfully.\n");
            } else if (strcmp(feature, "publicationYear") == 0) {
                book->publicationYear = atoi(value);
                printf("Book publication year updated successfully.\n");
            } else {
                printf("Invalid feature name.\n");
            }
            return;
        }
        book = book->next;
    }

    printf("Book not found.\n");
}

// Function to filter and sort the books in the library
void filterAndSortBooks(int filterChoice, char* filter, int sortChoice) {
    // Filter books
    struct Book* filteredBooks = NULL;
    struct Book* book = bookList;

    while (book != NULL) {
        if ((filterChoice == 0 && strcmp(book->author, filter) == 0) ||
            (filterChoice == 1 && book->publicationYear == atoi(filter))) {
            struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
            strcpy(newBook->isbn, book->isbn);
            strcpy(newBook->title, book->title);
            strcpy(newBook->author, book->author);
            newBook->publicationYear = book->publicationYear;
            newBook->reserved = book->reserved;
            newBook->next = filteredBooks;
            filteredBooks = newBook;
        }
        book = book->next;
    }

    // Sort books
    if (sortChoice == 0) { // Sort by title
        struct Book* sortedBooks = NULL;
        while (filteredBooks != NULL) {
            struct Book* maxBook = filteredBooks;
            struct Book* currentBook = filteredBooks->next;

            while (currentBook != NULL) {
                if (strcmp(currentBook->title, maxBook->title) < 0) {
                    maxBook = currentBook;
                }
                currentBook = currentBook->next;
            }

            if (maxBook == filteredBooks) {
                filteredBooks = filteredBooks->next;
            } else {
                struct Book* prevBook = filteredBooks;
                while (prevBook->next != maxBook) {
                    prevBook = prevBook->next;
                }
                prevBook->next = maxBook->next;
            }

            maxBook->next = sortedBooks;
            sortedBooks = maxBook;
        }

        filteredBooks = sortedBooks;
    } else if (sortChoice == 1) { // Sort by author
        struct Book* sortedBooks = NULL;
        while (filteredBooks != NULL) {
            struct Book* maxBook = filteredBooks;
            struct Book* currentBook = filteredBooks->next;

            while (currentBook != NULL) {
                if (strcmp(currentBook->author, maxBook->author) < 0) {
                    maxBook = currentBook;
                }
                currentBook = currentBook->next;
            }

            if (maxBook == filteredBooks) {
                filteredBooks = filteredBooks->next;
            } else {
                struct Book* prevBook = filteredBooks;
                while (prevBook->next != maxBook) {
                    prevBook = prevBook->next;
                }
                prevBook->next = maxBook->next;
            }

            maxBook->next = sortedBooks;
            sortedBooks = maxBook;
        }

        filteredBooks = sortedBooks;
    } else if (sortChoice == 2) { // Sort by publication year
        struct Book* sortedBooks = NULL;
        while (filteredBooks != NULL) {
            struct Book* maxBook = filteredBooks;
            struct Book* currentBook = filteredBooks->next;

            while (currentBook != NULL) {
                if (currentBook->publicationYear < maxBook->publicationYear) {
                    maxBook = currentBook;
                }
                currentBook = currentBook->next;
            }

            if (maxBook == filteredBooks) {
                filteredBooks = filteredBooks->next;
            } else {
                struct Book* prevBook = filteredBooks;
                while (prevBook->next != maxBook) {
                    prevBook = prevBook->next;
                }
                prevBook->next = maxBook->next;
            }

            maxBook->next = sortedBooks;
            sortedBooks = maxBook;
        }

        filteredBooks = sortedBooks;
    }

    // Display filtered and sorted books
    printf("Filtered and Sorted Books:\n");
    while (filteredBooks != NULL) {
        printf("ISBN: %s, Title: %s, Author: %s, Publication Year: %d, Reserved: %s\n",
            filteredBooks->isbn, filteredBooks->title, filteredBooks->author,
            filteredBooks->publicationYear, filteredBooks->reserved ? "Yes" : "No");
        filteredBooks = filteredBooks->next;
    }
}

// Function to reverse the order of books in the library
void reverseBookList() {
    struct Book* prevBook = NULL;
    struct Book* currentBook = bookList;
    struct Book* nextBook = NULL;

    while (currentBook != NULL) {
        nextBook = currentBook->next;
        currentBook->next = prevBook;
        prevBook = currentBook;
        currentBook = nextBook;
    }

    bookList = prevBook;

    printf("Book list reversed successfully.\n");
}

// Function to search for books in the library
void searchBooks(int searchChoice, char* searchValue) {
    struct Book* book = bookList;
    printf("Search Results:\n");

    while (book != NULL) {
        if ((searchChoice == 0 && strcmp(book->title, searchValue) == 0) ||
            (searchChoice == 1 && strcmp(book->author, searchValue) == 0) ||
            (searchChoice == 2 && strcmp(book->isbn, searchValue) == 0)) {
            printf("ISBN: %s, Title: %s, Author: %s, Publication Year: %d, Reserved: %s\n",
                book->isbn, book->title, book->author, book->publicationYear, book->reserved ? "Yes" : "No");
        }
        book = book->next;
    }
}

// Function to borrow a book from the library
void borrowBook(char* isbn) {
    struct Book* book = bookList;
    struct Book* previousBook = NULL;
    int currentStudentId = 0; // Declare and initialize currentStudentId

    while (book != NULL) {
        if (strcmp(book->isbn, isbn) == 0) {
            if (book->reserved == 0) {
                book->reserved = 1;

                struct Student* student = studentList;
                while (student != NULL) {
                    if (student->id == currentStudentId) {
                        struct Book* borrowedBook = (struct Book*)malloc(sizeof(struct Book));
                        strcpy(borrowedBook->isbn, book->isbn);
                        strcpy(borrowedBook->title, book->title);
                        strcpy(borrowedBook->author, book->author);
                        borrowedBook->publicationYear = book->publicationYear;
                        borrowedBook->reserved = book->reserved;
                        borrowedBook->next = student->borrowedBooks;
                        student->borrowedBooks = borrowedBook;
                        break;
                    }
                    student = student->next;
                }

                printf("Book borrowed successfully.\n");
            } else {
                printf("Book is already reserved.\n");
            }
            return;
        }

        previousBook = book;
        book = book->next;
    }

    printf("Book not found.\n");
}

// Function to return a borrowed book to the library
void returnBook(char* isbn) {
    struct Student* student = studentList;
    struct Student* previousStudent = NULL;

    while (student != NULL) {
        struct Book* currentBook = student->borrowedBooks;
        struct Book* previousBook = NULL;

        while (currentBook != NULL) {
            if (strcmp(currentBook->isbn, isbn) == 0) {
                if (previousBook != NULL) {
                    previousBook->next = currentBook->next;
                } else {
                    student->borrowedBooks = currentBook->next;
                }

                struct Book* book = bookList;
                while (book != NULL) {
                    if (strcmp(book->isbn, isbn) == 0) {
                        book->reserved = 0;
                        break;
                    }
                    book = book->next;
                }

                free(currentBook);
                printf("Book returned successfully.\n");
                return;
            }

            previousBook = currentBook;
            currentBook = currentBook->next;
        }

        previousStudent = student;
        student = student->next;
    }

    printf("Book not found.\n");
}

// Function to display the borrowed books of a student
void displayBorrowedBooks(int studentId) {
    struct Student* student = studentList;
    while (student != NULL) {
        if (student->id == studentId) {
            struct Book* book = student->borrowedBooks;
            printf("Borrowed Books:\n");
            while (book != NULL) {
                printf("ISBN: %s, Title: %s, Author: %s, Publication Year: %d\n",
                    book->isbn, book->title, book->author, book->publicationYear);
                book = book->next;
            }
            return;
        }
        student = student->next;
    }

    printf("Student not found.\n");
}

// Function to display the menu options
void displayMenu() {
    printf("Library Management System\n");
    printf("1. Add a book\n");
    printf("2. Delete a book\n");
    printf("3. Update book information\n");
    printf("4. Filter and sort books\n");
    printf("5. Reverse book list\n");
    printf("6. Search books\n");
    printf("7. Borrow a book\n");
    printf("8. Return a book\n");
    printf("9. Display borrowed books of a student\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main() {

    int choice = 0; // Declare and initialize choice
    char isbn[ISBN_LENGTH];
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int publicationYear;
    char feature[FEATURE_LENGTH];
    char value[VALUE_LENGTH];
    int filterChoice;
    char filter[FILTER_LENGTH];
    int sortChoice;
    int searchChoice;
    char searchValue[SEARCH_LENGTH];
    int method = 0; // Declare and initialize studentId

    // Initialize book list
    bookList = NULL;

    // Add sample books
    addBook("9780131103627", "The C Programming Language", "Brian W. Kernighan, Dennis M. Ritchie", 1978, 0);
    addBook("9780201632088", "Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", 1994, 0);
    addBook("9780321125217", "Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 2008, 0);
    addBook("9780132350884", "Introduction to the Theory of Computation", "Michael Sipser", 2005, 0);
    addBook("9780201633610", "Refactoring: Improving the Design of Existing Code", "Martin Fowler", 1999, 0);

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter ISBN: ");
                fgets(isbn, ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; // Remove trailing newline character

                printf("Enter title: ");
                fgets(title, TITLE_LENGTH, stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Enter author: ");
                fgets(author, AUTHOR_LENGTH, stdin);
                author[strcspn(author, "\n")] = '\0';

                printf("Enter publication year: ");
                scanf("%d", &publicationYear);
                getchar(); // Consume the newline character

                printf("Enter method (0 for FIFO, 1 for LIFO): ");
                scanf("%d", &method);
                getchar(); // Consume the newline character

                addBook(isbn, title, author, publicationYear, method);
                break;
            case 2:
                printf("Enter ISBN: ");
                fgets(isbn, ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; // Remove trailing newline character

                deleteBook(isbn);
                break;
            case 3:
                printf("Enter ISBN: ");
                fgets(isbn, ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; // Remove trailing newline character

                printf("Enter feature (title, author, publication year): ");
                fgets(feature, FEATURE_LENGTH, stdin);
                feature[strcspn(feature, "\n")] = '\0';

                printf("Enter new value: ");
                fgets(value, VALUE_LENGTH, stdin);
                value[strcspn(value, "\n")] = '\0';

                updateBook(isbn, feature, value);
                break;
            case 4:
                printf("Enter filter choice (0 for title, 1 for author, 2 for publication year): ");
                scanf("%d", &filterChoice);
                getchar(); // Consume the newline character

                printf("Enter filter value: ");
                fgets(filter, FILTER_LENGTH, stdin);
                filter[strcspn(filter, "\n")] = '\0';

                printf("Enter sort choice (0 for title, 1 for author, 2 for publication year): ");
                scanf("%d", &sortChoice);
                getchar(); // Consume the newline character

                filterAndSortBooks(filterChoice, filter, sortChoice);
                break;
            case 5:
                reverseBookList();
                break;
            case 6:
                printf("Enter search choice (0 for title, 1 for author, 2 for ISBN): ");
                scanf("%d", &searchChoice);
                getchar(); // Consume the newline character

                printf("Enter search value: ");
                fgets(searchValue, SEARCH_LENGTH, stdin);
                searchValue[strcspn(searchValue, "\n")] = '\0';

                searchBooks(searchChoice, searchValue);
                break;
            case 7:
                printf("Enter ISBN: ");
                fgets(isbn, ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; // Remove trailing newline character

                borrowBook(isbn);
                break;
            case 8:
                printf("Enter ISBN: ");
                fgets(isbn, ISBN_LENGTH, stdin);
                isbn[strcspn(isbn, "\n")] = '\0'; // Remove trailing newline character

                returnBook(isbn);
                break;
            case 9:
                printf("Enter student ID: ");
                scanf("%d", &method);
                getchar(); // Consume the newline character

                displayBorrowedBooks(method);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}
