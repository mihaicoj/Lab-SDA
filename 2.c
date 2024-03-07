#include <stdio.h>
#include <stdlib.h>

typedef struct Book_Collection{
    int book_id;
    char author[50];
    char book_name[50];
    int release_year;
    char release_country[30];
}Collection;


void read_book( Collection *array){
          
        printf("Enter the book ID: \n");
        scanf("%d", &array->book_id);
        printf("What s the author of the book?: ");
        scanf("%s", array->author);
        printf("Book Name: ");
        scanf("%s", array->book_name);
        printf("Release Year: ");
        scanf("%d", &array->release_year);
        printf("Release Country: ");
        scanf("%s", array->release_country);

    }

void read_library(Collection **array, int *array_size){
   
    printf("How many books will be in the library? \n");
    scanf("%d", array_size);

    *array = (Collection *) malloc(*array_size * sizeof(Collection));

    for(int i =0; i <*array_size; i++) {
        printf("Enter ID for book number %d: \n", i+1);

        read_book(&(*array)[i]);
    }

}

void show_library(Collection *array, int array_size){
    printf("The books from the library are: \n");
    for(int i = 0; i < array_size; i++){
        printf(" Book ID: %d |Book Name: %s | Author: %s | Release Year: %d | Release Country: %s \n", array[i].book_id, array[i].book_name, array[i].author, array[i].release_year, array[i].release_country);

    }
}

void find_by_ID(Collection *array, int array_size){
    int found = 0;
    int ID_search;
    printf("What s the Book ID you are searching? ");
    scanf("%d", &ID_search);
    for(int i = 0; i < array_size; i++) {

        if(array[i].book_id == ID_search){
            found = 1;
            printf("The book was found. \n");
            break;
        } else {printf("The book was not found \n"); }


    }
}

void free_memory(Collection *array, int array_size) {

   free(array);
}

void sort(Collection *array, int array_size){
    Collection temp;
    for(int i = 0; i< array_size - 1; i++){
        for (int j = 0; j < array_size - i - 1; j++) {
            if(array[j].book_id > array[j + 1].book_id){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Book ID. \n");
    for (int i = 0; i < array_size; i++) {
        printf("Book ID: %d |Book Name: %s | Author: %s \n", array[i].book_id, array[i].book_name, array[i].author);
    }
}

void insert_end(Collection **array, int *array_size){

    int n;
    printf("How many books you want to insert? ");
    scanf("%d", &n);
    *array_size += n;
    *array = (Collection *)realloc(*array, *array_size * sizeof(Collection));

    for (int i = *array_size - n; i < *array_size; i++) {
        printf("Enter the book ID: \n");
        scanf("%d", &((*array)[i].book_id));
        printf("What s the author of the book?: ");
        scanf("%s", (*array)[i].author);
        printf("Book Name: ");
        scanf("%s", (*array)[i].book_name);
        printf("Release Year: ");
        scanf("%d", &((*array)[i].release_year));
        printf("Release Country: ");
        scanf("%s", (*array)[i].release_country);
    }
}

void insert_start(Collection **array, int *array_size) {
    int n;
    printf("How many books do you want to insert? ");
    scanf("%d", &n);
    *array_size += n;
    *array = (Collection *)realloc(*array, *array_size * sizeof(Collection));

    for (int i = *array_size - 1; i >= n; i--) {
        (*array)[i] = (*array)[i - n];
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the book ID: ");
        scanf("%d", &((*array)[i].book_id));
        printf("Author: ");
        scanf("%s", (*array)[i].author);
        printf("Book Name: ");
        scanf("%s", (*array)[i].book_name);
        printf("Release Year: ");
        scanf("%d", &((*array)[i].release_year));
        printf("Release Country: ");
        scanf("%s", (*array)[i].release_country);
    }
    printf("Insertion at the beginning successful.\n");
}


void insert_x(Collection **array, int *array_size) {

    int n;
    printf("At what position do you want to insert? ");
    scanf("%d", &n);

    (*array_size)++;
    *array = (Collection *)realloc(*array, *array_size * sizeof(Collection));

    for (int i = *array_size - 1; i >= n; i--) {
        *array[i + 1] = *array[i];
    }
    printf("Enter the book ID: \n");
        scanf("%d", &((*array)[n].book_id));
        printf("What s the author of the book?: ");
        scanf("%s", (*array)[n].author);
        printf("Book Name: ");
        scanf("%s", (*array)[n].book_name);
        printf("Release Year: ");
        scanf("%d", &((*array)[n].release_year));
        printf("Release Country: ");
        scanf("%s", (*array)[n].release_country);
}

void delete_x(Collection **array, int *array_size) {

    int n;
    printf("What ID you want to delete?");
    scanf("%d", &n);

    for (int i = n - 1; i < *array_size - 1; i++) {
        *array[i] = *array[i + 1];
    }

    (*array_size)--;
    *array = (Collection *)realloc(*array, *array_size * sizeof(Collection));

    printf("Deleted.\n");

}

void menu(){
     int option;
     int array_size = 0;
     Collection *array;
    
    do{
       printf("\n1. Insert. \n");
       printf("2. Displaying elements. \n");
       printf("3. Search an element by ID. \n");
       printf("4. Free memory. \n");
       printf("5. Sort elements by ID. \n");
       printf("6. Insert a new element at the end. \n");
       printf("7. Insert a new element at the beginning. \n");
       printf("8. Insert an element at position X. \n");
       printf("9. Delete an element from position X. \n");
       printf("0. Exit. \n");
       printf("Choose an option: ");
       scanf("%d", &option);

        switch(option){
            case 1:
            read_library(&array, &array_size);
            break;
            case 2:
            show_library(array, array_size);
            break;
            case 3:
            find_by_ID(array, array_size);
            break;
            case 4:
            free_memory(array, array_size);
            break;
            case 5:
            sort(array, array_size);
            break;
            case 6:
            insert_end(&array, &array_size);
            break;
            case 7:
            insert_start(&array, &array_size);
            break;
            case 8:
            insert_x(&array, &array_size);
            break;
            case 9:
            delete_x(&array, &array_size);
            break;
            case 0:
            printf("End \n");
            break;
        }
    } while (option != 0);
}

int main() {
   
   menu();
   
    return 0;
}