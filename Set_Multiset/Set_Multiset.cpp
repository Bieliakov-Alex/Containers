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

template<typename T, typename T1>
void PrintSet(const set<T, T1>& s)
{
	for (auto i = s.begin(); i != s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int main()
{
	//Демонстрация функционального объекта сравнения двух чисел
	MyComp comp;
	int a = 0, b = 0;
	cin >> a >> b;
	cout << (comp(a, b) ? "a>=b" : "a<b") << endl;

	set<int, MyComp> s1({ 1,2,3,4 });
	set<int> s2({ 1,2,3,4 });
	PrintSet(s1);
	PrintSet(s2);

	_getch();
	return 0;
}