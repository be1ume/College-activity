#include <iostream>
#include <string>
#include <iomanip>
#define MAX 2
using namespace std;

class User{
private:
    struct Player{
    string username;
    string password;
    };
    struct Scores{
    int Es, Ms, Hs;
    //int As, Ss, Ds, Ms;
    };
    Player  player[MAX];
    Scores score[MAX];
protected:
    int last = -1;
    string activeUser;
    int currentUser;
public:

    string getUsername(int position){return player[position].username;}
    void setUsername(string name){player[last].username = name;}
    string getPassword(int position){return player[position].password;}
    void setPassword(string password){player[last].password = password;}
    int getEscore(int position){return score[position].Es;}
    void setEscore(int score){this->score[last].Es = score;}
    int getMscore(int position){return score[position].Ms;}
    void setMscore(int score){this->score[last].Ms = score;}
    int getHscore(int position){return score[position].Hs;}
    void setHscore(int score){this->score[last].Hs = score;}


    bool isDuplicate(string name){
        for(int i=0; i<=last; i++){
            if(name == getUsername(i))
                return true;
        } return false;}
    bool isFull(){
        if(MAX-1 == last)
            return true;
        return false;}
    int locate(string name){
        for(int i=0; i<=last; i++){
            if(name == getUsername(i))
                return i;
        } return -1;}
    void displayUser(int position){
        cout << "Username: " << player[position].username << endl;
        cout << "Password: " << player[position].password<< endl;
        cout << "Easy Score: " << score[position].Es << endl;
        cout << "Medium Score: " << score[position].Ms << endl;
        cout << "Hard Score: " << score[position].Hs << endl;

    }
    void displayAll() {
        if (last == -1) {
            cout << "No users registered yet." << endl;
            return;
        }
        cout << "\n--- Registered Users ---" << endl;
        for (int i = 0; i <= last; i++) {
            cout << "\nUser " << i + 1 << ":" << endl;
            displayUser(i);
        }
        cout << "------------------------" << endl;
    }
};

class Homepage : public User{
public:
    void signUp(){
        string temp_username;
        string temp_password;
        system("cls");
        cout<<"===Sign Up to create an account===\n\n"<<"Create Username: ";
        getline(cin >> ws, temp_username);
        if(isDuplicate(temp_username)){
            cout<<"\nUser already exist....."<<endl; return;
        }else if(isFull()){
            cout<<"\nMaximum users reached....."<<endl; return;
        }else{
        last++;
        setUsername(temp_username);
        cout<<"Create Password: ";
        getline(cin>>ws, temp_password);
        setPassword(temp_password);
        setEscore(0); setMscore(0); setHscore(0);
        }
    }

    int logIn(){
        string user_input;
        string pass_input;
        system("cls");
        cout<<"===Log In to proceed the Game===\n"<<endl<<"Enter Username: ";
        getline(cin>>ws, user_input);
        if(locate(user_input)==-1){
            cout<<"\nUser does not exist. . ."<<endl; return 0;
        }
        cout<<"Enter Password: ";
        getline(cin>>ws, pass_input);
        for(int i=0; i<=last; i++){
            if(getUsername(i)==user_input){
                if(getPassword(i)==pass_input){
                    cout<<"\nLogged in successfully. . ."<<endl;
                    currentUser = locate(user_input);
                    activeUser = user_input;
                    return 1;
                }
            }else{
                cout<<"\nWrong password. . ."<<endl; return 0;
            }
        }return 0;
    }

    void display(){displayAll();}
};

class Game : public User{
public:
    int option;

};

class Displays : public User{
public:
    int menu(){
    int op;
    cout<<"========================================"<<endl;
    cout<<"|              MAIN MENU               |"<<endl;
    cout<<"========================================"<<endl;
    cout<<"     1. Sign Up                       "<<endl;
    cout<<"     2. Log In                        "<<endl;
    cout<<"     3. Leaderboard                  "<<endl;
    cout<<"     4. Save and Quit                 "<<endl;
    cout<<"     Enter 1-4 to choose              "<<endl;
    cout<<"========================================"<<endl<<"->";
    cin>>op;
    return op;
    }


};

int main(){
    Homepage startUp;
    Displays disp;
    int opt, n;
    while(true){
        system("cls");
        switch(disp.menu()){
            case 1:
                startUp.signUp();
                break;
            case 2:
                n = startUp.logIn();
                 system("pause");
                break;
            case 3:
                startUp.display();
                system("pause");
                break;
            case 4:
                cout<<"Exiting program."<<endl;
                return 0;
            default:
                cout<<"Invalid option. Please try again.\n";
        }
    }

return 0;
}
