#include "SeqList.h"
#include <iostream>

// �޲ι��죬�����յ�˳���
template <typename DataType>
SeqList<DataType>::SeqList() {
	std::cout << "���Ա��ѱ�����" << std::endl;
};

// �вι��죬��������Ϊn��˳���
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	std::cout << "���Ա��ѱ�����������Ϊ" << n << std::endl;
}

// ���������������ڶ�������ʱ�ᱻִ��
template <typename DataType>
SeqList<DataType>::~SeqList() {

}

// ��ȡ���Ա�ĳ���
template <typename DataType>
int SeqList<DataType>::Length() {

}

// ��λ���ң����ҵ�i��Ԫ��
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {

}

// ��ֵ���ң�����ֵΪx��Ԫ��
template <typename DataType>
int SeqList<DataType>::Locate(DataType x) {

}

// ����������ڵ�i��λ�ò���ֵΪx��Ԫ��
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x) {

}

// ɾ��������ɾ����i��Ԫ��
template <typename DataType>
DataType SeqList<DataType>::Delete(int i) {

}

// �ж����Ա��Ƿ�Ϊ��
template <typename DataType>
int SeqList<DataType>::Empty() {

}

// ������������������������Ԫ��
template <typename DataType>
void SeqList<DataType>::PrintList() {

}
