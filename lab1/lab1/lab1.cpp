#include <iostream>
#include "pipe.h"
#include "kc.h"
#include "pipe_and_kc.h"
#include <fstream>
#include <sstream>
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
        cout << "2. Create a kc\n";
        cout << "3. Viewing all objects\n";
        cout << "4. Edit the pipe\n";
        cout << "5. Edit the kc\n";
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
            if (ch != 4) {
                if (entLen > 0) {
                    return entLen;
                }
                else {
                    std::cout << "Length must be a non-negative integer. Please enter a valid value\n";
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
            if (ch == 5) {
                if (entLen >= 0 && entLen <= 100) {
                    break;
                }
                else {
                    std::cout << "Number of efficiency must be a non-negative integer. Please enter a valid value from 0 to 100\n";
                }
            }
        }
        else {
            std::cout << "Invalid input. Please enter a valid integer\n";
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
pipe case1(bool& Tpipe) {
    if (!Tpipe) {
        pipe Pipe;
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
            entLen=check_int(1,0);
            entDia = check_int(2,0);
            entRep = check_bool(1);
            Pipe = pipe(entName, entLen, entDia, entRep);
            Tpipe = true;
            return Pipe;
        }
        else {
            Pipe = pipe();
            Tpipe = true;
            return Pipe;
        }
    }
}
kc case2(bool& Tkc) {
    if (!Tkc) {
        kc Kc;
        char T;
        cout << "Do you want to create your own kc? [Y/N]\n";
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
            Kc = kc(entName, entNum, entWork, entEff);
            Tkc = true;
            return Kc;
        }
        else {
            Kc = kc();
            Tkc = true;
            return Kc;
        }
    }

}
void showPipe(pipe Pipe, bool Tpipe) {
    if (Tpipe) {
        cout << "Your pipe's name: " << Pipe.GetName() << "\n";
        cout << "Your pipe's length: " << Pipe.GetLength() << "\n";
        cout << "Your pipe's diameter: " << Pipe.GetDiameter() << "\n";
        if (Pipe.GetInRepair() == 1) {
            cout << "Is your pipe in repair: " << "true" << "\n";
        }
        else {
            cout << "Is your pipe in repair: " << "false" << "\n";
        }

        cout << "\n";
    }
    else {
        cout << "You haven't created a pipe yet\n";
    }
}
void showKc(kc Kc, bool Tkc) {
    if (Tkc) {
        cout << "Your kc's name: " << Kc.GetName() << "\n";
        cout << "Your kc's number of factories: " << Kc.GetNumFac() << "\n";
        cout << "Your kc's number of working factories: " << Kc.GetNumWorkFac() << "\n";
        cout << "Your kc's efficiency: " << Kc.GetEff() << "\n";
        cout << "\n";
    }
    else {
        cout << "You haven't created a kc yet\n";
    }
}
void write_file(bool Tpipe,bool Tkc, pipe Pipe, kc Kc) {
    ofstream out;
    out.open("1.txt");
    if (out.is_open())
    {
        if (Tpipe) {
            out << "Your pipe's name: " << Pipe.GetName() << "\n";
            out << "Your pipe's length: " << Pipe.GetLength() << "\n";
            out << "Your pipe's diameter: " << Pipe.GetDiameter() << "\n";
            out << "Is your pipe in repair: " << Pipe.GetInRepair() << "\n";
            out << "\n";
        }
        else {
            out << "You haven't created a pipe yet\n";
        }
        if (Tkc) {
            out << "Your kc's name: " << Kc.GetName() << "\n";
            out << "Your kc's number of factories: " << Kc.GetNumFac() << "\n";
            out << "Your kc's number of working factories: " << Kc.GetNumWorkFac() << "\n";
            out << "Your kc's efficiency: " << Kc.GetEff() << "\n";
            out << "\n";
        }
        else {
            out << "You haven't created a kc yet\n";
        }
    }
    out.close();
    cout << "File has been written\n";
}
pipe_and_kc read_file(pipe& Pipe, kc& Kc, bool& Tpipe,bool& Tkc) {
    ifstream in("1.txt");
    if (in.is_open())
    {
        string line;
        pipe Pipe;
        pipe_and_kc PK;
        string name1;
        string name2;
        kc Kc;
        int Num;
        int Num2;
        bool A;
        int Num3;
        int Num4;
        int Num5;
        int num_of_line = 1;
        while (getline(in, line))
        {
            if (line == "You haven't created a pipe yet") {
                num_of_line = 6;
            }
            if (line == "You haven't created a kc yet") {
                num_of_line = 10;
            }
            size_t pos = line.find(": ");//we find position of ": " in fileeee
            
            if (pos != string::npos) {
                string value = line.substr(pos + 2);//+2 to skip ": "
                if (num_of_line == 1) {
                    name1 = value;
                }
                if (num_of_line == 2) {
                    Num = stoi(value);
                }
                if (num_of_line == 3) {
                    Num2 = stoi(value);
                }
                if (num_of_line == 4) {
                    if (value == "1") {
                        A = true;
                    }
                    else if (value == "false" || value == "False" || value == "F" || value == "f") {
                        A = false;
                    }
                    Pipe = pipe(name1, Num, Num2, A);
                    Tpipe = true;
                }
                if (num_of_line == 5) {
                    name2 = value;
                }
                if (num_of_line == 6) {
                    Num3 = stoi(value);
                }
                if (num_of_line == 7) {
                    Num4 = stoi(value);
                }
                if (num_of_line == 8) {
                    Num5 = stoi(value);
                    Kc = kc(name2, Num3, Num4, Num5);
                    Tkc = true;
                }
                num_of_line = num_of_line + 1;
            }
        }
        in.close();
        PK.Pipe = Pipe;
        PK.Kc = Kc;
        return PK;
    }
}
int main() {

    string line;
    pipe_and_kc PK;
    bool Tpipe = false;
    pipe Pipe;
    bool Tkc = false;
    kc Kc;
    while (true) {
        int choose = getChoose();
        switch (choose) {
        case 1: {
            Pipe = case1(Tpipe);
            break;
        }
        case 2:
            Kc = case2(Tkc);
            break;
        case 3:
            showPipe(Pipe, Tpipe);
            showKc(Kc, Tkc);
            break;
        case 4:
            if (Tpipe) {
                string A;
                bool T;
                T = check_bool(1);
                Pipe.SetInRepair(T);
                showPipe(Pipe, Tpipe);
            }
            else {
                cout << "You haven't created a pipe yet\n";
            }
            break;
        case 5:
            if (Tkc) {
                bool A;
                string T;
                A = check_bool(2);
                if (Kc.SetNumWorkFac(A)) {
                    showKc(Kc, Tkc);
                }
                else {
                    cout << "The error in adding or removing a factory! Check the number of working factories and try again!\n";
                    showKc(Kc, Tkc);
                }
            }
            else {
                cout << "You haven't created a kc yet\n";
            }
            break;
        case 6:
            write_file(Tpipe, Tkc, Pipe, Kc);
            break;
        case 7:
        {
            PK = read_file(Pipe,Kc,Tpipe,Tkc);
            Kc = PK.Kc;
            Pipe = PK.Pipe;
            break; 
        }
        case 0:
            return 0;
        }
    }
    return 0;
}

