//MARIANO, BSCS-1A

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10

char user[MAX][50];
char pass[MAX][50];
int e_score[MAX], m_score[MAX], h_score[MAX];
int add_score[MAX], sub_score[MAX], divi_score[MAX], multi_score[MAX];
int last;
int current_user;
char loggedInUsername[50];
float ave;

void init();
int menu();
int game_menu();
int arithmethic_menu();
void sign_up();
int log_in();
int is_full();
int is_dup();
int locate(char n[50]);
void game(int n);
int add(int n, int m);
int sub(int n, int m);
int divi(int n, int m);
int multi(int n, int m);
int easy();
int medium();
int hard();
void sort_in(int i, int j);
void sort();
void leaderboard();
void inner_leaderboard(char op);
void leaderboard_op(char op);
void l_add();
void l_sub();
void l_divi();
void l_multi();
void save();
void retrieve();
float average(int e, int m, int h);

int main(){
    char opt;
    int n;
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
                printf("View individual [y/n]:\t");
                scanf(" %c", &opt);
                inner_leaderboard(opt);
                break;
            case 4:
                printf("Saved successfully.....\n");
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
    printf("     1. Sign Up                       \n");
    printf("     2. Log In                        \n");
    printf("     3. Leaderboard                  \n");
    printf("     4. Save and Quit                 \n");
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
    printf("     \e[32m1. Easy     \e[0m(10 points)\n");
    printf("     \e[38;5;208m2. Medium   \e[0m(20 points)\n");
    printf("     \e[31m3. Hard     \e[0m(30 points)\n");
    printf("     4. Leaderboard\n");
    printf("     5. Save and Quit\n");
    printf("========================================\n->");
    scanf("%d", &opt);
    return opt;
}

int arithmethic_menu(){
    int opt;
    printf("========================================\n");
    printf("|           Choose Operation           |\n");
    printf("========================================\n");
    printf("  USER: %s\t\n  Add: %d\tSub: %d\tDiv: %d\tMul: %d\n", user[current_user], add_score[current_user], sub_score[current_user], divi_score[current_user], multi_score[current_user]);
    printf("     \e[33m1. Addition\e[0m\n");
    printf("     \e[34m2. Subtraction\e[0m\n");
    printf("     \e[32m3. Division\e[0m\n");
    printf("     \e[35m4. Multiplication\e[0m\n");
    printf("     5. Exit\n");
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
    }return -1;
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
    printf("===Sign Up to create an account===\n\n");
    printf("Create a user name: ");
    scanf(" %[^\n]s", u);
    if(is_dup(u)==1){
        printf("\nUser already exist.....\n");
        return;
    } else if(is_full()){
        printf("\nMaximum users reached.....\n");
        return;
    } else{
    last++;
    strcpy(user[last], u);
    printf("Create password: ");
    scanf(" %[^\n]s", pass[last]);
    printf("\nUser created successfully...\n");
    e_score[last] = 0;
    m_score[last] = 0;
    h_score[last] = 0;
    add_score[last] = 0;
    sub_score[last] = 0;
    divi_score[last] = 0;
    multi_score[last] = 0;
    }
}

int log_in(){
    int exist=0;
    char u_int[50];
    char p_int[50];

    system("cls");
    printf("===Log In to proceed the Game===\n\n");
    printf("Enter username: ");
    scanf(" %[^\n]s", u_int);

    if(locate(u_int) == -1){
        printf("\nUser does not exist.....\n");
        return 0;
    }
    printf("Enter password: ");
    scanf(" %[^\n]s", p_int);

    for(int i=0; i<=last; i++){
        if(strcasecmp(user[i], u_int)==0){
            if(strcasecmp(pass[locate(u_int)], p_int)==0){
                exist == 1;
                printf("\nLogged in succesfully.....\n");
                system("pause");
                current_user = locate(u_int);
                strcpy(loggedInUsername, user[current_user]);
                return 1;
            }
            else{
                printf("\nWrong password.....\n");
                return 0;
                }
            }
    }
 }

