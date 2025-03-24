#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 15

char user[MAX][50];
char pass[MAX][50];
int totpts[MAX];
int e_score[MAX], m_score[MAX], h_score[MAX];
int last;
int current_user;
float ave;

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
float average(int e, int m, int h);

int main(){
    int opt, n;
    char p_int[50];
    char u_int[50];
    init();
    retrieve();

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
    printf("========================================\n");
    printf("|              MAIN MENU               |\n");
    printf("========================================\n");
    printf("     1. Sign up                       \n");
    printf("     2. Log in                        \n");
    printf("     3. Leader board                  \n");
    printf("     4. Exit                          \n");
    printf("     Enter 1-4 to choose              \n");
    printf("========================================\n->");
    scanf("%d", &op);
    return op;
}

int game_menu(){
    int opt;
    printf("========================================\n");
    printf("|           Choose difficulty          |\n");
    printf("========================================\n");
    printf("  USER: %s \n  Easy: %d\tMedium: %d\tHard: %d\n", user[current_user], e_score[current_user], m_score[current_user], h_score[current_user]);
    printf("     \e[32m1. Easy\e[0m\n");
    printf("     \e[38;5;208m2. Medium\e[0m\n");
    printf("     \e[31m3. Hard\e[0m\n");
    printf("     4. Exit\n");
    printf("========================================\n->");
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
    e_score[last] = 0;
    m_score[last] = 0;
    h_score[last] = 0;
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
                printf("Wrong password.....\n");
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
                system("cls");
                switch(game_menu()){
                    case 1:
                        system("cls");
                        e_score[current_user] = easy();
                        break;
                    case 2:
                        system("cls");
                        m_score[current_user] = medium();
                        break;
                    case 3:
                        system("cls");
                        h_score[current_user] = hard();
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
    printf("\nWhat is %d + %d?\n->", a, b);
    scanf("%d", &ans);
    if(ans == a+b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a+b);
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
    printf("\nWhat is %d - %d?\n->", a, b);
    scanf("%d", &ans);
    if(ans == a-b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a-b);
    return c;
}

int divi(int n){
    int i, c = 0, a, b, ans;
    do{
        a = rand() %n + 1;
        b = rand() %n + 1;
    }while(a%b != 0);

    printf("\nWhat is %d / %d?\n->", a, b);
    scanf("%d", &ans);

    if(ans == a/b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a/b);
    return c;
}

int multi(int n){
    int i, c = 0, a, b, ans;
    a = rand() %n + 1;
    b = rand() %n + 1;
    printf("\nWhat is %d * %d?\n->", a, b);
    scanf("%d", &ans);
    if(ans == a*b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else {
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a*b);
    } return c;
}

int easy(){
    int c, pts=0, temp;
    srand(time(NULL));
    for(int i=0; i<1;){
    c = rand() %4+1;
        if(c==1){
            temp = 1*add(10);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==2){
            temp = 1*sub(10);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==3){
            temp = 1*divi(10);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==4){
            temp = 1*multi(10);
            if(temp==0)
                break;
            else
                pts += temp;
            }

    } printf("\nYou've got %d pts\n", pts);
    system("pause");
    if(pts>e_score[current_user])
        return pts;
}

int medium(){
    int c, pts=0, temp;
    srand(time(NULL));
    for(int i=0; i<1;){
    c = rand() %4+1;
        if(c==1){
            temp = 2*add(50);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==2){
            temp = 2*sub(50);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==3){
            temp = 2*divi(50);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==4){
            temp = 2*multi(50);
            if(temp==0)
                break;
            else
                pts += temp;
            }

    } printf("\nYou've got %d pts\n", pts);
    system("pause");
    if(pts>m_score[current_user])
        return pts;
}

int hard(){
    int c, pts=0, temp;
    srand(time(NULL));
    for(int i=0; i<1;){
    c = rand() %4+1;
        if(c==1){
            temp = 3*add(100);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==2){
            temp = 3*sub(100);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==3){
            temp = 3*divi(100);
            if(temp==0)
                break;
            else
                pts += temp;
            }
        if(c==4){
            temp = 3*multi(100);
            if(temp==0)
                break;
            else
                pts += temp;
            }

    } printf("\nYou've got %d pts\n", pts);
    system("pause");
    if(pts>h_score[current_user])
        return pts;
}

void sort(){
    int i, j, a, b, temp;
    char user_temp[50];
    char pass_temp[50];
    for(i=0; i<=last; i++){
        for(j=0; j<last-i; j++){
            a = average(e_score[j], m_score[j], h_score[j]);
            b = average(e_score[j+1], m_score[j+1], h_score[j+1]);
            if(a<b){
                strcpy(user_temp, user[j]);
                strcpy(user[j], user[j+1]);
                strcpy(user[j+1], user_temp);
                strcpy(pass_temp, pass[j]);
                strcpy(pass[j], pass[j+1]);
                strcpy(pass[j+1], pass_temp);
                temp = e_score[j];
                e_score[j] = e_score[j+1];
                e_score[j+1] = temp;
                temp = m_score[j];
                m_score[j] = m_score[j+1];
                m_score[j+1] = temp;
                temp = h_score[j];
                h_score[j] = h_score[j+1];
                h_score[j+1] = temp;
            }
        }
    }
}

float average(int e, int m, int h){
    return (e + m + h)/3.0;
}

void leaderboard(){
    printf("=====================\e[38;2;255;255;255mLEADERBOARD\e[0m=====================\n");
    printf("| Top | Name            Easy\tMedium\tHard\tXP  |\n");
    printf("=====================================================\n");
    for(int i=0; i<=last; i++){
        sort();
        if(i==0)
            printf("\e[38;2;255;255;0m   %d.\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else if(i==1)
            printf("\e[38;2;255;255;255m   %d.\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else if(i==2)
            printf("\e[38;5;180m   %d.\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else
            printf("\e[38;2;128;128;128m   %d.\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        }
     printf("=====================================================\n");
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
            fprintf(fp, "%s\t%s\t%d\t%d\t%d\n", user[i], pass[i], e_score[i], m_score[i], h_score[i]);
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
    while (fscanf(fp, "%s\t%s\t%d\t%d\t%d\n", user[last + 1], pass[last+1], &e_score[last+1], &m_score[last+1], &h_score[last+1]) == 5) {
        last++;
    }
    fclose(fp);
}


