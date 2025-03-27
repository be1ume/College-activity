//MARIANO-BSCS-1A

#include <iostream>
#include <string>
#include <iomanip>
#define MAX 5

using namespace std;

/*  1. Add a record
    2. Update a record
    3.Delete a record
    4.Display all   */

struct rec{
        string name;
        int q1;
        int q2;
        int q3;
};

rec sr[MAX];

int last;

int menu();
void init();
bool isfull();
bool isempty();
int locate(string n);
void display();
void add(rec x);
void update(string n);
void del(string n);
float ave(int x, int y, int z);


int main() {
    rec temp;
    init();
    while(true){
        system("cls");
        switch(menu()){
            case 1: system("cls"); cin.ignore();
                    cout<<"Enter student name: "; getline(cin, temp.name);
                    cout<<"Enter quiz 1: "; cin>>temp.q1;
                    cout<<"Enter quiz 2: "; cin>>temp.q2;
                    cout<<"Enter quiz 3: "; cin>>temp.q3;
                    add(temp); break;
            case 2: system("cls"); cin.ignore();
                    cout<<"Enter name to update: ";
                    getline(cin, temp.name);
                    update(temp.name); break;
            case 3: system("cls"); cin.ignore();
                    cout<<"Enter name to delete: ";
                    getline(cin, temp.name); del(temp.name); break;
            case 4: system("cls"); display(); break;
            case 5: exit(0);
        }
    }
    return 0;
}

int menu(){
    int opt;
    cout<<"1. Add a record"<<endl;
    cout<<"2. Update a record"<<endl;
    cout<<"3. Delete a record"<<endl;
    cout<<"4. Display all"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Choose [1-5]:\t";
    cin>>opt;
    return opt;
}

void init(){
    last = -1;
}

bool isfull(){
    return (MAX-1==last);
}

bool isempty(){
    return (last==-1);
}

int locate(string n){
    for(int i=0; i<=last; i++){
    if(n == sr[i].name)
        return i;
    }
    return -1;
}

void add(rec x){
    if(isfull()){
        cout<<"The record is full!"<<endl; system("pause"); return; }
    last++;
    sr[last] = x;
}

void update(string n){
    int opt;
    int p=locate(n);
    if(p<0){
        cout<<"Not found!"<<endl; system("pause"); return;
        }
    cout<<"Name: "<<sr[p].name<<endl;
    cout<<"Quiz 1: "<<sr[p].q1<<endl;
    cout<<"Quiz 2: "<<sr[p].q2<<endl;
    cout<<"Quiz 3: "<<sr[p].q3<<endl;
    cout<<"To change [1-3]: ";
    cin>>opt;
    cout<<"Enter new Quiz "<<opt<<":";
    switch(opt){
        case 1: cin>>sr[p].q1; break;
        case 2: cin>>sr[p].q2; break;
        case 3: cin>>sr[p].q3; break;
    }
}

void del(string n){
    int p=locate(n);
    if(isempty()){
        cout<<"The record is empty!"<<endl; system("pause"); return;
    }
    if(p<0)
        cout<<"Nothing to delete!";
    else{
    for(int i=p; i<=last; i++){
        sr[i] = sr[i+1];
        last--;
    }}
}

float ave(int x, int y, int z){
    return (x+y+z) / 3.0;
}

void display(){
    cout <<" "<< setw(15)<<left<<"Name"<<setw(10)<<"Quiz 1"<<setw(10)<<"Quiz 2"<<setw(10)<<"Quiz 3"<<setw(10)<<"Average"<<setw(10)<<"Remarks"<< endl;
    for(int i=0; i<=last; i++){
        cout<<i+1<<".) "<<setw(12)<<left<<sr[i].name<<setw(10)<<sr[i].q1<<setw(10)<<sr[i].q2<<setw(10)<<sr[i].q3<<setw(10)<<fixed<<setprecision(2)<<ave(sr[i].q1, sr[i].q2, sr[i].q3)<<setw(10)<<(ave(sr[i].q1, sr[i].q2, sr[i].q3)>=75? "PASSED":"FAILED")<<endl;
    } system("pause");
}
