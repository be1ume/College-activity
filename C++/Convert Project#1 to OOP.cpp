//Mariano, Luciano Martin T. - BSCS-1A - Convert Project#1 to OOP/C++
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>

#define MAX 10

using namespace std;

bool caseComp(string& s1, string& s2){
    if(s1.length() != s2.length()){
        return false;
    }
    for(size_t i = 0; i < s1.length(); ++i){
        if(tolower(s1[i]) != tolower(s2[i])){
            return false;
        }
    }return true;
}

class User;
class Game;
class Displays;

class Functions{
public:
    virtual void init() = 0;
    virtual bool isFull() = 0;
    virtual bool isDuplicate(string name) = 0;
    virtual int locate(string name) = 0;
    virtual ~Functions(){}
};

class User : public Functions{
protected:
    struct PlayerData{
        string username;
        string password;
        int Es = 0, Ms = 0, Hs = 0;
        int Ads = 0, Sus = 0, Divs = 0, Muls = 0;
    };

    PlayerData data[MAX];
    int last;
    string activeUser;
    int currentUser;

public:
    User(){
        init();
    }

    void init(){
        last = -1;
        currentUser = -1;
        activeUser = "";
        for(int i = 0; i < MAX; ++i){
            data[i] = PlayerData();
        }
    }

    bool isFull(){
        return(last == MAX - 1);
    }

    bool isDuplicate(string name){
        for(int i = 0; i <= last; i++){
            if(caseComp(data[i].username, name)){
                return true;
            }
        }return false;
    }

    int locate(string name){
        for(int i = 0; i <= last; i++){
            if(caseComp(data[i].username, name)){
                return i;
            }
        }return -1;
    }

    string getUsername(int position){ return data[position].username; }
    string getPassword(int position){ return data[position].password; }
    int getEscore(int position){ return data[position].Es; }
    int getMscore(int position){ return data[position].Ms; }
    int getHscore(int position){ return data[position].Hs; }
    int getAddScore(int position){ return data[position].Ads; }
    int getSubScore(int position){ return data[position].Sus; }
    int getDivScore(int position){ return data[position].Divs; }
    int getMulScore(int position){ return data[position].Muls; }
    int getLast(){ return last; }
    int getCurrentUserIndex(){ return currentUser; }
    string getActiveUsername(){ return activeUser; }

    void setUsername(int index, string& name){ data[index].username = name; }
    void setPassword(int index, string& password){ data[index].password = password; }
    void setEscore(int index, int score){ data[index].Es = score; }
    void setMscore(int index, int score){ data[index].Ms = score; }
    void setHscore(int index, int score){ data[index].Hs = score; }
    void setAddScore(int index, int score){ data[index].Ads = score; }
    void setSubScore(int index, int score){ data[index].Sus = score; }
    void setDivScore(int index, int score){ data[index].Divs = score; }
    void setMulScore(int index, int score){ data[index].Muls = score; }

    void incrementLast(){ if(!isFull()) last++; }

    float calcAverage(int index){
        if(index < 0 || index > last) return 0.0f;
        float divisor = 3.0f;
        if(divisor == 0) return 0.0f;
        return(data[index].Es + data[index].Ms + data[index].Hs) / divisor;
    }

    void swapPlayers(int index1, int index2){
        if(index1 >= 0 && index1 <= last && index2 >= 0 && index2 <= last && index1 != index2){
            PlayerData temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;

            if(currentUser == index1){
                currentUser = index2;
            } else if(currentUser == index2){
                currentUser = index1;
            }
        }
    }

