#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <deque>
#include <list>
using namespace std;

// ��������������˫�˶���dequeʵ��
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
	// vector : ����ʵ�ֶ��У������������
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

// ���ȼ����е�ʵ��
// ��һ���º��� Compares
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
			// ͨ���º���ʵ�ֱȽ��߼�
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
	// С��
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


// �Զ�������һ��Ҫ�����С�ڷ�������
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



// ���ȼ����е�ʵ��
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

// �л���ģ��
template <class T>
T Add( T& a, T& b){
return a + b;
}
// �ַ���Ӿ���ASCII��ֵ��ӣ�������ķ���

// �������͵��ػ��汾���ַ����ļӷ�
// ��ͨ�������ػ���������ʱ����ͨ����
template<>
char* Add<char*>(char*& a, char*& b){
// �ַ�����ƴ�ӣ���bƴ�ӵ�a�ϣ�Ȼ�󷵻�a�ĵ�ַ
strcat(a, b);
return a;
}

// ���ں���ģ�岻�ܴ�����������ͣ�һ��ᶨ��һ�������͵���ͨ����
// ����ģ����ػ��Ƚ�����
char* Add(char*& a, char*& b){
strcat(a, b);
return a;
}
void test(){
char* ptr = new char[100];
strcpy(ptr, "123");
char* ptr2 = new char[100];
strcpy(ptr2, "abc");

// �˴�ͨ�õ�ģ����������ַ�����ƴ�ӣ��������ͣ�ͨ��ģ�������ˣ���˾�����һ��ģ����ػ�
// ������ƴ���ַ��������Ǵ˴�������ָ�����
ptr  = Add(ptr, ptr2);

cout << ptr << endl;
}

// ��������ػ�
// ģ�����������ģ�����(class typename : �ؼ��ֺ�����Ķ�������ģ�����)��������ģ�����(��ֵ����)
// ������ģ�������������Ϊ����ʹ�ã�����ֵ��Ҫ�ڱ����ʱ��ȷ��
template<class T,size_t N>
class Array{
public:
private:
T _array[N];
};

void test2(){
// 20��������ģ�����
Array<int, 20>  array;
}

// ��ģ���ػ�
// 1��ȫ�ػ� --> ���еĲ�����Ϊ��������
//�ػ�֮ǰ��Ҫ���ڻ�����ģ��
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
// ȫ�ػ�
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



// 2��ƫ�ػ�:a�������ػ���b����ģ���������һ��������
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

// �����ػ�
// �����ػ����õ�һ����
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
A<int, char> b; //�ߵ�ȫ�ػ��汾
A<int, double> c;//�����ػ��汾����
A<int&, double&> d;
A<char&, int&> e;
}
*/


/*
void test4(){
	//  �����������غ���

	// ���� ostream ����ĳ�Ա���� operator<<
	cout.operator<<("abc").operator<<(1).operator<<(2.0).operator<<(endl);

	// ���� ostream ����ĳ�Ա���� operator<<
	cout << "abc def" << 1 << 2.0 << endl;
	cerr << "abc def" << 1 << 2.0 << endl;
	clog << "abc def" << 1 << 2.0 << endl;

	// ������ͨ����operator<<(ostream&,char*)
	operator<<(cout, "abd"); operator<<(cout, "ABC");


	int a;
	// ����istream����ĳ�Ա���� operator>>
	cin >> a;
	cin.operator>>(a);


	// cin : ����������cout:���������

	//���õ���ͬһ�������������Ҫָ����ʽ�������
	// C ���Զ��ڲ�ͬ��������-�������������ͬһ������
	// Ȼ��C++���ڲ�ͬ���͵����ݣ�����������ò�ͬ�����غ���
	scanf("%d", &a);
	printf("%d\n", a);
}

#include <fstream>

void test5(){
	// �����ļ�����
	ifstream fin("test.txt");
	if (!fin.is_open()) // �ж��Ƿ��
	{
		cout << "�ļ���ʧ��"<<endl;
	}

	// �ʱ���д
	// �ʱ��� getline() , >>
	string str;

	char strr[100];
	//fin >> strr; // �����ո����Ʊ������
	//cout << strr << endl;

	// getline : �������н������߶�������ֽڽ���
	// ����ʱ����� '\0'��������ָ��������
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
	// �ı���д
	ofstream fout("new.test.txt");
	if (!fout.is_open()){
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	// >>
	fout << "123" << endl;
	fout << "abcd" << endl;
	fout.close();

	ifstream fin("new.test.txt");
	if (!fin.is_open()){
		cout << " fin �ļ���ʧ��" << endl;
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
//�ı���д��Ч�ʵͣ��ɶ��Ժ�
// �����ƶ�д��Ч�ʸߣ��ɶ��Բ�
// �����齻��ʹ�ã�
void writeFile(const char* filename){
	ofstream fout(filename);
	if (!fout.is_open()){
		return;
	}
	Student st;
	st._age = 20;
	strcpy(st._name, "bitekeji");

	// ������д
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


	//�ѷ��ַ�������ת���ַ�����ʽ����

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