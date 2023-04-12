#pragma once
#include <iostream>

using namespace std;

const int StackSize = 10;

template <typename DataType = int>
class SeqStack {
public:
	SeqStack();					// 构造函数
	~SeqStack();				// 析构函数
	void Push(DataType x);		// 入栈操作
	DataType Pop();				// 出栈操作
	DataType GetTop();			// 去栈顶元素
	int Empty();				// 判断栈是否为空
private:
	DataType data[StackSize];	// 存放栈元素的数组
	int top;					// 栈顶元素在数组中的下标
};

// 构造函数
template <typename DataType>
SeqStack<DataType>::SeqStack() {
	this->top = -1;	// 初始化栈顶元素下标
}

// 析构函数
template <typename DataType>
SeqStack<DataType>::~SeqStack() {

}

// 入栈
template <typename DataType>
void SeqStack<DataType>::Push(DataType x) {
	if (this->top == StackSize - 1) throw "栈溢出";
	this->data[++top] = x;
}

// 出栈
template <typename DataType>
DataType SeqStack<DataType>::Pop() {
	return this->data[this->top--];
}

// 取栈顶
template <typename DataType>
DataType SeqStack<DataType>::GetTop() {
	return this->data[this->top];
}

// 判断栈是否为空
template <typename DataType>
int SeqStack<DataType>::Empty() {
	return (this->top == -1) ? 1 : 0;
}
