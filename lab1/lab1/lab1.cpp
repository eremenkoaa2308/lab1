#include <iostream>
#include "pipe.h"
#include "kc.h"
#include <fstream>
#include <sstream>
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
pipe case1(bool& Tpipe) {
    if (!Tpipe) {
        pipe* Pipe = nullptr;
        char T;
        cout << "Do you want to create your own pipe? [Y/N]\n";
        cin >> T;
        if (T == 'Y' || T == 'y') {
            string entName;
            string input1;
            string input2;
            string input3;
            int entLen;
            int entDia;
            bool entRep;
            cout << "Enter a name\n";
            cin >> entName;
            while (true) {
                cout << "Enter a length\n";
                cin >> input1;
                if (isInteger(input1)) {
                    std::stringstream ss(input1);
                    ss >> entLen;
                    if (entLen > 0) {
                        break; 
                    }
                    else {
                        std::cout << "Length must be a non-negative integer. Please enter a valid value\n";
                    }
                }
                else {
                    std::cout << "Invalid input for length. Please enter a valid integer\n";
                }
            }
            while (true) {
                cout << "Enter a diameter\n";
                cin >> input2;
                if (isInteger(input2)) {
                    stringstream ss(input2);
                    ss >> entDia;
                    if (entDia > 0) {
                        break;
                    }
                    else {
                        std::cout << "Length must be a non-negative integer. Please enter a valid value\n";
                    }
                }
                else {
                    cout << "Invalid input for diameter. Please enter a valid integer\n";
                }
            }
            while (true) {
                cout << "Enter if your pipe is in repair\n";
                cin >> input3;
                if (input3 == "true" || input3 == "True" || input3 == "T" || input3 == "t") {
                    entRep = true;
                    break;
                }
                else if (input3 == "false" || input3 == "False" || input3 == "F" || input3 == "f") {
                    entRep = false;
                    break;
                }
                else {
                    cout << "Invalid input for inRepair. It should be boolean. Try again! (true/false)\n";
                }
            }
            Pipe = new pipe(entName, entLen, entDia, entRep);
            Tpipe = true;
            return *Pipe;
        }
        else {
            Pipe = new pipe();
            Tpipe = true;
            return *Pipe;
        }
    }
}
kc case2(bool& Tkc) {
    if (!Tkc) {
        kc* Kc = nullptr;
        char T;
        cout << "Do you want to create your own kc? [Y/N]\n";
        cin >> T;
        if (T == 'Y' || T == 'y') {
            string entName;
            int entNum;
            int entWork;
            int entEff;
            string input1;
            string input2;
            string input3;
            cout << "Enter a name\n";
            cin >> entName;
            while (true) {
                cout << "Enter number of factories\n";
                cin >> input1;
                if (isInteger(input1)) {
                    std::stringstream ss(input1);
                    ss >> entNum;
                    if (entNum > 0) {
                        break;
                    }
                    else {
                        std::cout << "Number of factories must be a non-negative integer. Please enter a valid value\n";
                    }
                }
                else {
                    std::cout << "Invalid input for number of factories. Please enter a valid integer\n";
                }
            }
            while (true) {
                cout << "Enter number of working factories\n";
                cin >> input1;
                if (isInteger(input1)) {
                    std::stringstream ss(input1);
                    ss >> entWork;
                    if (entWork > 0 && entWork<=entNum) {
                        break;
                    }
                    else if (entWork <= 0){
                        std::cout << "Number of working factories must be a non-negative integer. Please enter a valid value\n";
                    }
                    else {
                        std::cout << "Number of working factories can't be more than total number of factories. Please enter a valid value\n";
                    }
                }
                else {
                    std::cout << "Invalid input for number of working factories. Please enter a valid integer\n";
                }
            }
            while (true) {
                cout << "Enter efficiency of kc\n";
                cin >> input1;
                if (isInteger(input1)) {
                    std::stringstream ss(input1);
                    ss >> entEff;
                    if (entEff >= 0 && entEff<=100) {
                        break;
                    }
                    else {
                        std::cout << "Number of efficiency must be a non-negative integer. Please enter a valid value from 0 to 100\n";
                    }
                }
                else {
                    std::cout << "Invalid input for efficiency. Please enter a valid integer from 0 to 100\n";
                }
            }
            Kc = new kc(entName, entNum, entWork, entEff);
            Tkc = true;
            return *Kc;
        }
        else {
            Kc = new kc();
            Tkc = true;
            return *Kc;
        }
    }

}
void showPipe(pipe* Pipe, bool Tpipe) {
    if (Tpipe) {
        cout << "Your pipe's name: " << Pipe->GetName() << "\n";
        cout << "Your pipe's length: " << Pipe->GetLength() << "\n";
        cout << "Your pipe's diameter: " << Pipe->GetDiameter() << "\n";
        if (Pipe->GetInRepair() == 1) {
            cout << "Is your pipe in repair: " << Pipe->GetInRepair() << "\n";
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
void showKc(kc* Kc, bool Tkc) {
    if (Tkc) {
        cout << "Your kc's name: " << Kc->GetName() << "\n";
        cout << "Your kc's number of factories: " << Kc->GetNumFac() << "\n";
        cout << "Your kc's number of working factories: " << Kc->GetNumWorkFac() << "\n";
        cout << "Your kc's efficiency: " << Kc->GetEff() << "\n";
        cout << "\n";
    }
    else {
        cout << "You haven't created a kc yet\n";
    }
}
int main() {
    ofstream out;
    string line;
    bool Tpipe = false;
    pipe* Pipe = new pipe();
    bool Tkc = false;
    kc* Kc = new kc();
    while (true) {
        int choose = getChoose();
        switch (choose) {
        case 1: {
            *Pipe = case1(Tpipe);
            break;
        }
        case 2:
            *Kc = case2(Tkc);
            break;
        case 3:
            showPipe(Pipe, Tpipe);
            showKc(Kc, Tkc);
            break;
        case 4:
            if (Tpipe) {
                string A;
                bool T;
                while (true) {
                    cout << "Enter if you want edit repairing of your pipe: \n";
                    cin >> A;
                    if (A == "true" || A == "True" || A == "T" || A == "t") {
                        T = true;
                        break;
                    }
                    else if (A == "false" || A == "False" || A == "F" || A == "f") {
                        T = false;
                        break;
                    }
                    else {
                        cout << "Invalid input for inRepair. It should be boolean. Try again! (true/false)\n";
                    }
                }

                Pipe->SetInRepair(T);
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
                while (true) {
                    cout << "Enter + (plus) if you want to add one working factory. Enter - (minus) if you want to remove one working factory\n";
                    cin >> T;
                    if (T == "plus" || T == "+" || T == "Plus") {
                        A = true;
                        break;
                    }
                    else if (T == "Minus" || T == "minus" || T == "-" ) {
                        A = false;
                        break;
                    }
                    else {
                        cout << "Invalid input for inRepair. It should be boolean. Try again! (true/false)\n";
                    }
                }
                
                if (Kc->SetNumWorkFac(A)) {
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
            out.open("1.txt");
            if (out.is_open())
            {
                if (Tpipe) {
                    out << "Your pipe's name: " << Pipe->GetName() << "\n";
                    out << "Your pipe's length: " << Pipe->GetLength() << "\n";
                    out << "Your pipe's diameter: " << Pipe->GetDiameter() << "\n";
                    out << "Is your pipe in repair: " << Pipe->GetInRepair() << "\n";
                    out << "\n";
                }
                else {
                    out << "You haven't created a pipe yet\n";
                }
                if (Tkc) {
                    out << "Your kc's name: " << Kc->GetName() << "\n";
                    out << "Your kc's number of factories: " << Kc->GetNumFac() << "\n";
                    out << "Your kc's number of working factories: " << Kc->GetNumWorkFac() << "\n";
                    out << "Your kc's efficiency: " << Kc->GetEff() << "\n";
                    out << "\n";
                }
                else {
                    out << "You haven't created a kc yet\n";
                }
            }
            out.close();
            cout << "File has been written\n";
            break;
        case 7:
        {
            std::ifstream in("1.txt"); 
            if (in.is_open())
            {
                std::string line;
                while (std::getline(in, line))
                {
                    std::cout << line << std::endl;
                }
                in.close(); 
            }
            break; 
        }
        case 0:
            return 0;
        }
    }
    delete Pipe;
    delete Kc;
    return 0;
}

