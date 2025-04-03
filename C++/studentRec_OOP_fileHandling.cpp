//MARIANO - BSCS1A
#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 5

using namespace std;

struct Record{
    string name;
    int q1, q2, q3;
};

class Person{
private:
    int last = -1;
    double ave;
    Record student[MAX];
    bool isfull();
    bool isempty();
    int locate(string n);
public:
    void init();
    void add(Record x);
    void del(string n);
    void display();
    double average(int a, int b, int c);
    void save();
    void retrieve();
};

int menu();

int main(){
    Record stud;
    Person cs;
    cs.init();
    cs.retrieve();
    while(true){
        system("cls");
        switch(menu()){
        case 1:
            system("cls");
            cout<<"Enter student name: "; cin.ignore(); getline(cin, stud.name);
            cout<<"Enter student Quiz 1: "; cin>>stud.q1;
            cout<<"Enter student Quiz 2: "; cin>>stud.q2;
            cout<<"Enter student Quiz 3: "; cin>>stud.q3;
            cs.add(stud);
            break;
        case 2:
            system("cls");
            cout<<"Enter name to delete: ";
            cin.ignore();
            getline(cin, stud.name);
            cs.del(stud.name);
            break;
        case 3:
            system("cls");
            cs.display();
            break;
        case 4:
            cs.save();
            exit(0);
        default:
            cout<<"Invalid choice"<<endl; system("pause");
        }
    }
    return 0;
}

int menu(){
    int opt;
    cout<<"=====Student Record====="<<endl<<"1. ADD RECORD"<<endl<<"2. DELETE RECORD"<<endl<<"3. DISPLAY ALL"<<endl<<"4. Exit"<<endl<<"Choose [1-4]:    ";
    cin>>opt;
    return opt;
}

void Person::init(){
    last = -1;
}

int Person::locate(string n){
    for(int i=0; i<=last; i++){
        if(n==student[i].name)
            return i;
    } return -1;
}

bool Person::isempty(){
    return (last == -1);
}

bool Person::isfull(){
    return (last == MAX-1);
}

void  Person::add(Record x){
    if(isfull()){
        cout<<"The record is full. . .\n";
        system("pause");
        return;
    }
    int p = locate(x.name);
    if(p!=-1){
        cout<<"Record already exist. . ."<<endl;
        system("pause");
        return;
    }
    last++;
    student[last] = x;
    cout<<"Record added successfully"<<endl;
    system("pause");
}

void Person::del(string n){
    int p = locate(n);
    if(p<0 || p > last){
        cout<<"Not found!. . ."<<endl;
        system("pause");
    }else{
        for(int i=p; i<last; i++){
            student[i] = student[i+1];
        }
        last--;
        cout<<"Record deleted  successfully. . ."<<endl;
        system("pause");
    }
}

double Person::average(int a, int b, int c){
    return (a+b+c)/3.0;
}

void Person::display(){
    cout<<left<<setw(15)<<"Name"<<setw(10)<<"Quiz 1"<<setw(10)<<"Quiz 2"<<setw(10)<<"Quiz 3"<<setw(12)<<"Average"<<"Remarks"<<endl;
    for(int i=0; i<=last; i++){
        cout<<left<<setw(0)<<i+1<<setw(1)<<"."<<setw(15)<<student[i].name<<setw(10)<<student[i].q1<<setw(10)<<student[i].q2<<setw(10)<<student[i].q3<<setw(10)<<fixed<<setprecision(2)<<Person::average(student[i].q1, student[i].q2 ,student[i].q3)<<setw(10)<<(Person::average(student[i].q1, student[i].q2 ,student[i].q3) >=75? "PASSED":"FAILED")<<endl;
    }
    system("pause");
}

void Person::save(){
    ofstream outFile("student_record.txt");
    if(!outFile){
        cout<<"Error opening file!"<<endl;
        return;
        }
    outFile<<last<<endl;
    for(int i=0; i<=last; i++){
        outFile<<student[i].name<<"\n";
        outFile<<student[i].q1<<"\t"<<student[i].q2<<"\t"<<student[i].q3<<endl;
    }
    outFile.close();
    cout<<"Data saved successfully. . ."<<endl;
}

void Person::retrieve() {
    ifstream inFile("student_record.txt");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return;
    }

    inFile >> last;
    inFile.ignore(); // Consume the newline character after reading 'last'

    if (last >= 0) { // Check if there are any records to read
        for (int i = 0; i <= last; i++) {
            getline(inFile, student[i].name);
            inFile >> student[i].q1 >> student[i].q2 >> student[i].q3;
            inFile.ignore(); // Consume the newline character after reading q1, q2, q3
        }
    }

    inFile.close();
    cout<<"Data retrieved successfully"<<endl;
    system("pause");
}
