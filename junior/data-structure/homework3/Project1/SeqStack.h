#pragma once
#include <iostream>

using namespace std;

const int StackSize = 10;

template <typename DataType = int>
class SeqStack {
public:
	SeqStack();					// ���캯��
	~SeqStack();				// ��������
	void Push(DataType x);		// ��ջ����
	DataType Pop();				// ��ջ����
	DataType GetTop();			// ȥջ��Ԫ��
	int Empty();				// �ж�ջ�Ƿ�Ϊ��
private:
	DataType data[StackSize];	// ���ջԪ�ص�����
	int top;					// ջ��Ԫ���������е��±�
};

// ���캯��
template <typename DataType>
SeqStack<DataType>::SeqStack() {
	this->top = -1;	// ��ʼ��ջ��Ԫ���±�
}

// ��������
template <typename DataType>
SeqStack<DataType>::~SeqStack() {

}

// ��ջ
template <typename DataType>
void SeqStack<DataType>::Push(DataType x) {
	if (this->top == StackSize - 1) throw "ջ���";
	this->data[++top] = x;
}

// ��ջ
template <typename DataType>
DataType SeqStack<DataType>::Pop() {
	return this->data[this->top--];
}

// ȡջ��
template <typename DataType>
DataType SeqStack<DataType>::GetTop() {
	return this->data[this->top];
}

// �ж�ջ�Ƿ�Ϊ��
template <typename DataType>
int SeqStack<DataType>::Empty() {
	return (this->top == -1) ? 1 : 0;
}
