#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[50], author[50];
    float price;
    int available;
};

struct Book b[100];
int n = 0;

void addBook() {
    printf("Enter ID, Title, Author, Price: ");
    scanf("%d %s %s %f", &b[n].id, b[n].title, b[n].author, &b[n].price);
    b[n].available = 1;
    n++;
}

void display() {
    int i;
    for(i = 0; i < n; i++)
        printf("%d %s %s %.2f %s\n", b[i].id, b[i].title, b[i].author,
               b[i].price, b[i].available ? "Available" : "Issued");
}

void issue() {
    int id, i;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
        if(b[i].id == id) {
            if(b[i].available) {
                b[i].available = 0;
                printf("Book issued successfully\n");
            } else
                printf("Book already issued\n");
            return;
        }
    printf("Book not found\n");
}

void returnBook() {
    int id, i;
    printf("Enter Book ID: ");
    scanf("%d", &id);

    for(i = 0; i < n; i++)
        if(b[i].id == id) {
            b[i].available = 1;
            printf("Book returned successfully\n");
            return;
        }
    printf("Book not found\n");
}

int main() {
    int ch;

    do {
        printf("\n1.Add  2.Display  3.Issue  4.Return  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: addBook(); break;
            case 2: display(); break;
            case 3: issue(); break;
            case 4: returnBook(); break;
        }
    } while(ch != 5);

    return 0;
}