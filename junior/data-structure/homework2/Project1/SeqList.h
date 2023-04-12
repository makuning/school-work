#pragma once
#include <iostream>
using namespace std;

const int MaxSize = 200;			// ���õ���������ܴ洢��Ԫ�ص�����

template <typename DataType = int>	// �൱��Java�ķ��ͣ���C++��ģ��
class SeqList
{
public:
	SeqList();						// �޲ι��죬�����յ�˳���
	SeqList(DataType a[], int n);	// �вι��죬��������Ϊn��˳���
	~SeqList();						// ���������������ڶ�������ʱ�ᱻִ��
	int Length();					// ��ȡ���Ա�ĳ���
	DataType Get(int i);			// ��λ���ң����ҵ�i��Ԫ��
	int Locate(DataType x);			// ��ֵ���ң�����ֵΪx��Ԫ��
	void Insert(int i, DataType x);	// ����������ڵ�i��λ�ò���ֵΪx��Ԫ��
	DataType Delete(int i);			// ɾ��������ɾ����i��Ԫ��
	int Empty();					// �ж����Ա��Ƿ�Ϊ��
	void PrintList();				// ������������������������Ԫ��
private:
	DataType data[MaxSize];			// �������Ԫ�ص�����
	int length;						// ���Ա�ĳ���
};

// �޲ι��죬�����յ�˳���
template <typename DataType>
SeqList<DataType>::SeqList() {
	this->length = 0;
};

// �вι��죬��������Ϊn��˳���
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	if (n > MaxSize) throw "�����Ƿ�";
	for (int i = 0; i < n; i++) {
		this->data[i] = a[i];
	}
	this->length = n;
}

// ���������������ڶ�������ʱ�ᱻִ��
template <typename DataType>
SeqList<DataType>::~SeqList() {
	cout << "��������" << endl;
}

// ��ȡ���Ա�ĳ���
template <typename DataType>
int SeqList<DataType>::Length() {
	return this->length;
}

// ��λ���ң����ҵ�i��Ԫ��
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {
	if (i < 1 || i > this->length) {
		throw "λ�ò�����";
	}
	return this->data[i - 1];
}

// ��ֵ���ң�����ֵΪx��Ԫ��
// 0��û�ҵ�
template <typename DataType>
int SeqList<DataType>::Locate(DataType x) {
	for (int i = 0; i < length; i++) {
		if (this->data[i] == x) {
			return i + 1;
		}
	}
	return 0;
}

// ����������ڵ�i��λ�ò���ֵΪx��Ԫ��
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x) {
	if (length >= MaxSize) throw "����";
	if (i < 1 || i > length + 1) throw "λ�ô���";
	for (int j = length; j >= i - 1; j--) {
		this->data[j + 1] = this->data[j];
	}
	this->data[i - 1] = x;
	this->length++;
}

// ɾ��������ɾ����i��Ԫ��
template <typename DataType>
DataType SeqList<DataType>::Delete(int i) {
	if (i < 1 || i > length) throw "λ�ô���";

	DataType del = this->Get(i);

	for (int j = i-1; j < length - 1; j++) {
		this->data[j] = this->data[j + 1];
	}

	this->length--;

	return del;
}

// �ж����Ա��Ƿ�Ϊ��
template <typename DataType>
int SeqList<DataType>::Empty() {
	return this->length ? 0 : 1;
}

// ������������������������Ԫ��
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
