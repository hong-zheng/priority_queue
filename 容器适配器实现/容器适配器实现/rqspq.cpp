#define _CRT_SECURE_NO_WARNGINS 1
#include <queue>

// ��������������ת����
// ����������

// ˫�˶���
/*

���˶����Բ���
�߼��������Ľṹ�������ϲ�����������

ָ������+������

˫�˶��У�
ʵ�֣�ָ������+buffer -->��̬��ά����
1��ͷ�壬ͷɾ��β�壬βɾʱ�临�Ӷȶ���O(1)������Ҫ�ƶ�Ԫ��
2��֧��������ʣ��߼�������������ȫ����
	Ч��û��vector�ߣ���Ҫ����λ�õĻ��㣬
3�����ݴ���С������Ҫ�������е�Ԫ�����ݡ�
*/


// push , pop , front , back , size , empty
template <class T, class Container = queue<T> >
class Queue{
public:
	void push(const T& val){
		_c.push_back(val);
	}
private:
	Container _c;
};
int main(){

	while (1);
	return 0;
}

void swap(int& l, int& r){
	int tmp = l;
	l = r;
	r = tmp;
}
void shiftDown(int arr[], int parent){
	if (parent <= 0)
		return;
	int len = parent / 2;
	int right = parent / 2 + 1;
	if (arr[len] < arr[right]){

	}
}