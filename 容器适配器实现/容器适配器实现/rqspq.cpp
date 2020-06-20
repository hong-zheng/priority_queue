#define _CRT_SECURE_NO_WARNGINS 1
#include <queue>

// 适配器就类似于转换器
// 容器适配器

// 双端队列
/*

两端都可以操作
逻辑上连续的结构，物理上不是整体连续

指针数组+缓冲区

双端队列：
实现：指针数组+buffer -->动态二维数组
1、头插，头删，尾插，尾删时间复杂度都是O(1)，不需要移动元素
2、支持随机访问：逻辑连续，物理不完全连续
	效率没有vector高，需要进行位置的换算，
3、增容代价小，不需要拷贝所有的元素内容。
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