#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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
int score[MAX][MAX];
int last;

void init();
int menu();
int game_menu();
void sign_up();
void log_in();
int locate(char n[50]);
void game();
void easy();
void medium();
void hard();
void leaderboard();

int main(){
    int opt;
    char p_int[50];
    char u_int[50];
    init();
    leaderboard();
    system("pause");

    while(1){
        system("cls");
        switch(menu()){
            case 1:
                sign_up();
                break;
            case 2:
                log_in();
                break;
            case 3:
                leaderboard();
                break;
            case 4:
                exit(0);
            default:
                printf("choose 1-3 only!");
printf("%d", last);
    system("pause");
        } system("pause");
    }

    return 0;
}

int menu(){
    int op;
    printf("1. Sign up\n");
    printf("2. Log in\n");
    printf("3. Leaderboard\n");
    printf("4. Exit\n");
    printf("Enter 1-3 to choose\n");
    scanf("%d", &op);
    return op;
}

int game_menu(){
    int opt;
    printf("==========Choose difficulty==========");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Exit\n");
    scanf("%d", &opt);
    return opt;
}

void sign_up(){
    last++;
    printf("Create username: ");
    scanf(" %[^\n]s", user[last]);
    printf("Create password: ");
    scanf(" %[^\n]s", pass[last]);
}

void log_in(){
    int exist=0;
    char u_int[50];
    char p_int[50];

    printf("\n\nEnter username: ");
    scanf(" %[^\n^]s", u_int);
    printf("Enter password: ");
    scanf(" %[^\n]s", p_int);

    for(int i=0; i<=last; i++){
        if(strcasecmp(user[i], u_int)==0){
            if(strcasecmp(pass[locate(u_int)], p_int)==0){
                exist == 1;
                printf("Log in succesfully....\n");
                return;
            }
            else{
                printf("Wrong password\n");
                return;
                }
            }
    }
    if(exist != 1)
        printf("User does not exist\n");
    getch();
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


void game(){
    char sel;
    while(1){
        printf("Do you want to play?\ny/n");
        scanf("%c", &sel);
        if(sel=='y'){
            switch(game_menu()){
                case 1:
                    easy();
                    break;
                case 2:
                    medium();
                    break;
                case 3:
                    hard();
                    break;
                case 4:
                    exit(0);
            }
        } else return;
    }
}

void easy(){
    int a, b, c, d, ans ,cor ,score, times=5;
    srand(time(NULL));
    for(int i=0; i<times; i++){
        a = rand()%10+1;
        b = rand()%10+1;
        c = rand()%2+1;
        if(c==1){
            printf("%d+%d?\t", a,b);
            scanf("%d", &ans);
            if(ans == a+b){
                printf("corret~~\n\n");
                cor++;
            }
            else
                printf("Wrong!\n\n");
        }
        if(c==2){
            if(b>a){
                d=a;
                a=b;
                b=d;
            }
            printf("%d-%d?\t", a,b);
            scanf("%d", &ans);
            if(ans == a-b){
                printf("corret~~\n\n");
                cor++;
            }
            else
                printf("Wrong!\n\n");
        }
    }
    printf("You've got %d/5", cor);
}

void leaderboard(){
    printf("=====Leaderboard=====\n");
        printf("Top\tName\t\tPassword\n");
        for(int i=0; i<=last; i++){
            if(i==0) printf("%d.\t\e[0;93m%s\e[0m\t%s\n", i+1, user[i], pass[i]);
            else if(i>0 && i<4) printf("%d.\t%s\et%s\n", i+1, user[i], pass[i]);
            else if (i>3) printf("%d.\e[0;90m\t%s\t%s\n\e[0m;",i+1, user[i], pass[i]);
            }
    printf("=====================\n");
}
