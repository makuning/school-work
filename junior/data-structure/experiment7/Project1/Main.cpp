#include <iostream>
#include "Order.h"
#include "Find.h"
#include <ctime>

using namespace std;
const int MAX_SIZE = 100000;

// �����ӡ����
void printArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (!(i % 14)) {
			cout << endl;
		}
		else {
			cout << '\t';
		}
		cout << arr[i];
	}
	cout << endl;
}

int main()
{
	int nums[] = { 12, 22, 43, 512, 5, 85, 546, 97, 23, 34, 84 };
	int len = sizeof(nums) / sizeof(int);
	bubbleOrderAsc(nums, len);
	printArr(nums, len);

	return 0;
}

//int main()
//{
//	int arr[MAX_SIZE];
//
//	for (int i = 0; i < MAX_SIZE; i++) {
//		arr[i] = i;
//	}
//
//	bubbleOrderAsc(arr, MAX_SIZE);
//	
//
//	clock_t startTime, endTime;
//	int index, search = MAX_SIZE - 1;
//
//	startTime = clock();
//	printArr(arr, MAX_SIZE);
//	endTime = clock();
//	cout << "��ӡ��" << (endTime - startTime) << "ms" << endl;
//
//	startTime = clock();
//	index = binSearch(arr, MAX_SIZE, search);
//	cout << "�۰����" << search << "���±�Ϊ��" << index << endl;
//	endTime = clock();
//	cout << "�۰���ң�" << (endTime - startTime) << "ms" << endl;
//
//	startTime = clock();
//	index = seqSearch(arr, MAX_SIZE, search);
//	cout << "˳�����" << search << "���±�Ϊ��" << index << endl;
//	endTime = clock();
//	cout << "˳����ң�" << (endTime - startTime) << "ms" << endl;
//	
//	return 0;
//}

