#include <iostream>
#include "pipe.h"
#include "kc.h"
using namespace std;
    

int main() {

    bool Tpipe = false;
    pipe* Pipe = nullptr;
    bool Tkc = false;
    kc* Kc = nullptr;

    while (true) {
        int choose;
        cout << "Choose one of the actions\n";
        cout << "1. Create a pipe\n";
        cout << "2. Create a kc\n";
        cout << "3. Viewing all objects\n";
        cout << "4. Edit the pipe\n";
        cout << "5. Edit the kc\n";
        cout << "6. Save\n";
        cout << "7. Download\n";
        cout << "0. Exit\n";
        cin >> choose;
        switch (choose) {
        case 1:
            if (!Tpipe) {
                char T;
                cout << "Do you want to create your own pipe? [Y/N]\n";
                cin >> T;
                if (T == 'Y' || T == 'y') {
                    string entName;
                    int entLen;
                    int entDia;
                    string entRep;
                    cout << "Enter a name\n";
                    cin >> entName;
                    cout << "Enter a length\n";
                    cin >> entLen;
                    cout << "Enter a diameter\n";
                    cin >> entDia;
                    cout << "Enter if your pipe is in repair\n";
                    cin >> entRep;
                    Pipe = new pipe(entName, entLen, entDia, entRep);
                    Tpipe = true;
                }
                else {
                    Pipe = new pipe();
                    Tpipe = true;
                }
            }
            break;
        case 2:
            if (!Tkc) {
                char T;
                cout << "Do you want to create your own kc? [Y/N]\n";
                cin >> T;
                if (T == 'Y' || T == 'y') {
                    string entName;
                    int entNum;
                    int entWork;
                    int entEff;
                    cout << "Enter a name\n";
                    cin >> entName;
                    cout << "Enter of factories\n";
                    cin >> entNum;
                    cout << "Enter of working factories\n";
                    cin >> entWork;
                    if (entWork > entNum) {
                        entWork = entNum;
                    }
                    cout << "Enter your efficiency(from 0 to 100%)\n";
                    cin >> entEff;
                    if (entEff >= 100) {
                        entEff = 100;
                    }
                    if (entEff < 0) {
                        entEff = 0;
                    }
                    Kc = new kc(entName, entNum, entWork, entEff);
                    Tkc = true;
                }
                else {
                    Kc = new kc();
                    Tkc = true;
                }
            }
            break;
        case 3:
            if (Tpipe) {
                cout << "Your pipe's name: " << Pipe->GetName() << "\n";
                cout << "Your pipe's length: " << Pipe->GetLength() << "\n";
                cout << "Your pipe's diameter: " << Pipe->GetDiameter() << "\n";
                cout << "Is your pipe in repair: " << Pipe->GetInRepair() << "\n";
                cout << "\n";
            }
            else {
                cout << "You haven't created a pipe yet\n";
            }
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
            break;

        case 4:
            if (Tpipe) {
                string A;
                cout << "Enter if you want edit repairing of your pipe: ";
                cin >> A;
                Pipe->SetInRepair(A);
                cout << "Your pipe's name: " << Pipe->GetName() << "\n";
                cout << "Your pipe's length: " << Pipe->GetLength() << "\n";
                cout << "Your pipe's diameter: " << Pipe->GetDiameter() << "\n";
                cout << "Is your pipe in repair: " << Pipe->GetInRepair() << "\n";
                cout << "\n";
            }
            else {
                cout << "You haven't created a pipe yet\n";
            }
            break;
        case 5:
            if (Tkc) {
                int A;
                cout << "Enter the number of fuctories to work: ";
                cin >> A;
                Kc->SetNumWorkFac(A);
                cout << "Your kc's name: " << Kc->GetName() << "\n";
                cout << "Your kc's number of factories: " << Kc->GetNumFac() << "\n";
                cout << "Your kc's number of working factories: " << Kc->GetNumWorkFac() << "\n";
                cout << "Your kc's efficiency: " << Kc->GetEff() << "\n";
                cout << "\n";
            }
            else {
                cout << "You haven't created a kc yet\n";
            }
            break;
        }
        
    }

    delete Pipe;
    delete Kc;
    return 0;
}

