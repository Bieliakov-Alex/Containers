#include <iostream>
#include <conio.h>
#include <list>

using namespace std;

template<typename T>
void printList(const list<T>& l)
{
	for (auto i : l)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	cout << "merge" << endl;
	list<int> l1({ 2,3,1 }), l2({ 0,-1,1,2 });
	cout << "l1: ";printList(l1);cout << "l2: ";printList(l2);
	l1.sort(); printList(l1); l2.sort(); printList(l2);
	l1.merge(l2);
	cout << "l1: "; printList(l1);
	cout << "unique" << endl;
	l1.push_back(2);
	printList(l1);
	l1.unique();
	printList(l1);
	_getch();
	return 0;
}