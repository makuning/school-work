#include "BiTree.h"

int main() 
{
	BiTree<char>T{};
	cout << "\n该二叉树的前序遍历序列是：" << endl;
	T.PreOrder();
	cout << "\n该二叉树的中序遍历序列是：" << endl;
	T.InOrder();
	cout << "\n该二叉树的后序遍历序列是：" << endl;
	T.PostOrder();
	cout << "\n该二叉树的层序遍历序列是：" << endl;
	T.LevelOrder();

	return 0;
}