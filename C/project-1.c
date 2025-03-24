#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 15
/*A simple arithmetic program with the following
1. Log-in/Sign up feature: username, password.
2. Leader board - upon logging in the leader board will be shown. there should also be a feature where user can view the leaderboard.
3. use parallel arrays to store player records, data will be stored upon exit.
*/

char user[MAX][50];
char pass[MAX][50];
int totpts[MAX];
int last;
int current_user;

void init();
int menu();
int game_menu();
void sign_up();
int log_in();
int is_full();
int is_dup();
int locate(char n[50]);
void game(int n);
int add(int n);
int sub(int n);
int divi(int n);
int multi(int n);
int easy();
int medium();
int hard();
void sort();
void leaderboard();
void save();
void retrieve();

int main(){
    int opt, n;
    char p_int[50];
    char u_int[50];
    init();
    retrieve();
    leaderboard();
    system("pause");

    while(1){
        system("cls");
        switch(menu()){
            case 1:
                sign_up();
                break;
            case 2:
                n = log_in();
                game(n);
                break;
            case 3:
                system("cls");
                leaderboard();
                break;
            case 4:
                save();
                exit(0);
            default:
                printf("choose 1-4 only!");
        } system("pause");
    }

    return 0;
}

int menu(){
    int op;
    printf("1. Sign up\n");
    printf("2. Log in\n");
    printf("3. Leader board\n");
    printf("4. Exit\n");
    printf("Enter 1-3 to choose\n");
    scanf("%d", &op);
    return op;
}

int game_menu(){
    int opt;
    printf("==========Choose difficulty==========\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Exit\n");
    scanf("%d", &opt);
    return opt;
}

void init(){
    last = -1;
}

int locate(char n[50]){
    for(int i=0; i<=last; i++){
        if(strcasecmp(user[i], n)==0)
            return i;
    }
}

int is_full(){
        return (last == MAX-1);
}

int is_dup(char n[]){
    for(int i=0; i<=last; i++){
        if(strcasecmp(n, user[i])==0){
            return 1;}
    } return 0;
}

void sign_up(){
    char u[50];
    system("cls");
    printf("Create a user name: ");
    scanf(" %[^\n]s", u);
    if(is_dup(u)==1){
        printf("User already exist.\n");
        return;
    } else if(is_full()){
        printf("Maximum users reached.....\n");
        return;
    } else{
    last++;
    strcpy(user[last], u);
    printf("Create password: ");
    scanf(" %[^\n]s", pass[last]);
    totpts[last] = 0;
    }
}

int log_in(){
    int exist=0;
    char u_int[50];
    char p_int[50];

    system("cls");
    printf("Enter username: ");
    scanf(" %[^\n^]s", u_int);
    printf("Enter password: ");
    scanf(" %[^\n]s", p_int);

    for(int i=0; i<=last; i++){
        if(strcasecmp(user[i], u_int)==0){
            if(strcasecmp(pass[locate(u_int)], p_int)==0){
                exist == 1;
                printf("Log in succesfully....\n");
                system("pause");
                current_user = locate(u_int);
                return 1;
            }
            else{
                printf("Wrong password\n");
                return 0;
                }
            }
    }
    if(exist != 1)
        printf("User does not exist\n");
 }

void game(int n){
    char sel;
    if(n==1){
        system("cls");
        leaderboard();
        printf("Do you want to play?\ny/n:\t");
        scanf(" %c", &sel);
        if(sel=='y'){
            while(1){
                sort();
                system("cls");
                printf("==========Player %s==========\n", user[current_user]);
                switch(game_menu()){
                    case 1:
                        system("cls");
                        printf("=====Player %s=====\n", user[current_user]);
                        totpts[current_user] += easy();
                        break;
                    case 2:
                        system("cls");
                        printf("=====Player %s=====\n", user[current_user]);
                        totpts[current_user] += medium();
                        break;
                    case 3:
                        system("cls");
                        printf("=====Player %s=====\n", user[current_user]);
                        totpts[current_user] += hard();
                        break;
                    case 4:
                        system("cls");
                        leaderboard();
                        return;
            }
            }
        }else return;
    } else return;
}

int add(int n){
    int i, c=0, a, b, ans;
    a = rand() %n + 1;
    b = rand() %n + 1;
    printf("\nWhat is %d + %d?\t", a, b);
    scanf("%d", &ans);
    if(ans == a+b){
        printf("Correct!\n");
        c+=10;
    } else
        printf("Wrong! The right answer is %d\n", a+b);
    return c;
}

