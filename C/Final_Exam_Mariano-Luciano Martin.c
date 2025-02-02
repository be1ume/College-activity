#include <stdio.h>

int main(){
    int choice;
    int high, low;
    char continueP;

    do{
    printf("************************\n");
    printf("1] Array\n");
    printf("2] Nested Loop\n");
    printf("3] Sequential Program\n");
    printf("4] Conditional Program\n");
    printf("5] Loop Program\n");
    printf("6] Credits\n");
    printf("7] Exit\n");
    printf("************************\n");
    
    printf("Input a number of your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: {
            printf("**This program will get the highest and lowest in your values**");
            int n;
            printf("\nEnter how many value do you want to enter: ");
            scanf("%d", &n);
            int arr[n];
            printf("Enter %d value: ", n);
            for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
            }

            high = arr[0];
            low = arr[0];

            for(int i = 0; i < n; i++){
                if(arr[i] > high){
                    high = arr[i];
                }
                if(arr[i] < low){
                    low = arr[i];
                }
            }
            printf("The lowest number is: %d\nThe highest number is: %d\n", low, high);
            break;
        }
        case 2:{
            printf("**This program will create a falling decreasing set of numbers**\n");
            int n;
            printf("Enter a number you want to make a falling stair of decerasing number: ");
            scanf("%d", &n);

            n += 1;

            for(int i = 0; i < n; i++){
                for(int j = i; j >= 0; j--){
                    printf("%d ", j);
                } printf("\n");
            }
            break;
        }

        case 3:{
            printf("**This program will convert the value of celsius to fahrenheit**\n");
            float C, F; 
            printf("Enter the value of Celsius: "); 
            scanf("%f", &C); 
            F = (9.0/5.0)*C+32.0; 
            printf("The degree in Fahrenheit is: %.2f\n", F); 
            
            break;
        }

        case 4:{
            int score;
            printf("**This program will show if you pass or fail the exam**\n");
            printf("Enter your score in computer programing written exam(/100): ");
            scanf("%d", &score);

            if(score >= 70){
                printf("You passed the Exam!");
            }
            else{
            printf("You failed!");
            }

            break;
        }

        case 5:{
            int n;
            printf("**This program will print how many times you want to say im handsome**\n");
            printf("How many times do you want to say I'm Handsome: ");
            scanf("%d", &n);

            for(int i = 0; i < n; i++){
                printf("I'm handsome\n");
            }

            break;
        }

        case 6:{
            printf("Luciano Martin T. Mariano \nBSCS-1A");
            printf("\nProgram 1: This program will used arrays of values then display the highest and lowest");
            printf("\nProgram 2: This program used nested loop to create a falling decreasing set of numbers");
            printf("\nProgram 3: This program used sequential to convert celcius to fahrenheit");
            printf("\nProgram 4: This program used conditional to show if you pass or fail an exam");
            printf("\nProgram 5: This program used loop to display multiple a fact multiple times");
            printf("\nProgram 6: Credits");
            printf("\nProgram 7: Exit the program");
            break;
        }

        case 7:
            printf("You exited the program");
            return 0;

        default:
            printf("Invalid choice.\n");
            break;
    }
    printf("\nDo you want to continue? (Y/N): ");
    scanf(" %c", &continueP);

    }while(continueP == 'Y' || continueP == 'y');

    printf("You end the program");

    return 0;
}