void game(int n){
    int opt;
    char sel;
    if(n==1){
        system("cls");
        leaderboard();
        printf("Do you want to play? [y/n]:\n->");
        scanf(" %c", &sel);
        if(sel=='y'){
            while(1){
                current_user = locate(loggedInUsername);
                system("cls");
                switch(game_menu()){
                    case 1:
                        system("cls");
                        e_score[current_user] += easy();
                        break;
                    case 2:
                        system("cls");
                        m_score[current_user] += medium();
                        break;
                    case 3:
                        system("cls");
                        h_score[current_user] += hard();
                        break;
                    case 4:
                        system("cls"); leaderboard();
                        printf("View individual operation? [y/n]:   ");
                        scanf(" %c", &opt);
                        leaderboard_op(opt);
                        break;
                    case 5:
                        system("cls");
                        leaderboard();
                        return;
            }
            }
        }else return;
    } else return;
}

int add(int n, int m){
    int i, c=0, a, b, ans;
    a = rand() %n + m;
    b = rand() %n + m;
    printf("\nWhat is %d + %d?\n->", a, b);
    scanf("%d", &ans);
    if(ans == a+b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a+b);
    return c;
}

int sub(int n, int m){
    int i, c=0, a, b, d, ans;
    a = rand() %n + m;
    b = rand() %n + m;
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

int divi(int n, int m){
    int i, c = 0, a, b, ans;
    do{
        a = rand() %n + m;
        b = rand() %n + 2;
    }while(a%b != 0 || a==b);

    printf("\nWhat is %d / %d?\n->", a, b);
    scanf("%d", &ans);

    if(ans == a/b){
        printf("\e[92mCorrect!\e[0m\n");
        c+=10;
    } else
        printf("\e[91mWrong!\e[0m The right answer is %d.\n", a/b);
    return c;
}

int multi(int n, int m){
    int i, c = 0, a, b, ans;
    a = rand() %n + m;
    b = rand() %n + m;
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
    int temp, pts=0;
    int opt = arithmethic_menu();
    system("cls");
    printf("Note! The operation wont stop until you get a wrong answer!\n");
    for(int i=0; i<1;){
    if(opt==1){
        temp = 1*add(10,1);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==2){
        temp = 1*sub(10,1);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==3){
        temp = 1*divi(10,1);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==4){
        temp = 1*multi(10,1);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==5)
        return 0;
}
    if(opt==1)
        add_score[current_user] += pts;
    if(opt==2)
        sub_score[current_user] += pts;
    if(opt==3)
        divi_score[current_user] += pts;
    if(opt==4)
        multi_score[current_user] += pts;
    printf("\n==== Game Over! Total score for the round: %d ====\n", pts);
    system("pause");
    return pts;
}

int medium(){
    int temp, pts=0;
    int opt = arithmethic_menu();
    system("cls");
    printf("Note! The operation wont stop until you get a wrong answer!\n");
    for(int i=0; i<1;){
    if(opt==1){
        temp = 2*add(50,11);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==2){
        temp = 2*sub(50,11);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==3){
        temp = 2*divi(50,11);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==4){
        temp = 2*multi(50,11);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==5)
        return 0;
}
    if(opt==1)
        add_score[current_user] += pts;
    if(opt==2)
        sub_score[current_user] += pts;
    if(opt==3)
        divi_score[current_user] += pts;
    if(opt==4)
        multi_score[current_user] += pts;
    printf("\n==== Game Over! Total score for the round: %d ====\n", pts);
    system("pause");
    return pts;
}

int hard(){
    int temp, pts=0;
    int opt = arithmethic_menu();
    system("cls");
    printf("Note! The operation wont stop until you get a wrong answer!\n");
    for(int i=0; i<1;){
    if(opt==1){
        temp = 3*add(100,21);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==2){
        temp = 3*sub(100,21);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==3){
        temp = 3*divi(100,21);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==4){
        temp = 3*multi(100,21);
        if(temp==0)
            break;
        else
            pts += temp;
    }else if(opt==5)
        return 0;
}
    if(opt==1)
        add_score[current_user] += pts;
    if(opt==2)
        sub_score[current_user] += pts;
    if(opt==3)
        divi_score[current_user] += pts;
    if(opt==4)
        multi_score[current_user] += pts;
    printf("\n==== Game Over! Total score for the round: %d ====\n", pts);
    system("pause");
    return pts;
}

void sort_in(int i, int j){
    char user_temp[50];
    char pass_temp[50];
    int temp;
    strcpy(user_temp, user[j]); strcpy(user[j], user[j+1]); strcpy(user[j+1], user_temp);
    strcpy(pass_temp, pass[j]); strcpy(pass[j], pass[j+1]); strcpy(pass[j+1], pass_temp);
    temp = e_score[j]; e_score[j] = e_score[j+1]; e_score[j+1] = temp;
    temp = m_score[j]; m_score[j] = m_score[j+1]; m_score[j+1] = temp;
    temp = h_score[j]; h_score[j] = h_score[j+1]; h_score[j+1] = temp;
    temp = add_score[j]; add_score[j] = add_score[j+1]; add_score[j+1] = temp;
    temp = sub_score[j]; sub_score[j] = sub_score[j+1]; sub_score[j+1] = temp;
    temp = divi_score[j]; divi_score[j] = divi_score[j+1]; divi_score[j+1] = temp;
    temp = multi_score[j]; multi_score[j] = multi_score[j+1]; multi_score[j+1] = temp;
}

void sort(){
    int i, j, a, b, temp;
    for(i=0; i<=last; i++){
        for(j=0; j<last-i; j++){
            a = average(e_score[j], m_score[j], h_score[j]);
            b = average(e_score[j+1], m_score[j+1], h_score[j+1]);
            if(a<b){
                sort_in(i,j);
            }
        }
    }
}

float average(int e, int m, int h){
    return (e + m + h)/3.0;
}

void leaderboard(){
    printf("=====================\e[38;2;255;255;255mLEADERBOARD\e[0m=====================\n");
    printf("| Rank | Name           Easy\tMedium\tHard\tXP  |\n");
    printf("=====================================================\n");
    for(int i=0; i<=last; i++){
        sort();
        if(i==0)
            printf("\e[38;2;255;255;0m   %d\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else if(i==1)
            printf("\e[38;2;255;255;255m   %d\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else if(i==2)
            printf("\e[38;5;180m   %d\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        else
            printf("\e[38;2;128;128;128m   %d\t%s\t\t%d\t%d\t%d\t%.2f\t\n\e[0m",i+1, user[i], e_score[i], m_score[i], h_score[i], average(e_score[i], m_score[i], h_score[i]));
        }
     printf("=====================================================\n");
}

void inner_leaderboard(char op){
    int n, opt;
    if(op=='y'){
        printf("Choose user to view:\t");
        scanf("%d", &n);
    system("cls");
    printf("========================================\n");
    printf("               %s                 \n", user[n-1]);
    printf("========================================\n");
    printf("  \e[32mEasy:\e[0m %d\t\e[38;5;208mMedium:\e[0m %d\t\e[31mHard:\e[0m %d\n", e_score[n-1], m_score[n-1], h_score[n-1]);
    printf("  \e[33m1. Addition:\e[0m\t\t%d\n", add_score[n-1]);
    printf("  \e[34m2. Subtraction:\e[0m\t%d\n", sub_score[n-1]);
    printf("  \e[32m3. Division:\e[0m \t\t%d\n", divi_score[n-1]);
    printf("  \e[35m4. Multiplication\e[0m\t%d\n", multi_score[n-1]);
    printf("  5. Exit\n");
    printf("========================================\n");
    printf("Choose operation to view:\t");
    scanf("%d", &opt);
    switch(opt){
        case 1: system("cls"); l_add(); break;
        case 2: l_sub(); break;
        case 3: l_divi(); break;
        case 4: l_multi(); break;
        case 5: return;
    }
    return;
    }
}

void leaderboard_op(char op){
    int opt;
    if(op=='y'){
    system("cls");
    printf("========================================\n");
    printf("            \e[38;2;255;255;255mLEADERBOARD\e[0m\n");
    printf("========================================\n");
    printf("     \e[33m1. Addition:\e[0m\n");
    printf("     \e[34m2. Subtraction:\e[0m\n");
    printf("     \e[32m3. Division:\e[0m\n");
    printf("     \e[35m4. Multiplication\e[0m\n");
    printf("     5. Exit\n");
    printf("========================================\n");
    printf("Choose operation to view:\n->");
    scanf("%d", &opt);
    switch(opt){
        case 1: system("cls"); l_add(); break;
        case 2: l_sub(); break;
        case 3: l_divi(); break;
        case 4: l_multi(); break;
        case 5: return;
    }
    return;
    }
}

void l_add() {
    system("cls");
    int i, j, temp;
    for (i = 0; i <= last; i++) {
        for (j = 0; j < last - i; j++) {
            if (add_score[j] < add_score[j + 1]) {
                sort_in(i,j);
            }
        }
    }
    printf("=============\e[38;2;255;255;255mADDITION\e[0m============\n");
    printf("| Rank | Name\t\tScore  |\n");
    printf("=================================\n");
    for (i = 0; i <= last; i++) {
        if(i==0) printf("\e[38;2;255;255;0m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], add_score[i]);
        else if(i==1) printf("\e[38;2;255;255;255m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], add_score[i]);
        else if(i==2) printf("\e[38;5;180m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], add_score[i]);
        else printf("\e[38;2;128;128;128m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], add_score[i]);
    }
    printf("=================================\n");
    system("pause");
}

void l_sub() {
    system("cls");
    int i, j, temp;
    for (i = 0; i <= last; i++) {
        for (j = 0; j < last - i; j++) {
            if (sub_score[j] < sub_score[j + 1]) {
                sort_in(i,j);
            }
        }
    }
    printf("===========\e[38;2;255;255;255mSUBTRACTION\e[0m===========\n");
    printf("| Rank | Name\t\tScore  |\n");
    printf("=================================\n");
    for (i = 0; i <= last; i++) {
        if(i==0) printf("\e[38;2;255;255;0m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], sub_score[i]);
        else if(i==1) printf("\e[38;2;255;255;255m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], sub_score[i]);
        else if(i==2) printf("\e[38;5;180m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], sub_score[i]);
        else printf("\e[38;2;128;128;128m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], sub_score[i]);
    }
    printf("=================================\n");
    system("pause");
}

void l_divi() {
    system("cls");
    int i, j, temp;
    for (i = 0; i <= last; i++) {
        for (j = 0; j < last - i; j++) {
            if (divi_score[j] < divi_score[j + 1]) {
                sort_in(i,j);
            }
        }
    }
    printf("=============\e[38;2;255;255;255mDIVISION\e[0m===========\n");
    printf("| Rank | Name\t\tScore  |\n");
    printf("=================================\n");
    for (i = 0; i <= last; i++) {
        if(i==0) printf("\e[38;2;255;255;0m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], divi_score[i]);
        else if(i==1) printf("\e[38;2;255;255;255m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], divi_score[i]);
        else if(i==2) printf("\e[38;5;180m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], divi_score[i]);
        else printf("\e[38;2;128;128;128m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], divi_score[i]);
    }
    printf("=================================\n");
    system("pause");
}

void l_multi() {
    system("cls");
    int i, j, temp;
    for (i = 0; i <= last; i++) {
        for (j = 0; j < last - i; j++) {
            if (multi_score[j] < multi_score[j + 1]) {
                sort_in(i,j);
            }
        }
    }
    printf("==========\e[38;2;255;255;255mMULTIPLICATION\e[0m=========\n");
    printf("| Rank | Name\t\tScore  |\n");
    printf("=================================\n");
    for (i = 0; i <= last; i++) {
        if(i==0) printf("\e[38;2;255;255;0m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], multi_score[i]);
        else if(i==1) printf("\e[38;2;255;255;255m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], multi_score[i]);
        else if(i==2) printf("\e[38;5;180m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], multi_score[i]);
        else printf("\e[38;2;128;128;128m   %d\t %s\t\t%d\n\e[0m", i + 1, user[i], multi_score[i]);
    }
    printf("=================================\n");
    system("pause");
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
            fprintf(fp, "%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", user[i], pass[i], e_score[i], m_score[i], h_score[i], add_score[i], sub_score[i], divi_score[i], multi_score[i]);
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
    while (fscanf(fp, "%[^\t]\t%[^\t]\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", user[last+1], pass[last+1], &e_score[last+1], &m_score[last+1], &h_score[last+1], &add_score[last+1], &sub_score[last+1], &divi_score[last+1], &multi_score[last+1]) == 9) {
        last++;
    }
    fclose(fp);
}
