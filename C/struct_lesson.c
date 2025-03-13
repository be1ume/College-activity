#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5

typedef struct record{
char name[31];
int q1, q2, q3;
}REC;
REC sr[MAX];

int last = -1;

void add(REC x);
int find(char n[]);
void update(char n[]);
void del(char n[]);
int menu();
void display();

int main(){
    char n[31];
    REC temp;
    while(1){
        switch(menu()){
            case 1:
                system("cls");
                printf("Enter name: "); scanf(" %[^\n]s", temp.name);
                printf("Enter quiz 1: "); scanf("%d", &temp.q1);
                printf("Enter quiz 2: "); scanf("%d", &temp.q2);
                printf("Enter quiz 3: "); scanf("%d", &temp.q3);
                add(temp);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Enter name you want to update:\t"); scanf(" %[^\n]s", n);
                update(n);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Enter name to delete:\t"); scanf(" %[^\n]s", n);
                del(n);
                system("pause");
                break;

            case 4:
                system("cls");
                display();
                system("pause");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter valid option! choose 1-4 only!");
        } system("cls");
    }
}

int menu(){
    int op;
    printf("1. add\n2. update\n3. delete\n4. display\n5. Exit\n");
    scanf("%d", &op);
    return op;
}

void add(REC x){
    last++;
    sr[last] = x;
}

int find(char n[31]){
    for(int i=0; i<=last; i++){
        if(strcmp(n, sr[i].name)==0)
            return i;
    } return -1;
}

void update(char n[]){
    int p = find(n);
    int op;
    if(p<0)
        printf("Not found!");
    else{
        do{
            printf("Select 1-3 for q1-3 else 4 to exit.");
            scanf("%d", &op);
        switch(op){
            case 1:
                printf("Enter new value for quiz 1: "); scanf("%d", &sr[p].q1); break;
            case 2:
                printf("Enter new value for quiz 2: "); scanf("%d", &sr[p].q2); break;
            case 3:
                printf("Enter new value for quiz 3: "); scanf("%d", &sr[p].q3); break;
            case 4:
                break;
            default:
                printf("Enter valid option 1-4");
            }
        }while(op!=4);
    }
}

void del(char n[]){
    int p = find(n);
    if(p<0)
        printf("Not found!");
    else{
        for(int i=p; i<last; i++)
            sr[i] = sr[i+1];
        last--;
    }
}

void display(){
    for(int i=0; i<=last; i++){
        printf("%d. %s\t\t%d\t%d\t%d\t", i+1, sr[i].name, sr[i].q1, sr[i].q2, sr[i].q3);
        printf("\n");
    }
}
