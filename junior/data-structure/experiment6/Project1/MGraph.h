#pragma once
#include <iostream>

using namespace std;

const int MaxSize = 10;				// ͼ����ඥ����

int visited[MaxSize] = { 0 };		// ȫ���������visited��ʼ��

template <typename DataType>
class MGraph
{
public:
	MGraph(DataType a[], int n, int e);	// ���캯��
	void DFTraverse(int v);				// ������ȱ���ͼ
	void BFTraverse(int v);				// ������ȱ���ͼ
private:
	DataType vertex[MaxSize];			// ���ͼ�ж��������
	int edge[MaxSize][MaxSize];			// ���ͼ�бߵ�����
	int vertexNum, edgeNum;				// ͼ�Ķ������ͱ���
};

// ����ͼ�ڽӾ���Ĺ��캯��
template <typename DataType>
MGraph<DataType>::MGraph(DataType a[], int n, int e)
{
	int i, j, k;
	vertexNum = n; edgeNum = e;
	for (i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];	// �洢����
	}

	for (i = 0; i < vertexNum; i++)	// ��ʼ���ڽӾ���
	{
		for (j = 0; j < vertexNum; j++)
		{
			edge[i][j] = 0;
		}
	}

	for (k = 0; k < edgeNum; k++)	// ��������ÿһ����
	{
		cin >> i >> j;				// �������������������ı��
		edge[i][j] = 1;
		edge[j][i] = 1;				// ���б߱�־
	}
}

// ������ȱ���
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

// ������ȱ���
template <typename DataType>
void MGraph<DataType>::BFTraverse(int v)
{
	int Q[MaxSize], front = -1, rear = -1;			// ����˳����в���ʼ������
	int w, j;						// ��ʱ���� 
	cout << vertex[v] << '\t';
	visited[v] = 1;
	Q[++rear] = v;					// �����ʶ������
	while (front != rear)			// �����зǿ�ʱ
	{
		w = Q[++front];				// ����ͷԪ�س��Ӳ��͵�v��
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