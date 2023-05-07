#include "MGraph.h"

int main() 
{
	int i;
	char ch[] = { 'A', 'B', 'C', 'D', 'E' };
	MGraph<char> MG{ ch, 5, 6 };	// 建立具有5个顶点，6条边的无向图
	for (i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}

	cout << "深度优先遍历序列是：" << endl;
	MG.DFTraverse(0);

	for (i = 0; i < MaxSize; i++)
	{
		visited[i] = 0;
	}
	cout << "\n广度优先遍历序列是：" << endl;
	MG.BFTraverse(0);

	return 0;
}