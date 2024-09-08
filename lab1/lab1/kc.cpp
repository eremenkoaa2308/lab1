#include "kc.h"

kc::kc(string n, int num, int numw, bool e)
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

bool kc::GetEff() const
{
	return this->eff;
}

void kc::SetNumWorkFac(int newFac)
{
	if (newFac >= numFac){
		numWorkFac = numFac;
	}
	else {
		numWorkFac = newFac;
	}
}


