#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Sort.h"

using namespace std;

// ��ӡ�ַ���
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
	// ��������ӳ�ʼ��
	srand(time(NULL));

	// ����500��1~2000֮����������
	int nums[500] = { 0 };
	for (int i = 0; i < 500; i++) {
		nums[i] = rand() % 2000 + 1;
	}
	
	int len = sizeof(nums) / sizeof(int);
	

	auto start_time = chrono::high_resolution_clock::now();
	quickSort(nums, len);
	auto end_time = chrono::high_resolution_clock::now();
	auto elapsed_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();

	cout << "��������ʱ�䣺" << elapsed_time << " ����" << endl;
	printArr(nums, len);

	return 0;
}