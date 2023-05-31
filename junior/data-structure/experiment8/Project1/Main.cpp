#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Sort.h"

using namespace std;

// 打印字符串
void printArr(int nums[], int len) {
	int i = 0;
	for (; i < len; i++) {
		cout << nums[i] << '\t';
		if (i % 11 == 10) cout << endl;
	}
	cout << endl;
}

int main()
{
	// 随机数种子初始化
	srand(time(NULL));

	// 生成500个1~2000之间的随机整数
	int nums[500] = { 0 };
	for (int i = 0; i < 500; i++) {
		nums[i] = rand() % 2000 + 1;
	}
	
	int len = sizeof(nums) / sizeof(int);
	

	auto start_time = chrono::high_resolution_clock::now();
	quickSort(nums, len);
	auto end_time = chrono::high_resolution_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

	cout << "排序所用时间：" << elapsed_time << " 纳秒" << endl;
	printArr(nums, len);

	return 0;
}