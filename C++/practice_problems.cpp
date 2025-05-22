#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


class I_sorted{
public:
    bool iterative_sorted(int arr[], int len){
        for(int i=0; i<len - 1; i++){
            if(arr[i] < arr[i+1]){
                return false;
            }
        } return true;
    }
};

class R_occurance{
public:
    int r_occurance_number(int arr[], int len, int target){
        if(len==0)
            return 0;
        else if(len > 0){
            if(target == arr[len-1]){
                return 1 + r_occurance_number(arr, len-1, target);
            }return r_occurance_number(arr, len-1, target);
        }else
            return r_occurance_number(arr, len-1, target);
    }
};

class Smallest{
public:
    int i_smallest(int arr[], int len){
        int temp=arr[0];
        if(len==0)
            return 0;
        for(int i=0; i<len; i++){
            if(arr[i]<temp)
                temp = arr[i];
        } return temp;
    }

    int r_smallest(int arr[], int len){
        if(len==0)
            return 0;
        if(len==1)
            return arr[len-1];
        int min = r_smallest(arr, len-1);

        if(min<arr[len-1])
            return min;
        else
            return arr[len-1];
    }
};

class Palindrome{
public:
    bool i_palindrome(string word){
        int len = word.size();
        for(int i=0; i<len/2; i++){
            if(word[i]!=word[len-i-1])
                return false;
        } return true;
    }

    bool r_palindrome(string word, int left, int right){
        if(left==right)
            return true;
        if(word[left]!=word[right])
            return false;
        else
            return r_palindrome(word, left+1, right-1);
    }
};

class Practice_Problems{
private:
    I_sorted sortcheck;
    R_occurance occurance;
    Smallest small;
    Palindrome palindromechecker;
public:
    int menu(){
        int opt;
        cout<<"1. Iterative sorted in descending\n2. Recursive Count Occurance\n3. Iterative find smallest"<<endl;
        cout<<"4. Recursive find smallest\n5. Palindrome Iterative method\n6. Palindrome Recursive method\n7. Exit\n[1-7]->";
        cin>>opt;
        return opt;
    }

    void cases(){
        while(true){
            system("cls");
            switch(menu()){
                case 1:{
                    system("cls");
                    cout<<"--Check if the array is sorted in descending order."<<endl;
                    int arr[]={};
                    int len;
                    cout<<"Enter number of your array: ";
                    cin>>len;
                    cout<<"Enter numbers: ";
                    for(int i=0; i<len; i++){
                        cin>>arr[i];
                    }
                    if(sortcheck.iterative_sorted(arr, len))
                        cout<<"The array is sorted in descending order."<<endl;
                    else
                        cout<<"The array is not sorted in descending order."<<endl;
                    system("pause");
                    break;
                }

                case 2:{
                    system("cls");
                    cout<<"--recursive method to count the occurrence--"<<endl;
                    int arr[] = {1,1,2,3,3,3,4,5,5,6,6,7,8,9,9};
                    int len = sizeof(arr)/sizeof(arr[0]);
                    int target;
                    cout<<"Enter target number: ";
                    cin>>target;
                    cout<<"The number "<<target<<" Occurred "<<occurance.r_occurance_number(arr, len, target)<<" times!"<<endl;
                    system("pause");
                    break;
                }

                case 3:{
                    system("cls");
                    cout<<"--iterative method to find the smallest--"<<endl;
                    int arr[]={};
                    int len;
                    cout<<"Enter number of your array: ";
                    cin>>len;
                    cout<<"Enter numbers: ";
                    for(int i=0; i<len; i++){
                        cin>>arr[i];
                    }
                    cout<<"The smallest element in your array is "<<small.i_smallest(arr, len)<<endl;
                    system("pause");
                    break;
                }
                case 4:{
                    system("cls");
                    cout<<"--Recursive method to find the smallest--"<<endl;
                    int arr[]={};
                    int len;
                    cout<<"Enter number of your array: ";
                    cin>>len;
                    cout<<"Enter numbers: ";
                    for(int i=0; i<len; i++){
                        cin>>arr[i];
                    }
                    cout<<"The smallest element in your array is "<<small.r_smallest(arr, len)<<endl;
                    system("pause");
                    break;
                }
                case 5:{
                    system("cls");
                    cout<<"--Check if Palindrome Iterative Method--"<<endl;
                    string word;
                    cout<<"Enter a word: ";
                    getline(cin>>ws,word);
                    int len = word.size();
                    if(palindromechecker.i_palindrome(word))
                        cout<<"The word "<<word<<" is a palindrome!"<<endl;
                    else
                        cout<<"The word "<<word<<" is not a palindrome!"<<endl;
                    system("pause");
                    break;
                }
                case 6:{
                    system("cls");
                    cout<<"--Check if Palindrome Recursive Method--"<<endl;
                    string word;
                    cout<<"Enter a word: ";
                    getline(cin>>ws,word);
                    int right = word.size()-1;
                    if(palindromechecker.r_palindrome(word, 0, right))
                        cout<<"The word "<<word<<" is a palindrome!"<<endl;
                    else
                        cout<<"The word "<<word<<" is not a palindrome!"<<endl;
                    system("pause");
                    break;
                }
                case 7:
                    exit(0);
                default:
                    cout<<"Invalid Input!"<<endl;
                    system("pause");
            }
        }
    }
};

int main(){
    Practice_Problems cs;
    cs.cases();

    return 0;
}