    void sortByAverage(){
        if(last < 1) return;
        bool swapped;
        for(int i = 0; i <= last; ++i){
            swapped = false;
            for(int j = 0; j < last - i; ++j){
                if(calcAverage(j) < calcAverage(j + 1)){
                    swapPlayers(j, j + 1);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
        if(!activeUser.empty()){
           currentUser = locate(activeUser);
        }
    }

    void sortByOperation(int scoreType){
        if(last < 1) return;
        bool swapped;
        for(int i = 0; i <= last; ++i){
            swapped = false;
            for(int j = 0; j < last - i; ++j){
                int score1 = 0, score2 = 0;
                switch(scoreType){
                    case 1: score1 = data[j].Ads; score2 = data[j+1].Ads; break;
                    case 2: score1 = data[j].Sus; score2 = data[j+1].Sus; break;
                    case 3: score1 = data[j].Divs; score2 = data[j+1].Divs; break;
                    case 4: score1 = data[j].Muls; score2 = data[j+1].Muls; break;
                    default: return;
                }
                if(score1 < score2){
                    swapPlayers(j, j + 1);
                    swapped = true;
                }
            }
            if(!swapped) break;
        }
        if(!activeUser.empty()){
           currentUser = locate(activeUser);
        }
    }

    void saveData(string& filename = *(new string("user_data.txt"))){
        ofstream outFile(filename);
        if(!outFile){
            cerr << "Error opening file for saving: " << filename << endl;
            return;
        }

        for(int i = 0; i <= last; ++i){
            outFile << data[i].username << "\t"
                    << data[i].password << "\t"
                    << data[i].Es << "\t"
                    << data[i].Ms << "\t"
                    << data[i].Hs << "\t"
                    << data[i].Ads << "\t"
                    << data[i].Sus << "\t"
                    << data[i].Divs << "\t"
                    << data[i].Muls << "\n";
        }
        outFile.close();
    }

    void loadData(string& filename = *(new string("user_data.txt"))){
        ifstream inFile(filename);
        if(!inFile){
             init();
            return;
        }
        init();
        PlayerData temp_data;
        while(last < MAX - 1 &&
              getline(inFile, temp_data.username, '\t') &&
              getline(inFile, temp_data.password, '\t') &&
              (inFile >> temp_data.Es) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Ms) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Hs) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Ads) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Sus) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Divs) && inFile.ignore(1000, '\t') &&
              (inFile >> temp_data.Muls) && inFile.ignore(1000, '\n'))
        {
            last++;
            data[last] = temp_data;
        }

        if(!inFile.eof() && inFile.fail()){
             cerr << "Warning: Error reading data from " << filename << ". File might be corrupt." << endl;
        }

        inFile.close();
    }
};


class Homepage : virtual public User {
public:
    void signUp(){
        string temp_username;
        string temp_password;
        system("cls");
        cout << "=== Sign Up to create an account ===\n\n" << "Create Username: ";
        getline(cin >> ws, temp_username);

        if(temp_username.empty() || temp_username.length() > 15){
             cout << "\nInvalid username (must be 1-15 characters)." << endl;
             return;
        }

        if(isDuplicate(temp_username)){
            cout << "\nUser already exists....." << endl;
            return;
        }
        if(isFull()){
            cout << "\nMaximum users reached....." << endl;
            return;
        }

        incrementLast();
        data[last].username = temp_username;

        cout << "Create Password: ";
        getline(cin >> ws, temp_password);
        if(temp_password.empty()){
             cout << "\nPassword cannot be empty." << endl;
             last--;
             return;
        }
        data[last].password = temp_password;

        cout << "\nUser signed up successfully..." << endl;
    }

    int logIn(){
        string user_input;
        string pass_input;
        system("cls");
        cout << "=== Log In to proceed the Game ===\n\n" << "Enter Username: ";
        getline(cin >> ws, user_input);

        int userIndex = locate(user_input);

        if(userIndex == -1){
            cout << "\nUser does not exist....." << endl;
            return 0;
        }

        cout << "Enter Password: ";
        getline(cin >> ws, pass_input);

        if(data[userIndex].password == pass_input){
            cout << "\nLogged in successfully....." << endl;
            currentUser = userIndex;
            activeUser = data[userIndex].username;
            return 1;
        } else {
            cout << "\nWrong password....." << endl;
            return 0;
        }
    }
};

class Displays : virtual public User {
public:
    int mainMenu(){
        int op = 0;
        cout << "========================================" << endl;
        cout << "|              MAIN MENU              |" << endl;
        cout << "========================================" << endl;
        cout << "        1. Sign Up                     " << endl;
        cout << "        2. Log In                      " << endl;
        cout << "        3. Leaderboard                 " << endl;
        cout << "        4. Save and Quit               " << endl;
        cout << "        Enter 1-4 to choose            " << endl;
        cout << "========================================" << endl << "-> ";
        cin >> op;
        while(cin.fail() || op < 1 || op > 4){
             cout << "Invalid input. Please enter a number between 1 and 4: ";
             cin.clear();
             cin.ignore(10000, '\n');
             cin >> op;
        }
        cin.ignore(10000, '\n');
        return op;
    }

