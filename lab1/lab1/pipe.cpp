#include "pipe.h"
#include <string>
using namespace std;

pipe::pipe(string n, int l, int d, string rep)
{
    name = n;
    length = l;
    diameter = d;
    inRepair = rep;
}
pipe::pipe()
{
    name = "Test";
    length = 10;
    diameter =20;
    inRepair = "true";
}
string pipe::GetName() const
{
    return this->name;
}

int pipe::GetLength() const
{
    return this->length;
}

int pipe::GetDiameter() const
{
    return this->diameter;
}

string pipe::GetInRepair() const
{
    return this->inRepair;
}

void pipe::SetInRepair(string s)
{
    inRepair = s;
}

