#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <deque>
#include <list>
using namespace std;

// 容器适配器，用双端队列deque实现
template<class T,class Container = deque<T>>
class Stack{
public:
	void push(const T& val){
		_c.push_back(val);
	}

	void pop(){
		_c.pop_back();
	}

	const T& top(){
		return _c.back();
	}

	size_t size() const{
		return _c.size();
	}

	bool empty() const{
		return _c.empty();
	}


private:
	Container _c;
};


template<class T,class Container = deque<T>>
class Queue{
public:
	void push(const T& val){
		_c.push_back(val);
	}

	void pop(){
		_c.pop_front();
	}

	size_t size() const{
		return _c.size();
	}

	bool empty() const{
		return _c.empty();
	}

	T& back() {
		return _c.back();
	}

	T& front() {
		return _c.front();
	}

	const T& back() const {
		return _c.back();
	}

	const T& front() const {
		return _c.front();
	}
private:
	Container _c;
};
void test(){
	//Stack<int> st;
	//Stack<int, vector<int>> st;
	Stack<int, list<int>> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty()){
		int e = st.top();
		cout << e << " ";
		st.pop();
	}
	cout << endl;
}

void testQ(){
	//Queue<int> q;
	// vector : 不能实现队列，可以随机访问
	Queue<int,list<int>> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(4);

	while (!q.empty())
	{
		int e = q.front();
		q.pop();
		cout << e << " ";
	}
	cout << endl;
}

template<class T>
struct Greater{
	bool operator() (const T& val1, const T& val2){
		return val1 > val2;
	}
};

template<class T>
struct Less{
	bool operator() (const T& val1, const T& val2){
		return val1 < val2;
	}
};

// 优先级队列的实现
// 整一个仿函数 Compares
template < class T, class Container = vector<T> , class Compare = Less<T>> 
class Priority_Queue{
public:
	void push(const T& val){
		_c.push_back(val);
		shiftUp(_c.size()-1);
	}
	void pop(){
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}
	T& top(){
		return _c.front();
	}
	size_t size() const{
		return _c.size();
	}