     int gameDifficultyMenu(){
        int opt = 0;
        if(currentUser == -1){
             cout << "Error: No user logged in." << endl;
             return 5;
        }
        cout << "========================================" << endl;
        cout << "|          Choose difficulty           |" << endl;
        cout << "========================================" << endl;
        cout << "  USER: " << getActiveUsername() << endl;
        cout << "  Scores -> Easy: " << getEscore(currentUser)
             << "\tMedium: " << getMscore(currentUser)
             << "\tHard: " << getHscore(currentUser) << endl;
        cout << "        1. Easy  (10 points)" << endl;
        cout << "        2. Medium (20 points)" << endl;
        cout << "        3. Hard   (30 points)" << endl;
        cout << "        4. Overall Leaderboard" << endl;
        cout << "        5. Back to Main Menu" << endl;
        cout << "========================================" << endl << "-> ";
        cin >> opt;
         while(cin.fail() || opt < 1 || opt > 5){
             cout << "Invalid input. Please enter a number between 1 and 5: ";
             cin.clear();
             cin.ignore(10000, '\n');
             cin >> opt;
        }
        cin.ignore(10000, '\n');
        return opt;
    }

    int arithmeticOperationMenu(){
        int opt = 0;
         if(currentUser == -1){
             cout << "Error: No user logged in." << endl;
             return 5;
        }
        cout << "========================================" << endl;
        cout << "|          Choose Operation            |" << endl;
        cout << "========================================" << endl;
        cout << "  USER: " << getActiveUsername() << endl;
        cout << "  Operation Scores -> Add: " << getAddScore(currentUser)
             << " Sub: " << getSubScore(currentUser)
             << " Div: " << getDivScore(currentUser)
             << " Mul: " << getMulScore(currentUser) << endl;
        cout << "        1. Addition" << endl;
        cout << "        2. Subtraction" << endl;
        cout << "        3. Division" << endl;
        cout << "        4. Multiplication" << endl;
        cout << "        5. Back to Difficulty Menu" << endl;
        cout << "========================================" << endl << "-> ";
        cin >> opt;
         while(cin.fail() || opt < 1 || opt > 5){
             cout << "Invalid input. Please enter a number between 1 and 5: ";
             cin.clear();
             cin.ignore(10000, '\n');
             cin >> opt;
        }
        cin.ignore(10000, '\n');
        return opt;
    }

    void displayLeaderboard(){
        system("cls");
        sortByAverage();

        cout << "======================== LEADERBOARD ========================" << endl;
        cout << "| Rank | Name            | Easy | Medium | Hard | Average XP |" << endl;
        cout << "=============================================================" << endl;

        if(last == -1){
            cout << "|           No users registered yet.                      |" << endl;
        } else {
             cout << fixed << setprecision(2);
             for(int i = 0; i <= last; i++){
                 string prefix = (currentUser != -1 && i == currentUser) ? " > " : "   ";
                  string rankStr = to_string(i + 1);
                  string currentUsername = getUsername(i);

                 cout << "|" << prefix << left << setw(4) << rankStr << "| "
                      << left << setw(15) << currentUsername.substr(0, 15) << "| "
                      << right << setw(4) << getEscore(i) << " | "
                      << right << setw(6) << getMscore(i) << " | "
                      << right << setw(4) << getHscore(i) << " | "
                      << right << setw(10) << calcAverage(i) << " |" << endl;
             }
              cout << defaultfloat << setprecision(6);
        }
        cout << "=============================================================" << endl;
    }

    void displayLeaderboardPerOperation(){
        system("cls");
        int opt;
        cout << "========================================" << endl;
        cout << "|       Operation Leaderboards         |" << endl;
        cout << "========================================" << endl;
        cout << "        1. Addition Leaderboard" << endl;
        cout << "        2. Subtraction Leaderboard" << endl;
        cout << "        3. Division Leaderboard" << endl;
        cout << "        4. Multiplication Leaderboard" << endl;
        cout << "        5. Back" << endl;
        cout << "========================================" << endl << "-> ";
        cin >> opt;
         while(cin.fail() || opt < 1 || opt > 5){
             cout << "Invalid input. Please enter a number between 1 and 5: ";
             cin.clear();
             cin.ignore(10000, '\n');
             cin >> opt;
        }
        cin.ignore(10000, '\n');

        if(opt >= 1 && opt <= 4){
            sortByOperation(opt);
            string title;
            switch(opt){
                case 1: title = "ADDITION"; break;
                case 2: title = "SUBTRACTION"; break;
                case 3: title = "DIVISION"; break;
                case 4: title = "MULTIPLICATION"; break;
            }
            system("cls");
            cout << "========== " << title << " LEADERBOARD ==========" << endl;
            cout << "| Rank | Name            | Score      |" << endl;
            cout << "==========================================" << endl;
            if(last == -1){
                 cout << "|           No users registered yet.       |" << endl;
            } else {
                 for(int i = 0; i <= last; ++i){
                     int score = 0;
                      switch(opt){
                          case 1: score = getAddScore(i); break;
                          case 2: score = getSubScore(i); break;
                          case 3: score = getDivScore(i); break;
                          case 4: score = getMulScore(i); break;
                      }
                     string prefix = (currentUser != -1 && i == currentUser) ? " > " : "   ";
                     string rankStr = to_string(i + 1);
                     string currentUsername = getUsername(i);

                     cout << "|" << prefix << left << setw(4) << rankStr << "| "
                          << left << setw(15) << currentUsername.substr(0, 15) << "| "
                          << right << setw(10) << score << " |" << endl;
                 }
            }
            cout << "==========================================" << endl;
        }
    }
};

