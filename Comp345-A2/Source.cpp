#include <iostream>
#include <vector>
using namespace std;

class a
{
protected:
	int test;
public:
	virtual void SetTest(int arg) { test = arg; }
	int GetTest() { return test; }
};

class b : public a
{
public:
	void SetTest(int arg) { test = arg + 1; }
};

class c : public a
{
public:
	void SetTest(int arg) { test = arg + 2; }
};

int main()
{
	vector<a *> derivedClassHolder;
	derivedClassHolder.push_back(new b);
	derivedClassHolder.push_back(new c);
	derivedClassHolder.push_back(new a);
	derivedClassHolder.push_back(new c);
	derivedClassHolder.push_back(new b);

	for (int i = 0; i < (int)derivedClassHolder.size(); i++)
	{
		derivedClassHolder[i]->SetTest(5);
	}

	for (int i = 0; i < (int)derivedClassHolder.size(); i++)
	{
		cout << derivedClassHolder[i]->GetTest() << "  ";
	}system("pause");
	return 0;

	
}