int sub(int n){
    int i, c=0, a, b, d, ans;
    a = rand() %n + 1;
    b = rand() %n + 1;
    if(b>a){
            d=a;
            a=b;
            b=d;
    }
    printf("\nWhat is %d - %d?\t", a, b);
    scanf("%d", &ans);
    if(ans == a-b){
        printf("Correct!\n");
        c+=10;
    } else
        printf("Wrong! The right answer is %d\n", a-b);
    return c;
}

int divi(int n){
    int i, c = 0, a, b, ans;
    do{
        a = rand() %n + 1;
        b = rand() %n + 1;
    }while(a%b != 0);

    printf("\nWhat is %d / %d? ", a, b);
    scanf("%d", &ans);

    if(ans == a/b){
        printf("Correct!\n");
        c+=10;
    } else
        printf("Wrong! The right answer is %d\n", a/b);
    return c;
}

int multi(int n){
    int i, c = 0, a, b, ans;
    a = rand() %n + 1;
    b = rand() %n + 1;
    printf("\nWhat is %d * %d? ", a, b);
    scanf("%d", &ans);
    if(ans == a*b){
        printf("Correct!\n");
        c+=10;
    } else {
        printf("Wrong! The right answer is %d\n", a*b);
    } return c;
}

int easy(){
    int c, pts=0;
    srand(time(NULL));
    for(int i=0; i<5; i++){
    c = rand() %4+1;
        if(c==1)
            pts += add(10);
        if(c==2)
            pts += sub(10);
        if(c==3)
            pts += divi(10);
        if(c==4)
            pts += multi(10);
    } printf("\nYou've got %d/50 pts\n", pts);
    system("pause");
    return pts;
}

int medium(){
    int c, pts=0, totpts=0;
    srand(time(NULL));
    for(int i=0; i<5; i++){
    c = rand() %4+1;
        if(c==1)
            pts += 2*add(50);
        if(c==2)
            pts += 2*sub(50);
        if(c==3)
            pts += 2*divi(50);
        if(c==4)
            pts += 2*multi(50);
    }
    printf("\nYou've got %d/100 pts\n", pts);
    system("pause");
    return pts;
}

int hard(){
    int c, pts=0, totpts=0;
    srand(time(NULL));
    for(int i=0; i<5; i++){
    c = rand() %4+1;
        if(c==1)
            pts += 3*add(100);
        if(c==2)
            pts += 3*sub(100);
        if(c==3)
            pts += 3*divi(100);
        if(c==4)
            pts += 3*multi(100);
    } printf("\nYou've got %d/150 pts\n", pts);
    system("pause");
    return pts;
}

void sort(){
    int i, j, temp;
    char user_temp[50];
    char pass_temp[50];
    for(i=0; i<=last; i++){
        for(j=0; j<last-i; j++){
            if(totpts[j]<totpts[j+1]){
                strcpy(user_temp, user[j]);
                strcpy(user[j], user[j+1]);
                strcpy(user[j+1], user_temp);
                strcpy(pass_temp, pass[j]);
                strcpy(pass[j], pass[j+1]);
                strcpy(pass[j+1], pass_temp);
                temp = totpts[j];
                totpts[j] = totpts[j+1];
                totpts[j+1] = temp;
            }
        }
    }
}

void leaderboard(){
    printf("=====Leaderboard=====\n");
        printf("Top\tName\t\tPoints\n");
        for(int i=0; i<=last; i++){
            sort();
            printf("%d.\t%s\t\t%d\t\n",i+1, user[i], totpts[i]);
            }
    printf("=====================\n");
}

void save(){
    FILE *fp;
    int i;
    fp = fopen("user_data.txt", "w+");
    if(fp==NULL){
        printf("File error.....\n");
        system("pause");
    }else{
        for(i=0; i<=last; i++){
            fprintf(fp, "%s\t%s\t%d\n", user[i], pass[i], totpts[i]);
        }
    }
    fclose(fp);
}

void retrieve() {
    FILE *fp;
    fp = fopen("user_data.txt", "r");
    if (fp == NULL) {
        printf("File error.....\n");
        return;
    }
    while (fscanf(fp, "%s\t%s\t%d\n", user[last + 1], pass[last + 1], &totpts[last + 1]) == 3) {
        last++;
    }
    fclose(fp);
}