class Game : virtual public User, public Displays {

private:
    int generateRandom(int range, int min_val){
        if(range <= 0) range = 1;
        return(rand() % range) + min_val;
    }

    int do_Addition(int range, int min_val){
        if(currentUser == -1) return 0;
        int a = generateRandom(range, min_val);
        int b = generateRandom(range, min_val);
        int answer;
        cout << a << " + " << b << " = ? ";
        cin >> answer;

        if(cin.fail()){
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return -1;
        }
        cin.ignore(10000, '\n');

        if(answer == (a + b)){
            cout << "Correct!" << endl;
            return 1;
        } else {
            cout << "Incorrect. The answer was " << (a + b) << "." << endl;
            return 0;
        }
    }

    int do_Subtraction(int range, int min_val){
        if(currentUser == -1) return 0;
        int a = generateRandom(range, min_val);
        int b = generateRandom(range, min_val);
        if(b > a) swap(a, b);
        int answer;
        cout << a << " - " << b << " = ? ";
         cin >> answer;

        if(cin.fail()){
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return -1;
        }
        cin.ignore(10000, '\n');

        if(answer == (a - b)){
             cout << "Correct!" << endl;
             return 1;
        } else {
            cout << "Incorrect. The answer was " << (a - b) << "." << endl;
            return 0;
        }
    }

    int do_Division(int range, int min_val){
         if(currentUser == -1) return 0;
         int a, b, result;
         int attempts = 0;
         int max_attempts = 100;
         do{
            b = generateRandom(range / 2 > 2 ? range/2 : 2, min_val > 1 ? 2 : 1);
            int max_result = (range + min_val) / b;
            result = generateRandom(max_result > 1 ? max_result : 1, 1);
            a = result * b;
            attempts++;
         } while((b <= 1 && min_val > 1)
                  || (a < min_val || a > (range + min_val))
                  && attempts < max_attempts);

         if(attempts >= max_attempts){
             cout << "DEBUG: Could not generate suitable division problem." << endl;
             b = 2; a = generateRandom(range, min_val)*b; result = a/b;
         }

        int answer;
        cout << a << " / " << b << " = ? ";
         cin >> answer;

        if(cin.fail()){
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return -1;
        }
        cin.ignore(10000, '\n');

        if(answer == result){
             cout << "Correct!" << endl;
             return 1;
        } else {
            cout << "Incorrect. The answer was " << result << "." << endl;
            return 0;
        }
    }

     int do_Multiplication(int range, int min_val){
         if(currentUser == -1) return 0;
         int factor_limit = 15;
         int a = generateRandom(factor_limit, 1);
         int b = generateRandom(factor_limit, 1);
         int answer;
         cout << a << " * " << b << " = ? ";
         cin >> answer;

        if(cin.fail()){
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return -1;
        }
        cin.ignore(10000, '\n');

        if(answer == (a * b)){
             cout << "Correct!" << endl;
             return 1;
        } else {
            cout << "Incorrect. The answer was " << (a * b) << "." << endl;
            return 0;
        }
    }

