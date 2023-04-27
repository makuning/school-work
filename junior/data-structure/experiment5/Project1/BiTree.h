#pragma once

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

// ����һ���յĶ�����
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
