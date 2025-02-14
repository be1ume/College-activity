#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

char name[MAX][MAX];
int quiz1[MAX], quiz2[MAX], quiz3[MAX];
int last;
float ave[MAX];

void init();
int isfull();
int isempty();
int locate(char n[]);
void del(char n[]);
void add(char n[],int q1, int q2, int q3);
float compAve(int q1, int q2, int q3);
void display();
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
    case 1 : system("cls");printf("Input Name: ");scanf(" %[^\n]",&n);
             printf("Input Quiz #1 Score: ");scanf("%d",&q1);
             printf("Input Quiz #2 Score: ");scanf("%d",&q2);
             printf("Input Quiz #3 Score: ");scanf("%d",&q3);
             add(n, q1, q2, q3);
             break;
    case 2 : system("cls");printf("Input Name: ");scanf("%s",&n);del(n);break;
    case 3 : display();break;
    case 4 : save();exit(0);
    default: printf("\n1 to 4 only.\nError rerun the code!\n");system("pause");
    }
}

return 0;

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

void add(char n[], int q1, int q2, int q3){
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
    ave[last] = compAve(q1, q2, q3);
}
}

int menu(){
int op;
system("cls");
printf("Menu\n");
printf("1. Add a Record\n");
printf("2. Delete a Record\n");
printf("3. Display All\n");
printf("4. Exit\n");
printf("\nSelect(1-4): ");
scanf("%d",&op);
return op;
}

float compAve(int q1, int q2, int q3){
    return (q1 + q2 + q3) / 3.0;
}

void display(){
int i;
system("cls");
printf("  NAME\t\t\tQUIZ#1\tQUIZ#2\tQUIZ#3\tAVERAGE\tREMARKS\n");
for (i=0; i<=last; i++)
    printf("%d.) %s\t\t%d\t%d\t%d\t%6.2f\t%s\n", i+1, name[i], quiz1[i], quiz2[i], quiz3[i], ave[i] ,ave[i]>=70? "PASSED":"FAILED");

system("pause");
}

void save(){
FILE *fp;
int i;
fp = fopen("bscs1a.txt","w+");
if (fp==NULL){
    printf("File Error.\n");
    system("pause");
}
else {
    for(i=0;i<=last;i++)
        fprintf(fp,"%s\n%d\n%d\n%d\n", name[i], quiz1[i], quiz2[i], quiz3[i]);
}
fclose(fp);
}

void retrieve(){
FILE *fp;
int quiz1, quiz2, quiz3;
char n[31];
fp = fopen("bscs1a.txt","r+");
if (fp==NULL){
    printf("File Error.\n");
    system("pause");
 }
else {
    while (!feof(fp)){
        fscanf(fp,"%[^\n]\n%d\n%d\n%d\n",n,&quiz1, &quiz2, &quiz3);
        add(n, quiz1, quiz2, quiz3);
    }
}

}
