#include <iostream>
#include "pipe.h"
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
    pipe r;
    cout << r.GetDiameter();
}
