#pragma once
#include <string>
using namespace std;
class pipe
{
	private:
		string name;
		int length;
		int diameter;
		string inRepair;
	public:
		pipe(string n, int l, int d, string rep);  // объ€вл€ем конструктор
		pipe();
		// ќбъ€вл€ем 4 функции дл€ чтени€ полей:
		string GetName() const;
		int GetLength() const;
		int GetDiameter() const;
		string GetInRepair() const;
		void SetInRepair(string s);
};

