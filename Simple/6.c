#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Book {
    int Accession_number;
    char Author_name[100];
    char title[100];
    int Issued;
};

int Addbook(struct Book Arr[], int n) {
    printf("Enter the book's Accession number: ");
    scanf("%d", &Arr[n].Accession_number);
    printf("Enter the book's Author name: ");
    getchar();
    fgets(Arr[n].Author_name, sizeof(Arr[n].Author_name), stdin);
    Arr[n].Author_name[strcspn(Arr[n].Author_name, "\n")] = '\0';
    printf("Enter the book's title: ");
    fgets(Arr[n].title, sizeof(Arr[n].title), stdin);
    Arr[n].title[strcspn(Arr[n].title, "\n")] = '\0';
    printf("\n");
    Arr[n].Issued = 1;
    return ++n;
}

void displayBookInfo(struct Book Arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n\t\tBook %d\n", i + 1);
        printf("book Accession number: %d\n", Arr[i].Accession_number);
        printf("book Author name: %s\n", Arr[i].Author_name);
        printf("book title: %s\n", Arr[i].title);
        if (Arr[i].Issued == 0) {
            printf("Book is issued\n");
        } else {
            printf("Book is not issued\n");
        }
    }
}

void Booksofauthor(struct Book Arr[], char Author[100], int n) {
    for (int i = 0; i < n; i++) {
        if ((strcmp(Arr[i].Author_name, Author) == 0) && (Arr[i].Issued == 1)) {
            printf("\n\nbook Accession number: %d\n", Arr[i].Accession_number);
            printf("book title: %s\n", Arr[i].title);
        }
    }
}

void Booksoftitle(struct Book Arr[], char title[100], int n) {
    for (int i = 0; i < n; i++) {
        if ((strcmp(Arr[i].title, title) == 0) && (Arr[i].Issued == 1)) {
            printf("\n\nbook Accession number: %d\n", Arr[i].Accession_number);
            printf("book author: %s\n", Arr[i].Author_name);
        }
    }
}

int displaytotalbooks(struct Book Arr[],int n){
    int k=0;
    for(int i=0;i<n;i++){
        if(Arr[i].Issued==1){
            k=k+1;
        }
    }
    return k;
}

void Issuebook(struct Book Arr[],int r,int n){
    for(int i=0;i<n;i++){
        if(Arr[i].Accession_number==r){
            Arr[i].Issued=0;
            printf("Book issued");
        }
    }
}

int main() {
    int n = 0;
    struct Book Arr[100];

    printf("Enter how many books to enter: ");
    int k;
    scanf("%d", &k);
    getchar();
    for (int l = 0; l < k; l++) {
        n = Addbook(Arr, n);
    }

    printf("\nEnter Author name to find books of the author  :");
    char author[100];
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = '\0';
    Booksofauthor(Arr, author, n);

    printf("\nEnter Book title to find author :");
    char title[100];
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    Booksoftitle(Arr, title, n);

    displaytotalbooks(Arr,n);

    printf("\nEnter the books Accession number  :");
    int r;
    scanf("%d",&r);
    Issuebook(Arr,r,n);
     
    printf("\n\nAll the books in the system2");
    displayBookInfo(Arr, n);
}
