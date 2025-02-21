#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int add(int items);
int sub(int items);
int multi(int items);
int divi(int items);
int menu();

int main(){
    int n = 5, cor = 0;
    while(1){
        switch(menu()){
            case 1:
            srand(time(NULL));
            cor = add(n);
            printf("\nYou got %d right out of %d", cor, n );
            break;
            case 2:
            srand(time(NULL));
            cor = sub(n);
            printf("\nYou got %d right out of %d", cor, n );
            break;
            case 3:
            srand(time(NULL));
            cor = multi(n);
            printf("\nYou got %d right out of %d", cor, n );
            break;
            case 4:
            srand(time(NULL));
            cor = divi(n);
            printf("\nYou got %d right out of %d", cor, n );
            break;
            case 5:
            exit(0);
            default:
            printf("Error! enter valid option");
        }
    } return 0;
}

int menu(){
    int op;
    printf("\n1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    scanf("%d", &op);
    return op;
}

int add(int items){
    int i, c = 0, a, b, ans;
    for(int i = 0; i<items; i++){
        a = rand() %10 + 1;
        b = rand() %10 + 1;
        printf("\nWhat is %d + %d? ", a, b);
        scanf("%d", &ans);

        if(ans == a+b){
            printf("Perfect!\n");
            c++;
        } else {
            printf("Wrong! The right answer is %d\n", a+b);
        }
    } return c;
}

int sub(int items){
    int i, c = 0, a, b, ans;
    for(int i = 0; i<items; i++){
        do{
            a = rand() %10 + 1;
            b = rand() %10 + 1;
        }while(a<b);

        printf("\nWhat is %d - %d? ", a, b);
        scanf("%d", &ans);

        if(ans == a-b){
            printf("Perfect!\n");
            c++;
        } else {
            printf("Wrong! The right answer is %d\n", a-b);
        }
    } return c;
}

int multi(int items){
    int i, c = 0, a, b, ans;
    for(int i = 0; i<items; i++){
        a = rand() %10 + 1;
        b = rand() %10 + 1;
        printf("\nWhat is %d * %d? ", a, b);
        scanf("%d", &ans);

        if(ans == a*b){
            printf("Perfect!\n");
            c++;
        } else {
            printf("Wrong! The right answer is %d\n", a*b);
        }
    } return c;
}

int divi(int items){
    int i, c = 0, a, b, ans;
    for(int i = 0; i<items; i++){
        do{
            a = rand() %10 + 1;
            b = rand() %10 + 1;
        }while(a%b != 0);

        printf("\nWhat is %d / %d? ", a, b);
        scanf("%d", &ans);

        if(ans == a/b){
            printf("Perfect!\n");
            c++;
        } else {
            printf("Wrong! The right answer is %d\n", a/b);
        }
    } return c;
}