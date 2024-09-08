#pragma once
#include <string>
using namespace std;
class kc
{
	private:
		string name;
		int numFac;
		int numWorkFac;
		bool eff;
	public:
		kc(string n, int num, int numw, bool e);
		kc();
		string GetName() const;
		int GetNumFac() const;
		int GetNumWorkFac() const;
		bool GetEff() const;
		void SetNumWorkFac(int newFac);

};

