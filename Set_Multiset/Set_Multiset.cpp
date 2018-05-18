#include <set>
#include <conio.h>
#include <iostream>

using namespace std;

class MyComp
{
public:
	bool operator()(const int& first, const int& second)
	{
		return !(first < second);
		/*
		if(first<second)
		{
			return false;
		}
		else
		{
			return true;
		}
		*/
	}
};

int main()
{
	//Демонстрация функционального объекта сравнения двух чисел
	MyComp comp;
	int a = 0, b = 0;
	cin >> a >> b;
	cout << (comp(a, b) ? "a>=b" : "a<b") << endl;

	_getch();
	return 0;
}