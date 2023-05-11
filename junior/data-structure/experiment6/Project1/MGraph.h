#pragma once
#include <iostream>

using namespace std;

const int MaxSize = 10;				// 图中最多顶点数

int visited[MaxSize] = { 0 };		// 全局数组变量visited初始化

template <typename DataType>
class MGraph
{
public:
	MGraph(DataType a[], int n, int e);	// 构造函数
	void DFTraverse(int v);				// 深度优先遍历图
	void BFTraverse(int v);				// 广度优先遍历图
private:
	DataType vertex[MaxSize];			// 存放图中顶点的数组
	int edge[MaxSize][MaxSize];			// 存放图中边的数组
	int vertexNum, edgeNum;				// 图的顶点数和边数
};

// 无向图邻接矩阵的构造函数
template <typename DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n; edgeNum = e;
	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];	// 存储顶点
	}

	for (i = 0; i < vertexNum; i++)	// 初始化邻接矩阵
	{
		for (j = 0; j < vertexNum; j++)
		{
			edge[i][j] = 0;
		}
	}

	for (k = 0; k < edgeNum; k++)	// 依次输入每一条边
	{
		cin >> i >> j;				// 输入边依附的两个顶点的编号
		edge[i][j] = 1;
		edge[j][i] = 1;				// 置有边标志
	}
}

// 深度优先遍历
template<typename DataType>
void MGraph<DataType>::DFTraverse(int v)
{
	cout << vertex[v] << '\t';
	visited[v] = 1;
	for (int i = 0; i < vertexNum; i++)
	{
		if (edge[v][i] == 1 && visited[i] == 0) DFTraverse(i);
	}
}

// 广度优先遍历
template <typename DataType>
void MGraph<DataType>::BFTraverse(int v)
{
	int Q[MaxSize], front = -1, rear = -1;			// 采用顺序队列并初始化队列
	int w, j;						// 临时变量 
	cout << vertex[v] << '\t';
	visited[v] = 1;
	Q[++rear] = v;					// 被访问顶点入队
	while (front != rear)			// 当队列非空时
	{
		w = Q[++front];				// 将队头元素出队并送到v中
		for (j = 0; j < vertexNum; j++)
		{
			if (edge[w][j] == 1 && visited[j] == 0)
			{
				cout << vertex[j] << '\t';
				visited[j] = 1;
				Q[++rear] = j;
			}
		}
	}
}