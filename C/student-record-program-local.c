#include <stdio.h>
#include <stdlib.h>
#define MAX 3

float computeAve(int a, int b, int c);
void getRec(char n[][31], int q1[], int q2[], int q3[], float ave[]);
void displayRec(char n[][31], int q1[], int q2[], int q3[], float ave[]);

int main(){
    char name[MAX][31];
    float ave[MAX];
    int q1[MAX], q2[MAX], q3[MAX];
    getRec(name, q1, q2, q3, ave);
    displayRec(name, q1, q2, q3, ave);
return 0;
}

void getRec(char n[][31], int q1[], int q2[], int q3[], float ave[]){
    for(int i=0; i<MAX; i++){
        printf("Enter name: ");
        scanf(" %[^\n]", n[i]);
        printf("Enter Quiz 1 Score: ");
        scanf("%d", &q1[i]);
        printf("Enter Quiz 2 Score: ");
        scanf("%d", &q2[i]);
        printf("Enter Quiz 3 Score: ");
        scanf("%d", &q3[i]);
        ave[i]= computeAve(q1[i], q2[i], q3[i]);
    }
}

float computeAve(int a, int b, int c){
    return (a+b+c) / 3.0;
}

void displayRec(char n[][31], int q1[], int q2[], int q3[], float ave[]){
    printf("Name\t\t Quiz 1\t\t Quiz 2\t\t Quiz 3\t\t Average\t\t Remarks\n");
    for(int i=0; i<MAX; i++){
        printf("%d.) %s\t\t %d\t\t %d\t\t %d\t\t %6.2f\t\t\t", i+1, n[i], q1[i], q2[i], q3[i], ave[i]);
        if(ave[i] >= 75.0){
            printf("Passed\n");
        }else{
            printf("Fail\n");
        }
    }
}

