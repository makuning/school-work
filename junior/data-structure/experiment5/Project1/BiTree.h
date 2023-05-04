#pragma once
#include <iostream>

using namespace std;

// �������Ľ��
template <typename DataType>
struct BiNode
{
	DataType data;									// �������
	BiNode<DataType>* left_child, * right_child;	// �������ӣ��Һ���
};

template <typename DataType>
class BiTree
{
public:
	BiTree() { root = Create(); }				// ���캯��������һ�Ŷ�����
	~BiTree() { Release(root); }				// �����������ͷŸ��ڵ�Ĵ洢�ռ�
	void PreOrder() { PreOrder(root); }			// ǰ�����������
	void InOrder() { InOrder(root); };			// �������������
	void PostOrder() { PostOrder(root); }		// �������������
	void LevelOrder();							// �������������
private:
	BiNode<DataType>* Create();					// ���캯������
	void Release(BiNode<DataType> * bt);		// ������������
	void PreOrder(BiNode<DataType> * bt);		// ǰ�������������
	void InOrder(BiNode<DataType> * bt);		// ���������������
	void PostOrder(BiNode<DataType> * bt);		// ���������������
	BiNode<DataType>* root;						// ָ����ڵ��ͷָ��
};

// ǰ�������������
template <typename DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType>* bt)
{
	if (bt == nullptr)
	{
		return;
	}
	else
	{
		cout << bt->data << "\t";
		PreOrder(bt->left_child);
		PreOrder(bt->right_child);
	}
}

// ���������������
template <typename DataType>
void BiTree<DataType>::InOrder(BiNode<DataType>* bt) 
{
	if (bt == nullptr)
	{
		return;
	}
	else
	{
		InOrder(bt->left_child);
		cout << bt->data << "\t";
		InOrder(bt->right_child);
	}
}

// ���������������
template <typename DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType>* bt)
{
	if (bt == nullptr)
	{
		return;
	}
	else
	{
		PostOrder(bt->left_child);
		PostOrder(bt->right_child);
		cout << bt->data << "\t";
	}
}

// �������������
template <typename DataType>
void BiTree<DataType>::LevelOrder() 
{
	BiNode<DataType>* Q[100], * q = nullptr;
	int front = -1, rear = -1;
	if (root == nullptr) return;
	Q[++rear] = root;
	while (front != rear)
	{
		q = Q[++front];
		cout << q->data << "\t";
		if (q->left_child != nullptr) Q[++rear] = q->left_child;
		if (q->right_child != nullptr) Q[++rear] = q->right_child;
	}
}

// ���������������캯������
template <typename DataType>
BiNode<DataType>* BiTree<DataType>::Create()
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		return nullptr;
	}
	else
	{
		BiNode<DataType>* bt;
		bt = new BiNode<DataType>;
		bt->data = ch;
		bt->left_child = Create();
		bt->right_child = Create();
		return bt;
	}
}

// �ͷŸ��ڵ�Ĵ洢�ռ䣬������������
template <typename DataType>
void BiTree<DataType>::Release(BiNode<DataType>* bt)
{
	if (bt == nullptr) return;
	else
	{
		Release(bt->left_child);
		Release(bt->right_child);
		delete bt;
	}
}