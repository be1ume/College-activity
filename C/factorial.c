#include <stdio.h>

int main(){
    int f = 1, n;
    printf("Input number: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        f=i*f;
    }
    printf("The factorial is: %d", f);

}