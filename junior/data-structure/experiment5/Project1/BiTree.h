#pragma once
#include <iostream>

using namespace std;

// 二叉树的结点
template <typename DataType>
struct BiNode
{
	DataType data;									// 结点数据
	BiNode<DataType>* left_child, * right_child;	// 结点的左孩子，右孩子
};

template <typename DataType>
class BiTree
{
public:
	BiTree() { root = Create(); }				// 构造函数，建立一颗二叉树
	~BiTree() { Release(root); }				// 析构函数，释放各节点的存储空间
	void PreOrder() { PreOrder(root); }			// 前序遍历二叉树
	void InOrder() { InOrder(root); };			// 中序遍历二叉树
	void PostOrder() { PostOrder(root); }		// 后序遍历二叉树
	void LevelOrder();							// 层序遍历二叉树
private:
	BiNode<DataType>* Create();					// 构造函数调用
	void Release(BiNode<DataType> * bt);		// 析构函数调用
	void PreOrder(BiNode<DataType> * bt);		// 前序遍历函数调用
	void InOrder(BiNode<DataType> * bt);		// 中序遍历函数调用
	void PostOrder(BiNode<DataType> * bt);		// 后序遍历函数调用
	BiNode<DataType>* root;						// 指向根节点的头指针
};

// 前序遍历函数调用
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

// 中序遍历函数调用
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

// 后序遍历函数调用
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

// 层序遍历二叉树
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

// 建立二叉树，构造函数调用
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

// 释放各节点的存储空间，析构函数调用
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