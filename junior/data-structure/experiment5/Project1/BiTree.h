#pragma once

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

// 创建一个空的二叉树
template <typename DataType>
BiNode<DataType>* BiTree<DataType>::Create()
{
	root = nullptr;
}


template <typename DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType>* bt)
{
	if () {}
}
