#pragma once
#include <string>
using namespace std;
struct kc
{
	private:
		string name;
		int numFac;
		int numWorkFac;
		int eff;
	public:
		kc(string n, int num, int numw, int e);
		kc();
		string GetName() const;
		int GetNumFac() const;
		int GetNumWorkFac() const;
		int GetEff() const;
		bool SetNumWorkFac(bool A);

};

