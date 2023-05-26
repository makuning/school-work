#include <iostream>
#include <chrono>
#include "Sort.h"

using namespace std;

// ��ӡ�ַ���
void printArr(int nums[], int len) {
	int i = 0;
	for (; i < len; i++) {
		cout << nums[i] << '\t';
	}
	cout << endl;
}

int main()
{
	int nums[] = {12, 22, 43, 512, 5, 85, 546, 97, 23, 34, 84};
	int len = sizeof(nums) / sizeof(int);
	

	auto start_time = chrono::high_resolution_clock::now();
	insertAsc(nums, len);
	auto end_time = chrono::high_resolution_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

	cout << "��������ʱ�䣺" << elapsed_time << " ����" << endl;
	printArr(nums, len);

	return 0;
}