#include <iostream>

int main(){
    int number, result;
    std::cout << "Enter a number: " ;
    std::cin >>  number ; 
    result = number + number; 
    std::cout << "Youve entered: " << number << "\n" << "The sum of the number twice is: "  << result << std::endl;


}