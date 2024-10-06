#include <iostream>
#include "pipe.h"
#include "cs.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <string>
#include <thread>
using namespace std;

bool isInteger(const string& s) {
    istringstream iss(s);
    int num;
    iss >> num;
    return !iss.fail() && iss.eof();
}
    
int getChoose() {
    string input;
    int choose;
    while (true) {
        cout << "Choose one of the actions\n";
        cout << "1. Create a pipe\n";
        cout << "2. Create a cs\n";
        cout << "3. Viewing all objects\n";
        cout << "4. Edit the pipe\n";
        cout << "5. Edit the cs\n";
        cout << "6. Save\n";
        cout << "7. Download\n";
        cout << "0. Exit\n";
        cin >> input;

        if (isInteger(input)) {
            stringstream ss(input);
            ss >> choose;
            return choose;
        }
        else {
            cout << "Invalid input. Please enter a valid integer\n";
        }
    }
}
int check_int(int ch, int EntNum) {
    string input1;
    int entLen;
    while (true) {
        if (ch == 1) {
            cout << "Enter a length"<<endl;
        }
        else if (ch == 2) {
            cout << "Enter a diameter" << endl;
        }
        else if (ch == 3) {
            cout << "Enter number of factories" <<endl;
        }
        else if (ch == 4) {
            cout << "Enter number of working factories"<<endl;
        }
        else if (ch == 5) {
            cout << "Enter number of efficiency from 0 to 100" << endl;
        }
        cin >> input1;
        if (isInteger(input1)) {
            stringstream ss(input1);
            ss >> entLen;
            if (ch != 4 && ch != 5) {
                if (entLen > 0) {
                    return entLen;
                }
                else {
                    cout << "Length must be a non-negative integer. Please enter a valid value\n";
                }
            }
            if (ch == 5) {
                if (entLen >= 0 && entLen <= 100) {
                    return entLen;
                }
                else {
                    cout << "Number of efficiency must be a non-negative integer. Please enter a valid value from 0 to 100\n";
                }
            }
            else {
                if (entLen > 0 && entLen<EntNum) {
                    return entLen;
                }
                else if (entLen <= 0) {
                    cout << "Number of working factories must be a non-negative integer. Please enter a valid value\n";
                }
                else {
                    cout << "Number of working factories can't be more than total number of factories. Please enter a valid value\n";
                }
            }  
            
        }
        else {
            cout << "Invalid input. Please enter a valid integer\n";
        }
    }

}
int check_i(string ch) {
    int entLen;
    if (isInteger(ch)) {
        stringstream ss(ch);
        ss >> entLen;
        if (entLen > 0) {
            return entLen;
        }
    }
}
bool check_bool(int ch) {
    bool entRep;
    string input1;
    bool A;
    while (true) {
        if (ch == 1) {
            cout << "Enter if your pipe is in repair\n";
        }
        if (ch == 2) {
            cout << "Enter + (plus) if you want to add one working factory. Enter - (minus) if you want to remove one working factory\n";
        }
        if (ch != 0) {
            cin >> input1;
        }
        if (ch == 1 || ch==0) {
            if (input1 == "true" || input1 == "True" || input1 == "T" || input1 == "t") {
                entRep = true;
                return entRep;
            }
            else if (input1 == "false" || input1 == "False" || input1 == "F" || input1 == "f") {
                entRep = false;
                return entRep;
            }
            else {
                cout << "Invalid input for inRepair. It should be boolean. Try again! (true/false)\n";
            }
        }
        else {
            if (input1 == "plus" || input1 == "+" || input1 == "Plus") {
                A = true;
                return A;
            }
            else if (input1 == "Minus" || input1 == "minus" || input1 == "-") {
                A = false;
                return A;
            }
            else {
                cout << "Invalid input for inRepair. It should be boolean. Try again! (+/-)\n";
            }
        }

    }
}
void createPipe(vector<pipe>& Pipes) {
    char T;
    cout << "Do you want to create your own pipe? [Y/N]\n";
    cin >> T;
    if (T == 'Y' || T == 'y') {
        string entName;
        int entLen;
        int entDia;
        bool entRep;
        cout << "Enter a name" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, entName);
        entLen = check_int(1, 0);
        entDia = check_int(2, 0);
        entRep = check_bool(1);
        Pipes.push_back(pipe(entName, entLen, entDia, entRep));
    }
    else {
        Pipes.push_back(pipe());
    }

}
void createCs(vector<cs>& Css) {
    char T;
    cout << "Do you want to create your own cs? [Y/N]\n";
    cin >> T;
    if (T == 'Y' || T == 'y') {
        string entName;
        int entNum;
        int entWork;
        int entEff;
        cout << "Enter a name" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, entName);
        entNum = check_int(3,0);
        entWork = check_int(4,entNum);
        entEff = check_int(5, 0);
        Css.push_back(cs(entName, entNum, entWork, entEff));
    }
    else {
        Css.push_back(cs());
    }

}
void showPipe(const vector<pipe> Pipes) {
    if (Pipes.size()>0) {
        cout << "Your's pipes:"<<endl;
        for (int i = 0; i < Pipes.size(); i++) {
            cout << "Pipe id = " << i+1<<endl;
            cout << "Your pipe's name: " << Pipes[i].GetName() << "\n";
            cout << "Your pipe's length: " << Pipes[i].GetLength() << "\n";
            cout << "Your pipe's diameter: " << Pipes[i].GetDiameter() << "\n";
            if (Pipes[i].GetInRepair() == 1) {
                cout << "Is your pipe in repair: " << "true" << "\n";
            }
            else {
                cout << "Is your pipe in repair: " << "false" << "\n";
            }

            cout << "\n";
        }
    }
    else {
        cout << "You haven't created any pipes yet\n";
    }
}
void showCs(const vector<cs> Css) {
    if (Css.size() > 0) {
        cout << "Your's css:"<<endl;
        for (int i = 0; i < Css.size(); i++) {
            cout << "Cs id = " << i+1<<endl;
            cout << "Your cs's name: " << Css[i].GetName() << "\n";
            cout << "Your cs's number of factories: " << Css[i].GetNumFac() << "\n";
            cout << "Your cs's number of working factories: " << Css[i].GetNumWorkFac() << "\n";
            cout << "Your cs's efficiency: " << Css[i].GetEff() << "\n";
            cout << "\n";
        }   
    }
    else {
        cout << "You haven't created any css yet\n";
    }
}
void editPipe(vector<pipe>& Pipes) {
    string A;
    string num;
    int a;
    while (true) {
        cout << "Enter the number of pipe, you want to redact (from 1 to inf)"<<endl;
        cin >> num;
        if (isInteger(num)) {
            a = stoi(num);
            break;
        }
        else {
            cout << "Enter the positive number!";
        }
    }
    bool T;
    T = check_bool(1);
    if (Pipes.size() >= a) {
        Pipes[a - 1].SetInRepair(T);
    }
    else {
        cout << "Pipe with this number doesn't exsist";
    }
    showPipe(Pipes);
}
void editCs(vector<cs>& Css) {
    bool A;
    string num;
    int a;
    string T;
    while (true) {
        cout << "Enter the number of cs, you want to redact (from 1 to inf)" << endl;
        cin >> num;
        if (isInteger(num)) {
            a = stoi(num);
            break;
        }
        else {
            cout << "Enter the positive number!";
        }
    }
    A = check_bool(2);
    if (Css.size() >= a) {
        if (Css[a].SetNumWorkFac(A)) {
            showCs(Css);
        }
        else {
            cout << "The error in adding or removing a factory! Check the number of working factories and try again!\n";
            showCs(Css);
        }
    }
    else {
        cout << "Cs with this number doesn't exsist";
    }
}
void write_file(vector<pipe> Pipes,vector<cs> Css) {
    string f;
    cout << "Enter the name of file, that you want save your data" << endl;
    cin >> f;
    ofstream out;
    if (f.length() < 4 || f.substr(f.length() - 4) != ".txt") {
        f += ".txt"; // if not ".txt", we add it to the end
    }
    out.open(f);
    if (out.is_open())
    {
        if (Pipes.size()>0){
            out << "==PIPES=="<<endl;
            for (int i = 0; i < Pipes.size(); i++) {
                out << "Pipe id: " <<i<< endl;
                out << "Your pipe's name: " << Pipes[i].GetName() << "\n";
                out << "Your pipe's length: " << Pipes[i].GetLength() << "\n";
                out << "Your pipe's diameter: " << Pipes[i].GetDiameter() << "\n";
                out << "Is your pipe in repair: " << Pipes[i].GetInRepair() << "\n";
                out << "\n";
            }
        }
        else {
            out << "You haven't created any pipe yet\n";
        }
        if (Css.size() > 0) {
            out << "==CSS=="<<endl;
            for (int i = 0; i < Css.size(); i++) {
                out << "Cs id: " << i << endl;
                out << "Your cs's name: " << Css[i].GetName() << "\n";
                out << "Your cs's number of factories: " << Css[i].GetNumFac() << "\n";
                out << "Your cs's number of working factories: " << Css[i].GetNumWorkFac() << "\n";
                out << "Your cs's efficiency: " << Css[i].GetEff() << "\n";
                out << "\n";
            }
        }
        else {
            out << "You haven't created a cs yet\n";
        }
    }
    out.close();
    cout << "File has been written\n";
}
void read_file(vector<pipe>& Pipes, vector<cs>& Css) {
    string f;
    cout << "Enter the name of file, that you want read data from" << endl;
    cin >> f;
    if (f.length() < 4 || f.substr(f.length() - 4) != ".txt") {
        f += ".txt"; // if not ".txt", we add it to the end
    }
    ifstream in(f);
    if (in.is_open()) {
        string line;
        string name1;
        string name2;
        int Num;
        int Num2;
        bool A;
        int Num3;
        int Num4;
        int idP;
        int idC;
        int Num5;
        int numOfLine = 0;
        bool CheckPipeOrCs;
        while (getline(in, line)) {
            numOfLine++;
            if (line == "==PIPES==") {
                CheckPipeOrCs = true;
            }
            else if (line == "==CSS==") {
                CheckPipeOrCs = false;
            }
            size_t pos = line.find(": ");//we find position of ": " in fileeee
            if (pos != string::npos) {
                string value = line.substr(pos + 2);//+2 to skip ": "
                if (CheckPipeOrCs) {
                    if (numOfLine == 2) {
                        idP = stoi(value);
                    }
                    if (numOfLine == 3) {
                        name1 = value;
                    }
                    if (numOfLine == 4) {
                        Num = stoi(value);
                    }
                    if (numOfLine == 5) {
                        Num2 = stoi(value);
                    }
                    if (numOfLine == 6) {
                        if (value == "1") {
                            A = true;
                        }
                        else if (value == "0") {
                            A = false;
                        }
                        if (idP >= 0 && idP < Pipes.size()) {
                            Pipes[idP] = pipe(name1, Num, Num2, A);

                        }
                        else if (idP == Pipes.size()) {
                            Pipes.push_back(pipe(name1, Num, Num2, A));
                        }
                        numOfLine = 0;
                    }
                }
                else {
                    if (numOfLine == 3) {
                        idC = stoi(value);
                    }
                    if (numOfLine == 4) {
                        name2 = value;
                    }
                    if (numOfLine == 5) {
                        Num3 = stoi(value);
                    }
                    if (numOfLine == 6) {
                        Num4 = stoi(value);
                    }
                    if (numOfLine == 7) {
                        Num5 = stoi(value);
                        if (idC >= 0 && idC < Css.size()) {
                            Css[idC] = cs(name2, Num3, Num4, Num5);
                        }
                        else if (idC == Css.size()) {
                            Css.push_back(cs(name2, Num3, Num4, Num5));
                        }
                        numOfLine = 1;
                    }
                }
            }
        }
        in.close();
    }
}
//    ifstream in("1.txt");
//    if (in.is_open())
//    {
//        string line;
//        string name1;
//        string name2;
//        int Num;
//        int Num2;
//        bool A;
//        int Num3;
//        int Num4;
//        int Num5;
//        int num_of_line = 1;
//        while (getline(in, line))
//        {
//            if (line == "You haven't created a pipe yet") {
//                num_of_line = 6;
//            }
//            if (line == "You haven't created a cs yet") {
//                num_of_line = 10;
//            }
//            size_t pos = line.find(": ");//we find position of ": " in fileeee
//            
//            if (pos != string::npos) {
//                string value = line.substr(pos + 2);//+2 to skip ": "
//                if (num_of_line == 1) {
//                    name1 = value;
//                }
//                if (num_of_line == 2) {
//                    Num = stoi(value);
//                }
//                if (num_of_line == 3) {
//                    Num2 = stoi(value);
//                }
//                if (num_of_line == 4) {
//                    if (value == "1") {
//                        A = true;
//                    }
//                    else if (value == "false" || value == "False" || value == "F" || value == "f") {
//                        A = false;
//                    }
//                    Pipe = pipe(name1, Num, Num2, A);
//                    Tpipe = true;
//                }
//                if (num_of_line == 5) {
//                    name2 = value;
//                }
//                if (num_of_line == 6) {
//                    Num3 = stoi(value);
//                }
//                if (num_of_line == 7) {
//                    Num4 = stoi(value);
//                }
//                if (num_of_line == 8) {
//                    Num5 = stoi(value);
//                    Cs = cs(name2, Num3, Num4, Num5);
//                    Tcs = true;
//                }
//                num_of_line = num_of_line + 1;
//            }
//        }
//        in.close();
//    }
//}
int main() {

    string line;
    vector<pipe> Pipes;
    vector<cs> Css;
    while (true) {
        int choose = getChoose();
        switch (choose) {
        case 1: {
            createPipe(Pipes);
            break;
        }
        case 2:
            createCs(Css);
            break;
        case 3:
            showPipe(Pipes);
            showCs(Css);
            break;
        case 4: {
            editPipe(Pipes);
            break;
        }
        case 5:
            editCs(Css);
            break;
        case 6:
            write_file(Pipes,Css);
            break;
        case 7:
        {
            read_file(Pipes,Css);
            break; 
        }
        case 0:
            return 0;
        }
    }
    return 0;
}

