#include <stdlib.h>
#include <stdio.h>
#define MAX 5

int A[MAX];
int last;

// UDFS DECLARE
void init();
void add(int x);
int isfull();
int isempty();
int find(int x);
void del(int x);
void display();
int menu();

void init() {
    last = -1;
}

int isfull() {
    return (last == MAX - 1);
}

int isempty() {
    return (last == -1);
}

void add(int x) {
    if (isfull()) {
        printf("Array is Full\n");
        system("pause");
    } else {
        last++;
        A[last] = x;
    }
}

int find(int x) {
    int i;
    for (i = 0; i <= last; i++) {
        if (x == A[i]) {
            return i;
        }
    }
    return -1;
}

void del(int x) {
    int i, p;
    if (isempty()) {
        printf("Array is empty\n");
        system("pause");
    } else {
        p = find(x);
        if (p < 0) {
            printf("Not found\n");
            system("pause");
        } else {
            for (i = p; i < last; i++) {
                A[i] = A[i + 1];
            }
            last--;
        }
    }
}

void display() {
    int i;
    system("cls");
    printf("The array contains:\n");
    for (i = 0; i <= last; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }
    system("pause");
}

int menu() {
    int op;
    system("cls");
    printf("Menu\n");
    printf("1. Add\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Select (1-4): ");
    scanf("%d", &op);
    return op;
}

int main() {
    int x;
    init();
    while (1) {
        switch (menu()) {
            case 1:
                system("cls");
                printf("Input x: ");
                scanf("%d", &x);
                add(x);
                break;

            case 2:
                system("cls");
                printf("Input x: ");
                scanf("%d", &x);
                del(x);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid option\n");
                system("pause");
        }
    }
    return 0;
}