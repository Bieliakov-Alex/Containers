#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

template<typename T>
void printVector(const vector<T>& v)
{
	for (auto i : v) { cout << i << " "; }
	cout << endl;
}

int counter = 0;

class C
{
private:
	int data;
	C() {}
public:
	friend ostream& operator<<(ostream& o, const C& c);
	explicit C(int d) :data{ d } { cout << "Construct C with int " << data << endl; }
	~C() { cout << "Destruct C with int " << data << endl; }
	C(const C& c) :data{ c.data } { cout << "Construct C with copy " << data << endl; }
	C(C&& c) : data{ c.data } { cout << "Construct C with move " << data << endl; }
	const C& operator=(const C& c) { data = c.data; cout << "= " << data<<endl; return *this; }
	operator int() { return data; }
};


int main()
{

	//Демонстрация конструкторов
	//по умолчанию
	vector<int> v1;

	//количество элементов и элемент для заполнения
	vector<int> v2(10, 1);

	//список инициализации
	vector<int> v3({ 1,2,3,4,5,6,7,8,9 });

	//количество элементов
	vector<int> v4(10);

	//через итераторы
	vector<int> v5(v3.begin() + 1, v3.begin() + 4);

	//конструктор перемещения
	vector<int> v6(std::move(vector<int>({ 1,2,3,4,5 })));
	//vector<int> v6(vector<int>({ 1,2,3,4,5 }));

	//конструктор копирования
	vector<int> v7(v6);

	//Демонстрация оператора присвоения
	vector<int> vfirst({ 1,2,3,4,5 });
	vector<int> vsecond({ 6,7,8,9,0 });

	vfirst = vsecond;

	//доступ по индексу
	vsecond[0] = -6;

	cout << "Assignment operator (=)" << endl;
	printVector(vfirst);
	printVector(vsecond);

	//функция assign
	cout << endl << "Assign function" << endl;
	//количество элементов и их значение
	v1.assign(10, 0);
	printVector(v1);

	//присвоение значений через итераторы
	v1.assign(vfirst.begin(), vfirst.end());
	printVector(v1);

	//через список инициализации
	v1.assign({ 5,4,3,2,1,0 });
	printVector(v1);

	//Функция at
	cout << endl << "at function"<<endl;
	cout << "v1.at(0):" << v1.at(0) << " v1.at(5):" << v1.at(5);//cout << " v1.at(6) (error!):" << v1.at(6) << endl;
	cout << endl;

	//Функция front (ссылка на первый элемент)
	cout << endl << "front()" << endl;
	v1.front() = -50;
	cout << "v1.front():" << v1.front() << " v1[0]:" << v1[0] << endl;

	//Функция back (ссылка на последний элемент)
	cout << endl << "back()" << endl;
	v1.back() = -100;
	printVector(v1);

	//Функция data (указатель на первый элемент массива)
	cout << endl << "data" << endl;
	cout << "v1[0]:" << v1[0] << " *v1.data():" << *v1.data() << endl;
	*v1.data() = -42;
	cout << "v1[0]:" << v1[0] << " *v1.data():" << *v1.data() << endl;

	//Функция empty
	cout << endl << "empty" << endl;
	vector<int> vempty;
	cout << (vempty.empty() ? "vempty is empty" : "vempty isn't empty") << endl;
	cout << (v1.empty() ? "v1 is empty" : "v1 isn't empty") << endl;

	//Функция size
	cout << endl << "size" << endl;
	cout << "vempty.size():" << vempty.size() << " v1.size():" << v1.size() << endl;

	//Функция max_size
	cout << endl << "max_size" << endl;
	cout << "vempty.max_size():" << vempty.max_size() <<endl<< "    v1.max_size():" << v1.max_size() << endl;

	//Функция capacity
	cout << endl << "capacity" << endl;
	cout << "vempty.capacity():" << vempty.capacity() << " v1.capacity():" << v1.capacity() << endl;

	//Функция reserve
	cout << endl << "reserve" << endl;
	vempty.reserve(10);
	printVector(vempty);
	v1.reserve(9);
	printVector(v1);
	cout << "vempty.capacity():" << vempty.capacity() << " v1.capacity():" << v1.capacity() << endl;

	//Функция shrink_to_fit
	cout << endl << "shrink_to_fit" << endl;
	vempty.shrink_to_fit();
	v1.shrink_to_fit();
	cout << "vempty.capacity():" << vempty.capacity() << " v1.capacity():" << v1.capacity() << endl;

	//Функция clear
	cout << endl << "clear" << endl;
	vector<int> vclear({ 1,2,3,4,5 });
	cout << "vclear: ";printVector(vclear);
	vclear.clear();
	cout << "vclear: ";printVector(vclear);

	//Функция insert
	cout << endl << "insert" << endl;
	printVector(v1);

	v1.insert(v1.begin() + 3, -65);
	printVector(v1);

	v1.insert(v1.begin() + 5, -88);
	printVector(v1);

	v1.insert(v1.begin() + 3, vsecond.begin(), vsecond.begin() + 2);
	printVector(v1);

	v1.insert(v1.begin() + 3, { -8,-7,-6 });
	printVector(v1);

	//Функция emplace
	cout << endl << "emplace" << endl;
	cout << endl<<"Prepare start"<<endl << endl;
	vector<C> vC(1,C(1));
	vC.push_back(C(2));
	cout <<endl<< "Prepare end"<<endl << endl;
	cout <<endl<< "Insert demonstration:" << endl<<endl;
	vC.insert(vC.begin()+1, C(3));
	//vC.emplace(vC.begin() + 1, 3);
	cout << endl<<"Insert demonstration end: " <<endl<< endl;
	cout << endl << "Emplace demonstration:" << endl << endl;
	vC.emplace(vC.begin() + 1, 4);
	cout << endl << "Emplace demonstration end:" << endl << endl;
	

	//Функция erase
	cout << endl << "erase" << endl;
	cout << "vC: ";
	printVector(vC);
	vC.erase(vC.begin() + 1);
	printVector(vC);
	vC.erase(vC.begin() + 1, vC.begin() + 3);
	printVector(vC);

	//Функция push_back

	//Функция emplace_back

	//Функция pop_back
	cout << endl << "pop_back" << endl;
	cout << "v1: ";
	printVector(v1);
	v1.pop_back();
	cout << "v1.pop_back():" << endl;
	cout << "v1: ";printVector(v1);

	//Функция resize
	cout<<endl << "resize" << endl;
	vector<int> v10({ 1,2,3,4,5,6,7,8,9,0 });
	printVector(v10);
	cout << "v10 size:" << v10.size() << endl;
	v10.resize(20);
	printVector(v10);
	cout << "v10 size:" << v10.size() << endl;
	v10.resize(5);
	printVector(v10);
	cout << "v10 size:" << v10.size() << endl;

	//Функция swap
	cout << endl << "swap" << endl;
	cout << "v1: "; printVector(v1);
	cout << "vempty: ";printVector(vempty);
	v1.swap(vempty);
	cout << "v1: "; printVector(v1);
	cout << "vempty: ";printVector(vempty);
	v1.swap(vempty);



	_getch();
	return 0;
}

ostream & operator<<(ostream & o, const C & c)
{
	o << c.data;
	return o;
}
