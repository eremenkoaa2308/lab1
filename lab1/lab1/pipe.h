#pragma once
#include <string>
using namespace std;
class pipe
{
	private:
		string name;
		int length;
		int diameter;
		bool inRepair;
	public:
		pipe(string n, int l, int d, int rep);  // объ€вл€ем конструктор
		pipe();
		// ќбъ€вл€ем 4 функции дл€ чтени€ полей:
		string GetName() const;
		int GetLength() const;
		int GetDiameter() const;
		bool GetInRepair() const;
		void SetInRepair(bool s);
};