	bool empty() const{
		return _c.empty();
	}
private:
	void shiftDown(int parent)
	{
		int child = 2 * parent + 1;

		while (child < size()){
			//if (child + 1 < size() && _c[child] < _c[child+1]){
			// 通过仿函数实现比较逻辑
			if (child + 1 < size() && _cmp(_c[child] , _c[child + 1])){
				child++;
			}
			if (_cmp(_c[parent] , _c[child])){
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}

	}
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0){
			//if (_c[parent] < _c[child]){
			if (_cmp(_c[parent] , _c[child])){

				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	Container _c;
	Compare _cmp;
};

void test3(){
	// 小堆
	Priority_Queue<int,vector<int>,Greater<int>> pq;



}
void testpriority(){
	//Priority_Queue<int> pq;
	Priority_Queue<int, vector<int>, Greater<int>> pq;

	pq.push(1);
	pq.push(23);
	pq.push(3);
	pq.push(24);
	pq.push(5);

	while (!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << endl;
}


// 自定义类型一定要定义大小于符号重载
class Date{
public:
	Date(int y, int m, int d)
		:_y(y)
		, _m(m)
		, _d(d)
	{	}

	bool operator>(const Date& d)const{
		if (_y > d._y){
			return true;
		}
		else{
			if (_y == d._y){
				if (_m > d._m){
					return true;
				}
				else{
					if (_m == d._m){
						if (_d > d._d)
							return true;
					}
				}
			}
		}
		return false;
	}

	bool operator<(const Date& d)const{
		if (_y < d._y){
			return true;
		}
		else{
			if (_y == d._y){
				if (_m < d._m){
					return true;
				}
				else{
					if (_m == d._m){
						if (_d < d._d)
							return true;
					}
				}
			}
		}
		return false;
	}
public:
	int _y;
	int _m;
	int _d;
};

ostream& operator<<(ostream& cout, const Date& d){
	cout << d._y << "-" << d._m << "-" << d._d << endl;
	return cout;
}
int main(){
	testpriority();
	//testQ();
	//test();
	system("pause");
	return 0;
}

/*



// 优先级队列的实现
template < class T, class Container = vector<T> >
class Priority_Queue{
public:
void push(const T& val){
_c.push_back(val);
shiftUp(_c.size()-1);
}
void pop(){
swap(_c[0], _c[_c.size() - 1]);
_c.pop_back();
shiftDown(0);
}
T& top(){
return _c.front();
}
size_t size() const{
return _c.size();
}

bool empty() const{
return _c.empty();
}
private:
void shiftDown(int parent){
int child = 2 * parent + 1;

while (child < size()){
if (child + 1 < size() && _c[child] < _c[child+1]){
child++;
}
if (_c[parent] < _c[child]){
swap(_c[parent], _c[child]);
parent = child;
child = 2 * parent + 1;
}
else
break;
}

}
void shiftUp(int child){
int parent = (child - 1) / 2;
while (child > 0){
if (_c[parent] < _c[child]){
swap(_c[parent], _c[child]);
child = parent;
parent = (child - 1) / 2;
}
else
break;
}
}
private:
Container _c;
};

*/















//void test111(){
//	deque<int> dq;
//}
/*

// 有基础模板
template <class T>
T Add( T& a, T& b){
return a + b;
}
// 字符相加就是ASCII码值相加，有溢出的风险

// 特殊类型的特化版本，字符串的加法
// 普通函数与特化函数共存时，普通优先
template<>
char* Add<char*>(char*& a, char*& b){
// 字符串的拼接，将b拼接到a上，然后返回a的地址
strcat(a, b);
return a;
}

// 对于函数模板不能处理的特殊类型，一般会定义一个此类型的普通函数
// 函数模板的特化比较少用
char* Add(char*& a, char*& b){
strcat(a, b);
return a;
}
void test(){
char* ptr = new char[100];
strcpy(ptr, "123");
char* ptr2 = new char[100];
strcpy(ptr2, "abc");

// 此处通用的模板就做不了字符串的拼接，特殊类型，通用模板解决不了，因此就做了一个模板的特化
// 本意是拼接字符串，但是此处是两个指针相加
ptr  = Add(ptr, ptr2);

cout << ptr << endl;
}

// 类里面的特化
// 模板参数：类型模板参数(class typename : 关键字后面跟的都是类型模板参数)，非类型模板参数(数值类型)
// 非类型模板参数：可以作为常量使用，它的值需要在编译的时候确定
template<class T,size_t N>
class Array{
public:
private:
T _array[N];
};

void test2(){
// 20：非类型模板参数
Array<int, 20>  array;
}

// 类模板特化
// 1、全特化 --> 所有的参数都为具体类型
//特化之前需要存在基础类模板
template<class T1,class T2>
class A{
public:
A(){
cout << "A(T1,T2)" << endl;
}
private:
T1 _t1;
T2 _t2;
};
// 全特化
template<>
class A < int, char >
{
public:
A(){
cout << "A<int,char>" << endl;
}
private:
int _t1;
int _t2;
};



// 2、偏特化:a、部分特化，b、对模板参数做进一步的限制
template<class T1>
class A < T1, double >
{
public:
A(){
cout << "A(T1,double)" << endl;
}
private:
T1 _t1;
double _t2;
};

// 限制特化
// 限制特化引用的一个类
template<class T1,class T2>
class A < T1&, T2& >
{
public:
A(){
cout << "A<T1&,T2&>" << endl;
}
};
void test3(){
A<int, int> a;
A<int, char> b; //走的全特化版本
A<int, double> c;//部分特化版本调用
A<int&, double&> d;
A<char&, int&> e;
}
*/


/*
void test4(){
	//  输出运算符重载函数

	// 调用 ostream 对象的成员函数 operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);

	// 调用 ostream 对象的成员函数 operator<<
	cout << "abc def" << 1 << 2.0 << endl;
	cerr << "abc def" << 1 << 2.0 << endl;
	clog << "abc def" << 1 << 2.0 << endl;

	// 调用普通函数operator<<(ostream&,char*)
	operator<<(cout, "abd"); operator<<(cout, "ABC");


	int a;
	// 调用istream对象的成员函数 operator>>
	cin >> a;
	cin.operator>>(a);


	// cin : 输入流对象；cout:输出流对象

	//调用的是同一个函数，因此需要指定格式才能完成
	// C 语言对于不同类型数据-的输入输出调用同一个函数
	// 然而C++对于不同类型的数据，输入输出调用不同的重载函数
	scanf("%d", &a);
	printf("%d\n", a);
}

#include <fstream>

void test5(){
	// 输入文件对象
	ifstream fin("test.txt");
	if (!fin.is_open()) // 判断是否打开
	{
		cout << "文件打开失败"<<endl;
	}

	// 问本读写
	// 问本读 getline() , >>
	string str;

	char strr[100];
	//fin >> strr; // 遇到空格换行制表符结束
	//cout << strr << endl;

	// getline : 遇到换行结束或者读完最大字节结束
	// 读的时候包括 '\0'，还可以指定结束符
	//fin.getline(strr, ' ');
	fin.getline(strr, 100);
	cout << strr << endl;

	fin.getline(strr, 100);
	cout << strr << endl;
	fin.getline(strr, 100);
	cout << strr << endl;


	fin.getline(strr, 100);
	cout << strr << endl;

	fin.getline(strr, 100);
	cout << strr << endl;
}

void test6(){
	// 文本读写
	ofstream fout("new.test.txt");
	if (!fout.is_open()){
		cout << "文件打开失败" << endl;
		return;
	}
	// >>
	fout << "123" << endl;
	fout << "abcd" << endl;
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open()){
		cout << " fin 文件打开失败" << endl;
		return;
	}

	char str[100];
	fin >> str;
	cout << str << endl;
	fin >> str;
	cout << str << endl;
	fin.close();
}

struct Student{
	int _age;
	char _name[100];
};
//文本读写：效率低，可读性好
// 二进制读写：效率高，可读性差
// 不建议交叉使用：
void writeFile(const char* filename){
	ofstream fout(filename);
	if (!fout.is_open()){
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");

	// 二进制写
	fout.write((char*)&st, sizeof(Student));
	fout.close();
}

void readFile(const char* filename){
	ifstream fin(filename);
	if (!fin.is_open()){
		return;
	}
	Student st;
	fin.read((char*)&st, sizeof(Student));
	fin.close();
}

void test10(){
	char str[100];
	itoa(100, str, 10);
	itoa(100, str, 16);
	itoa(100, str, 2);
	itoa(100, str, 8);


	//把非字符串数据转成字符串形式数据

}
int maien(){
	test5();
	//test4();

	//test3();
	//test();

	system("pause");
	return 0;
}
*/