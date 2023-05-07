#include "MGraph.h"

int main() 
{
	int i;
	char ch[] = { 'A', 'B', 'C', 'D', 'E' };
	MGraph<char> MG{ ch, 5, 6 };	// ��������5�����㣬6���ߵ�����ͼ
	for (i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}

	cout << "������ȱ��������ǣ�" << endl;
	MG.DFTraverse(0);

	for (i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}
	cout << "\n������ȱ��������ǣ�" << endl;
	MG.BFTraverse(0);

	return 0;
}