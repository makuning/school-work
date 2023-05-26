#include <iostream>
#include "Order.h"
#include "Find.h"
#include <ctime>

using namespace std;
const int MAX_SIZE = 100000;

// 数组打印函数
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
//	cout << "打印：" << (endTime - startTime) << "ms" << endl;
//
//	startTime = clock();
//	index = binSearch(arr, MAX_SIZE, search);
//	cout << "折半查找" << search << "的下标为：" << index << endl;
//	endTime = clock();
//	cout << "折半查找：" << (endTime - startTime) << "ms" << endl;
//
//	startTime = clock();
//	index = seqSearch(arr, MAX_SIZE, search);
//	cout << "顺序查找" << search << "的下标为：" << index << endl;
//	endTime = clock();
//	cout << "顺序查找：" << (endTime - startTime) << "ms" << endl;
//	
//	return 0;
//}

