#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 200;			// 设置单链表最多能存储的元素的数量

template <typename DataType = int>	// 相当于Java的泛型，在C++叫模板
class SeqList
{
public:
	SeqList();						// 无参构造，建立空的顺序表
	SeqList(DataType a[], int n);	// 有参构造，建立长度为n的顺序表
	~SeqList();						// 析构函数，就是在对象销毁时会被执行
	int Length();					// 获取线性表的长度
	DataType Get(int i);			// 按位查找，查找第i个元素
	int Locate(DataType x);			// 按值查找，查找值为x的元素
	void Insert(int i, DataType x);	// 插入操作，在第i个位置插入值为x的元素
	DataType Delete(int i);			// 删除操作，删除第i个元素
	int Empty();					// 判断线性表是否为空
	void PrintList();				// 遍历操作，按序号依次输出各元素
private:
	DataType data[MaxSize];			// 存放数据元素的数组
	int length;						// 线性表的长度
};

// 无参构造，建立空的顺序表
template <typename DataType>
SeqList<DataType>::SeqList() {
	this->length = 0;
};

// 有参构造，建立长度为n的顺序表
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	if (n > MaxSize) throw "参数非法";
	for (int i = 0; i < n; i++) {
		this->data[i] = a[i];
	}
	this->length = n;
}

// 析构函数，就是在对象销毁时会被执行
template <typename DataType>
SeqList<DataType>::~SeqList() {
	cout << "被销毁了" << endl;
}

// 获取线性表的长度
template <typename DataType>
int SeqList<DataType>::Length() {
	return this->length;
}

// 按位查找，查找第i个元素
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {
	if (i < 1 || i > this->length) {
		throw "位置不存在";
	}
	return this->data[i - 1];
}

// 按值查找，查找值为x的元素
// 0：没找到
template <typename DataType>
int SeqList<DataType>::Locate(DataType x) {
	for (int i = 0; i < length; i++) {
		if (this->data[i] == x) {
			return i + 1;
		}
	}
	return 0;
}

// 插入操作，在第i个位置插入值为x的元素
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x) {
	if (length >= MaxSize) throw "已满";
	if (i < 1 || i > length + 1) throw "位置错误";
	for (int j = length; j >= i - 1; j--) {
		this->data[j + 1] = this->data[j];
	}
	this->data[i - 1] = x;
	this->length++;
}

// 删除操作，删除第i个元素
template <typename DataType>
DataType SeqList<DataType>::Delete(int i) {
	if (i < 1 || i > length) throw "位置错误";

	DataType del = this->Get(i);

	for (int j = i-1; j < length - 1; j++) {
		this->data[j] = this->data[j + 1];
	}

	this->length--;

	return del;
}

// 判断线性表是否为空
template <typename DataType>
int SeqList<DataType>::Empty() {
	return this->length ? 0 : 1;
}

// 遍历操作，按序号依次输出各元素
template <typename DataType>
void SeqList<DataType>::PrintList() {
	if (this->Empty()) {
		cout << "{}" << endl;
		return;
	}

	int i = 0;

	cout << "{";
	for (; i < length - 1; i++) {
		cout << this->data[i] << ",";
	}
	cout << this->data[i] << "}" << endl;
}