    int playLevel(int Multiplier, int range, int min_val){
        if(currentUser == -1) return -2;

        int operationType = arithmeticOperationMenu();
        if(operationType == 5) return -1;

        system("cls");
        string diffName;
        if(Multiplier == 10) diffName = "Easy";
        else if(Multiplier == 20) diffName = "Medium";
        else if(Multiplier == 30) diffName = "Hard";
        else diffName = "Custom";

        string opName;
         switch(operationType){
            case 1: opName = "Addition"; break;
            case 2: opName = "Subtraction"; break;
            case 3: opName = "Division"; break;
            case 4: opName = "Multiplication"; break;
            default: opName = "Unknown";
        }

        cout << "Difficulty: " << diffName << " (" << Multiplier << "x points)" << endl;
        cout << "Operation: " << opName << endl;
        cout << "Note: The round continues until you get a wrong answer or invalid input!" << endl;
        cout << "----------------------------------------------------" << endl;

        int questionResult = 0;
        int totalPoints = 0;

        while(true){
            switch(operationType){
                case 1: questionResult = do_Addition(range, min_val); break;
                case 2: questionResult = do_Subtraction(range, min_val); break;
                case 3: questionResult = do_Division(range, min_val); break;
                case 4: questionResult = do_Multiplication(range, min_val); break;
                default: questionResult = -2;
            }

            if(questionResult == 1){
                int pointsToAdd = Multiplier;
                totalPoints += pointsToAdd;
                switch(operationType){
                    case 1: setAddScore(currentUser, getAddScore(currentUser) + pointsToAdd); break;
                    case 2: setSubScore(currentUser, getSubScore(currentUser) + pointsToAdd); break;
                    case 3: setDivScore(currentUser, getDivScore(currentUser) + pointsToAdd); break;
                    case 4: setMulScore(currentUser, getMulScore(currentUser) + pointsToAdd); break;
                }
                cout << "Current round score: " << totalPoints << endl;
                cout << "----------------------------------------------------" << endl;
            } else {
                 if(questionResult == -1){
                      cout << "Ending round due to invalid input." << endl;
                 } else if(questionResult == 0){
                 } else {
                      cout << "Ending round due to an error." << endl;
                 }
                 break;
            }
        }

        cout << "\n==== Round Over! Total score gained in this round: " << totalPoints << " ====" << endl;
        system("pause");
        return totalPoints;
    }

public:
    void playGame(){
        if(currentUser == -1){
            cout << "Please log in first to play the game." << endl;
            system("pause");
            return;
        }

        while(true){
            system("cls");
            int difficultyChoice = gameDifficultyMenu();
            int pointsEarned = 0;
            system("cls");
            switch(difficultyChoice){
                case 1:
                    pointsEarned = playLevel(10, 10, 1);
                    if(pointsEarned > 0) setEscore(currentUser, getEscore(currentUser) + pointsEarned);
                    break;
                case 2:
                    pointsEarned = playLevel(20, 50, 11);
                    if(pointsEarned > 0) setMscore(currentUser, getMscore(currentUser) + pointsEarned);
                    break;
                case 3:
                    pointsEarned = playLevel(30, 100, 21);
                    if(pointsEarned > 0) setHscore(currentUser, getHscore(currentUser) + pointsEarned);
                    break;
                case 4:
                    displayLeaderboard();
                    char opChoice;
                    cout << "\nView leaderboards per operation? [y/n]: ";
                    cin >> opChoice;
                    cin.ignore(10000, '\n');
                    if(tolower(opChoice) == 'y'){
                       displayLeaderboardPerOperation();
                    }
                    system("pause");
                    pointsEarned = -999;
                    break;
                case 5:
                    cout << "Returning to main menu..." << endl;
                    system("pause");
                    return;
                default:
                    cout << "Invalid choice." << endl;
                     system("pause");
                     pointsEarned = -999;
                    break;
            }
            if(pointsEarned >= 0){
                 string fn = "user_data.txt";
                 saveData(fn);
            }
        }
    }
};

class Application : public Homepage, public Game {
public:
    Application(){
        string fn = "user_data.txt";
        loadData(fn);
        srand(time(NULL));
    }

    void run(){
         int choice;

        while(true){
            system("cls");
            choice = mainMenu();

            switch(choice){
                case 1:
                    signUp();
                    {
                        string fn = "user_data.txt";
                        saveData(fn);
                    }
                    system("pause");
                    break;
                case 2:
                    if(logIn() == 1){
                        system("pause");
                        playGame();
                        activeUser = "";
                        currentUser = -1;
                    } else {
                        system("pause");
                    }
                    break;
                case 3:
                    displayLeaderboard();
                     char opChoice;
                     cout << "\nView leaderboards per operation? [y/n]: ";
                     cin >> opChoice;
                     cin.ignore(10000, '\n');
                     if(tolower(opChoice) == 'y'){
                          displayLeaderboardPerOperation();
                     }
                    system("pause");
                    break;
                case 4:
                    {
                        string fn = "user_data.txt";
                        saveData(fn);
                    }
                    cout << "Data saved. Exiting program." << endl;
                    return;
                default:
                    cout << "Invalid option detected in main loop." << endl;
                    system("pause");
            }
        }
    }
};


int main(){
    Application app;
    app.run();

    return 0;
}
