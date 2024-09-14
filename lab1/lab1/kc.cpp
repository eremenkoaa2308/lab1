#include "kc.h"

kc::kc(string n, int num, int numw, int e)
{
	name = n;
	numFac = num;
	numWorkFac = numw;
	eff = e;
}

kc::kc()
{
	name = "Test";
	numFac = 10;
	numWorkFac = 2;
	eff = false;
}

string kc::GetName() const
{
	return this->name;
}

int kc::GetNumFac() const
{
	return this->numFac;
}

int kc::GetNumWorkFac() const
{
	return this->numWorkFac;
}

int kc::GetEff() const
{
	return this->eff;
}

bool kc::SetNumWorkFac(bool A)
{
	if (A) {
		if ((numWorkFac+1) > numFac) {
			return false;
		}
		else {
			numWorkFac++;
			return true;
		}
	}
	else {
		if ((numWorkFac-1) < 0) {
			return false;
		}
		else {
			numWorkFac--;
			return true;
		}
	}
}


