#include <set>
#include <conio.h>

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
	_getch();
	return 0;
}