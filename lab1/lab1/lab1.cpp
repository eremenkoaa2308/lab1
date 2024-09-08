#include <iostream>
#include "pipe.h"
#include "kc.h"
using namespace std;
    

int main() {

    bool Tpipe = false;
    pipe* Pipe = nullptr;

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
        cin.ignore(); // Очистка символа новой строки из буфера cin
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
            break;
        }
    }

    delete Pipe;
    return 0;
}

