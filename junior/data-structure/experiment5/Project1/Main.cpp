#include "BiTree.h"

int main() 
{
	BiTree<char>T{};
	cout << "\n�ö�������ǰ����������ǣ�" << endl;
	T.PreOrder();
	cout << "\n�ö�������������������ǣ�" << endl;
	T.InOrder();
	cout << "\n�ö������ĺ�����������ǣ�" << endl;
	T.PostOrder();
	cout << "\n�ö������Ĳ�����������ǣ�" << endl;
	T.LevelOrder();

	return 0;
}