/*
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
using namespace std;

void test(){
	// ͨ����ʵ�֣�Ĭ��Ϊ���
	priority_queue<int> pq;

	pq.push(10);
	pq.push(1);
	pq.push(0);
	pq.push(120);
	pq.push(10);
	pq.push(23);
	pq.push(3);
	pq.push(10);

	while (!pq.empty()){
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

struct A{
	A(int a = 1,int b=1,int c=1)
		:_a(a)
		, _b(b)
		, _c(c){}

	bool operator<(const A& c){
		return _a < c._a;
	}

	//bool operator>(const A& c){
	//	return _a < c._a;
	//}
	int _a;
	int _b;
	int _c;
};

ostream& operator<<(ostream& cout, const A& c){
	cout << c._a << "-" << c._b << "-" << c._c << endl;
	return cout;
}

// �º�����ģ��
template<class T>
struct Less
{
	//�������������
	bool operator() (const T& a1, const T& a2){
		return a1 < a2;
	}
};


// �º�����ģ��
template<class T>
struct Greater
{
	//�������������
	bool operator() (const T& a1, const T& a2){
		return a1 > a2;
	}
};
void test2(){
	Less<A> lc;
	A a(1, 2, 3);
	A a1(3, 2, 3);
	bool ret = lc.operator()(a,a1);
	ret = lc(a, a1); //�ȼ��� lc.operator()(a,a1);
}
void test1(){
	//���ȼ����д���Զ������ͣ��Զ���������Ҫ֧�ִ�С�Ƚ�����
	// ����ѣ���Ҫ�ṩС�ڵıȽ�
	priority_queue<A> apq;

	// ��С��
	// ��Ҫ�ṩ���Խ��д��ڱȽϵķº�����
	priority_queue<A, vector<A>, Greater<A>> PQ;
	// ���
	priority_queue<A, vector<A>, Less<A>> PQ;
}

void test11(){
	//stack<int, vector<int>> vv;

}
int main1(){


	system("pause");
	return 0;
}
*/