#include <set>
#include <conio.h>
#include <iostream>

using namespace std;

class MyComp
{
public:
	bool operator()(const int& first, const int& second) const
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
	set<int> s2({ 1,2,3,4,5 });
	PrintSet(s1);
	PrintSet(s2);

	//lower_bound

	//TODO: определить, как в lower_bound использовать свой компаратор

	auto it=s2.lower_bound(3);
	cout << *it << endl;

	//upper_bound
	auto it1 = s2.upper_bound(3);
	cout << *it1 << endl;

	_getch();
	return 0;
}