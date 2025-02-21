//MARIANO, Luciano Martin BSCS-1A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

char name[MAX][MAX];
int quiz1[MAX], quiz2[MAX], quiz3[MAX];
int last;
float ave;

void init();
int isfull();
int isempty();
int locate(char n[]);
void del(char n[]);
void add(char n[],int q1, int q2, int q3);
float avg(int q1, int q2, int q3);
void upd_rec(char n[]);
void disp_rec(char n[]);
void disp_all();
int menu();
void save();
void retrieve();

int main(){
char n[31];
int q1, q2, q3;

init();
retrieve();
while(1){
    switch(menu()){
    case 1 : system("cls"); printf("Input Name: "); scanf(" %[^\n]",&n);
             printf("Input Quiz #1 Score: "); scanf("%d",&q1);
             printf("Input Quiz #2 Score: "); scanf("%d",&q2);
             printf("Input Quiz #3 Score: "); scanf("%d",&q3);
             add(n, q1, q2, q3);
             break;
    case 2 : system("cls"); printf("Input Student Name: "); scanf(" %[^\n]", n); upd_rec(n); break;
    case 3 : system("cls"); printf("Input Student Name: "); scanf("%s",&n); del(n); break;
    case 4 : disp_all(); break;
    case 5 : system("cls"); printf("Input Student name: "); scanf(" %[^\n]", n); disp_rec(n); break;
    case 6 : save();exit(0);
    default: printf("\n1 to 6 only.\nError rerun the code!\n");system("pause");
} } return 0; }

int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Add A Record\n");
printf("2. Update A Record\n");
printf("3. Delete a Record\n");
printf("4. Display All\n");
printf("5. Display A Record\n");
printf("6. Exit\n");
printf("\nSelect(1-6): ");
scanf("%d",&op);
return op;
}

void init(){
 last = -1;
}

int isfull(){
return (last==MAX-1);
}

int isempty(){
return (last==-1);
}

int locate(char n[]){
int i;
for (i=0;i<=last;i++){
    if (strcmp(n,name[i])==0)
        return i;
  }
return -1;
}

void add(char n[], int q1, int q2, int q3){
    int i, j, sortQ1, sortQ2, sortQ3;
    char sortName[MAX];
    if (isfull()){
        printf("Array is full.\n");
        system("pause");
    }
    else if (locate(n) != -1) {
        printf("Error! It is already recorded\n");
        system("pause");
    }
    else {
        last++;
        strcpy(name[last], n);
        quiz1[last] = q1;
        quiz2[last] = q2;
        quiz3[last] = q3;

        for (i = 0; i <= last; i++) {
            for (j = 0; j < last - i; j++) {
                if (strcmp(name[j], name[j + 1]) > 0) {
                    strcpy(sortName, name[j]);
                    strcpy(name[j], name[j + 1]);
                    strcpy(name[j + 1], sortName);

                    sortQ1 = quiz1[j];
                    quiz1[j] = quiz1[j + 1];
                    quiz1[j + 1] = sortQ1;

                    sortQ2 = quiz2[j];
                    quiz2[j] = quiz2[j + 1];
                    quiz2[j + 1] = sortQ2;

                    sortQ3 = quiz3[j];
                    quiz3[j] = quiz3[j + 1];
                    quiz3[j + 1] = sortQ3;
                }
            }
        }
}}

void upd_rec(char n[]) {
    int op, p;
    p = locate(n);
    if(isempty()){
    printf("Array is empty.\n");
    system("pause");
    }else {
    if(p < 0) {
        printf("Not found.\n");
        system("pause");
    } else {
        do {
            ave = avg(quiz1[p], quiz2[p], quiz3[p]);
            printf("Updating Record for: %s, Average: %6.2f\n", name[p], ave);
            printf("1. Quiz#1: %d\n", quiz1[p]);
            printf("2. Quiz#2: %d\n", quiz2[p]);
            printf("3. Quiz#3: %d\n", quiz3[p]);
            printf("4. Return to Menu\n");
            printf("\nSelect(1-4): ");
            scanf("%d", &op);
            switch (op) {
                case 1 : printf("Enter new Quiz 1 score: "); scanf("%d", &quiz1[p]); system("cls"); break;
                case 2 : printf("Enter new Quiz 2 score: "); scanf("%d", &quiz2[p]); system("cls"); break;
                case 3 : printf("Enter new Quiz 3 score: "); scanf("%d", &quiz3[p]); system("cls"); break;
                case 4 : break;
                default: printf("Invalid choice.\n"); system("pause"); system("cls");
            }} while (op != 4); system("pause"); }
    }}

void del(char n[]){
int p, i;
if (isempty()){
    printf("Array is empty.\n");
    system("pause");
 }
else {
    p = locate(n);
    if (p<0){
        printf("Not found.\n");
        system("pause");
      }
    else {
        for (i=p;i<last;i++){
            strcpy(name[i],name[i+1]);
            quiz1[i] = quiz1[i+1];
            quiz2[i] = quiz2[i+1];
            quiz3[i] = quiz3[i+1];
        }
        last--;
        printf("Record of %s is successfully deleted.\n",n);
        system("pause");
    }
}
}

float avg(int q1, int q2, int q3){
    return (q1 + q2 + q3) / 3.0;
}

void disp_all(){
int i;
system("cls");
printf("  NAME\t\t\tQUIZ#1\tQUIZ#2\tQUIZ#3\tAVERAGE\tREMARKS\n");
for (i=0; i<=last; i++){
        ave = avg(quiz1[i],quiz2[i],quiz3[i]);
        printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t%s\n", i+1, name[i], quiz1[i], quiz2[i], quiz3[i], ave, ave>=75? "PASSED":"FAILED");
}

system("pause");
}

void disp_rec(char n[]){
int p;
p=locate(n);
system("cls");
if(isempty()){
    printf("Array is empty.\n");
    system("pause");
}else {
    if(p<0){
        printf("Record not found\n");
        system("pause");
    }else {
        ave = avg(quiz1[p], quiz2[p], quiz3[p]);
        printf("Student Record:\nName: %s\nQuiz#1: %d\nQuiz#2: %d\nQuiz#3: %d\nAverage: %6.2f\nRemark: %s\n", name[p], quiz1[p], quiz2[p], quiz3[p], ave, ave>=75? "PASSED":"FAILED");
    system("pause");
}}}

void save(){
FILE *fp;
int i;
fp = fopen("BSCS1A-record.txt","w+");
if (fp==NULL){
    printf("File Error.\n");
    system("pause");
}
else {
    for(i=0;i<=last;i++)
        fprintf(fp,"%s\n%d %d %d\n", name[i], quiz1[i], quiz2[i], quiz3[i]);
}
fclose(fp);
}

void retrieve(){
FILE *fp;
int quiz1, quiz2, quiz3;
char n[31];
fp = fopen("BSCS1A-record.txt","r+");
if (fp==NULL){
    printf("File Error.\n");
    system("pause");
 }
else {
    while (!feof(fp)){
        fscanf(fp,"%[^\n]\n%d\n%d\n%d\n",n,&quiz1, &quiz2, &quiz3);
        add(n, quiz1, quiz2, quiz3);
    }
}}

