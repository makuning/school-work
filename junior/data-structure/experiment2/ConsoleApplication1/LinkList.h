#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

// ���嵥����Ľ��
template <typename DataType = int>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template <typename DataType = int>	// �൱��Java�ķ��ͣ���C++��ģ��
class LinkList
{
public:
	// ����������ϲ�Ϊһ������
	static LinkList<DataType>* Merge(LinkList<DataType>* first, LinkList<DataType>* second);

	LinkList();						// �޲ι��죬�����յ�˳���
	LinkList(DataType a[], int n);	// �вι��죬��������Ϊn��˳���
	~LinkList();					// ���������������ڶ�������ʱ�ᱻִ��
	int Length();					// ��ȡ���Ա�ĳ���
	DataType Get(int i);			// ��λ���ң����ҵ�i�����
	int Locate(DataType x);			// ��ֵ���ң�����ֵΪx�Ľ��
	void Insert(int i, DataType x);	// ����������ڵ�i��λ�ò���ֵΪx�Ľ��
	DataType Delete(int i);			// ɾ��������ɾ����i�����
	int Empty();					// �ж����Ա��Ƿ�Ϊ��
	void PrintList();				// ���������������������������
private:
	Node<DataType>* header;			// �������ͷ���
};

// ����������ϲ�Ϊһ������
template <typename DataType>
LinkList<DataType>* LinkList<DataType>::Merge(LinkList<DataType>* first, LinkList<DataType>* second) {
	LinkList<DataType> list;

	for (int i = 1; i <= second->Length(); i++) {
		list.Insert(1, second->Get(i));
	}

	for (int i = 1; i <= first->Length(); i++) {
		list.Insert(1,first->Get(i));
	}


	return &list;
}

// �޲ι��죬����ֻ��ͷ�ڵ�ĵ�����
template <typename DataType>
LinkList<DataType>::LinkList() {
	this->header = new Node<DataType>;
	this->header->next = nullptr;
}

// �вι��죬��������Ϊn��˳���ͷ�巨
template <typename DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
	this->header = new Node<DataType>;
	this->header->next = nullptr;
	Node<DataType>* temp = nullptr;
	for (int i = 0; i < n; i++) {
		temp = this->header->next;
		this->header->next = new Node<DataType>;
		this->header->next->data = a[i];
		this->header->next->next = temp;
	}
}

//// �вι��죬��������Ϊn��˳���β�巨
//template <typename DataType>
//LinkList<DataType>::LinkList(DataType a[], int n) {
//	this->header = new Node<DataType>;
//	Node<DataType>* temp = this->header;
//	for (int i = 0; i < n; i++) {
//		temp->next = new Node<DataType>;
//		temp->next->data = a[i];
//		temp = temp->next;
//	}
//	temp->next = nullptr;
//}

// ���������������ڶ�������ʱ�ᱻִ��
template <typename DataType>
LinkList<DataType>::~LinkList() {

}

// ��ȡ���Ա�ĳ���
template <typename DataType>
int LinkList<DataType>::Length() {
	int cnt = 0;
	Node<DataType>* temp = this->header;
	while (temp->next != nullptr) {
		temp = temp->next;
		cnt++;
	}
	return cnt;
}

// ��λ���ң����ҵ�i�����
template <typename DataType>
DataType LinkList<DataType>::Get(int i) {
	if (i < 1 || i > this->Length()) {
		throw "λ�ò�����";
	}
	Node<DataType>* temp = this->header;
	for (int j = 0; j < i; j++) {
		temp = temp->next;
	}
	return temp->data;
}

// ��ֵ���ң�����ֵΪx�Ľ��
// 0��û�ҵ�
template <typename DataType>
int LinkList<DataType>::Locate(DataType x) {
	Node<DataType>* temp = header;
	for (int i = 0; i < this->Length(); i++) {
		temp = temp->next;
		if (temp->data == x) {
			return i + 1;
		}
	}
	return 0;
}

// ����������ڵ�i��λ�ò���ֵΪx�Ľ��
template <typename DataType>
void LinkList<DataType>::Insert(int i, DataType x) {
	if (i < 1 || i > this->Length() + 1) throw "λ�ô���";

	Node<DataType>* temp = header, * new_node = new Node<DataType>;
	for (int j = 0; j < i - 1; j++) {
		temp = temp->next;
	}
	new_node->data = x;
	new_node->next = temp->next;
	temp->next = new_node;
}

// ɾ��������ɾ����i�����
template <typename DataType>
DataType LinkList<DataType>::Delete(int i) {
	if (i < 1 || i > this->Length()) throw "λ�ô���";

	DataType del = this->Get(i);

	Node<DataType>* node = header, * temp = nullptr;
	for (int j = 0; j < i-1; j++) {
		node = node->next;
	}
	temp = node->next;
	node->next = node->next->next;
	delete(temp);

	return del;
}

// �ж����Ա��Ƿ�Ϊ��
template <typename DataType>
int LinkList<DataType>::Empty() {
	if (this->header->next == nullptr) {
		return 1;
	}
	return 0;
}

// ���������������������������
template <typename DataType>
void LinkList<DataType>::PrintList() {
	if (this->Empty()) {
		cout << "{}" << endl;
		return;
	}

	Node<DataType>* temp = header->next;

	cout << "{" << temp->data;
	while (temp->next != nullptr) {
		temp = temp->next;
		cout << "," << temp->data;
	}
	cout << "}" << endl;
}