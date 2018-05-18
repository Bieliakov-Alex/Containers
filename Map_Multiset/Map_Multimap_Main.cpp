#include <map>
#include <iostream>
#include <conio.h>

using namespace std;

template<typename T1, typename T2>
void PrintMap(const map<T1, T2>& map)
{
	for (auto i : map)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	_getch();
	return 0;
}