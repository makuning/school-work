#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

// 定义单链表的结点
template <typename DataType = int>
struct Node {
	DataType data;
	Node<DataType>* next;
};

template <typename DataType = int>	// 相当于Java的泛型，在C++叫模板
class LinkList
{
public:
	// 将两个链表合并为一个链表
	static LinkList<DataType>* Merge(LinkList<DataType>* first, LinkList<DataType>* second);

	LinkList();						// 无参构造，建立空的顺序表
	LinkList(DataType a[], int n);	// 有参构造，建立长度为n的顺序表
	~LinkList();					// 析构函数，就是在对象销毁时会被执行
	int Length();					// 获取线性表的长度
	DataType Get(int i);			// 按位查找，查找第i个结点
	int Locate(DataType x);			// 按值查找，查找值为x的结点
	void Insert(int i, DataType x);	// 插入操作，在第i个位置插入值为x的结点
	DataType Delete(int i);			// 删除操作，删除第i个结点
	int Empty();					// 判断线性表是否为空
	void PrintList();				// 遍历操作，按序号依次输出各结点
private:
	Node<DataType>* header;			// 单链表的头结点
};

// 将两个链表合并为一个链表
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

// 无参构造，建立只有头节点的单链表
template <typename DataType>
LinkList<DataType>::LinkList() {
	this->header = new Node<DataType>;
	this->header->next = nullptr;
}

// 有参构造，建立长度为n的顺序表，头插法
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

//// 有参构造，建立长度为n的顺序表，尾插法
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

// 析构函数，就是在对象销毁时会被执行
template <typename DataType>
LinkList<DataType>::~LinkList() {

}

// 获取线性表的长度
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

// 按位查找，查找第i个结点
template <typename DataType>
DataType LinkList<DataType>::Get(int i) {
	if (i < 1 || i > this->Length()) {
		throw "位置不存在";
	}
	Node<DataType>* temp = this->header;
	for (int j = 0; j < i; j++) {
		temp = temp->next;
	}
	return temp->data;
}

// 按值查找，查找值为x的结点
// 0：没找到
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

// 插入操作，在第i个位置插入值为x的结点
template <typename DataType>
void LinkList<DataType>::Insert(int i, DataType x) {
	if (i < 1 || i > this->Length() + 1) throw "位置错误";

	Node<DataType>* temp = header, * new_node = new Node<DataType>;
	for (int j = 0; j < i - 1; j++) {
		temp = temp->next;
	}
	new_node->data = x;
	new_node->next = temp->next;
	temp->next = new_node;
}

// 删除操作，删除第i个结点
template <typename DataType>
DataType LinkList<DataType>::Delete(int i) {
	if (i < 1 || i > this->Length()) throw "位置错误";

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

// 判断线性表是否为空
template <typename DataType>
int LinkList<DataType>::Empty() {
	if (this->header->next == nullptr) {
		return 1;
	}
	return 0;
}

// 遍历操作，按序号依次输出各结点
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