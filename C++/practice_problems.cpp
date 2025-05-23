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
            return 0;
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
    bool i_palindrome(int arr[], int len){
        for(int i=0; i<len/2; i++){
            if(arr[i]!=arr[len-i-1])
                return false;
        } return true;
    }

    bool r_palindrome(int arr[], int left, int right){
        if(left>=right)
            return true;
        if(arr[left]!=arr[right])
            return false;
        else
            return r_palindrome(arr, left+1, right-1);
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
        cout<<"----------------------------Practice Problems-----------------------------\n";
        cout<<"1. iterative method to determine if array is sorted in descending order.\n";
        cout<<"2. recursive method to count the occurrence of a number in an array\n";
        cout<<"3. iterative method to find the smallest element in an array\n";
        cout<<"4. recursive method to find the smallest element in an array\n";
        cout<<"5. iterative method to check if the array is PALINDROME\n";
        cout<<"6. recursive method to check if the array is PALINDROME\n";
        cout<<"7. change the array\n";
        cout<<"8. Exit\n";
        cout<<"--------------------------------------------------------------------------\n";
        cout<<"[1-8]-> ";
        cin>>opt;
        return opt;
    }

    void cases(){
        const int MAX = 10;
        int arr[MAX];
        int len;
        int target;
        cout<<"Enter size of your array (max 10): ";
        cin>>len;
        cout<<"Enter elements: ";
        for(int i=0; i<len; i++) {
            cin>>arr[i];
        }
        while(true){
            system("cls");
            switch(menu()){
                case 1:
                    system("cls");
                    cout<<"--Check if the array is sorted in descending order.--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    if(sortcheck.iterative_sorted(arr, len))
                        cout<<"The array is sorted in descending order."<<endl;
                    else
                        cout<<"The array is not sorted in descending order."<<endl;
                    system("pause");
                    break;

                case 2:
                    system("cls");
                    cout<<"--recursive method to count the occurrence--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    cout<<"Enter target number: ";
                    cin>>target;
                    cout<<"The number "<<target<<" Occurred "<<occurance.r_occurance_number(arr, len, target)<<" times!"<<endl;
                    system("pause");
                    break;

                case 3:
                    system("cls");
                    cout<<"--iterative method to find the smallest--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    cout<<"The smallest element in your array is "<<small.i_smallest(arr, len)<<endl;
                    system("pause");
                    break;

                case 4:
                    system("cls");
                    cout<<"--Recursive method to find the smallest--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    cout<<"The smallest element in your array is "<<small.r_smallest(arr, len)<<endl;
                    system("pause");
                    break;

                case 5:
                    system("cls");
                    cout<<"--Check if Palindrome Iterative Method--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    if(palindromechecker.i_palindrome(arr, len))
                        cout<<"The array is a palindrome!"<<endl;
                    else
                        cout<<"The array is not a palindrome!"<<endl;
                    system("pause");
                    break;

                case 6:{
                    system("cls");
                    cout<<"--Check if Palindrome Recursive Method--"<<endl;
                    cout<<"Your array is [ ";
                    for(int i=0; i<len; i++){
                        cout<<arr[i]<<" ";
                        if (i<len-1)
                            cout<<", ";
                    } cout<<"]\n";
                    if(palindromechecker.r_palindrome(arr, 0, len-1))
                        cout<<"The array is a palindrome!"<<endl;
                    else
                        cout<<"The array is not a palindrome!"<<endl;
                    system("pause");
                    break;
                }

                case 7:
                    system("cls");
                    cout<<"--Enter New Array--"<<endl;
                    cout<<"Enter size of your array (max 10): ";
                    cin>>len;
                    cout<<"Enter elements: ";
                    for(int i=0; i<len; i++) {
                        cin>>arr[i];
                    }
                    break;

                case 8:
                    exit(0);
                    break;

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
