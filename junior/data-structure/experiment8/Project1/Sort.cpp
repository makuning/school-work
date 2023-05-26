#include "Sort.h"

// 插入排序-降序
void insertDesc(int nums[], int len) {
	int i, j, max, maxIndex;

	// 从未排序的数字中找到最大数，放到已排序数字的末尾
	for (i = 0; i < len - 1; i++) {
		// 将最大值假设为未排序数中的第一个数
		max = nums[maxIndex = i];
		// 遍历未排序的数字
		for (j = i; j < len - 1; j++) {
			if (max < nums[j + 1]) {
				max = nums[maxIndex = j + 1];
			}
		}
		// 将未排序数的最大值放到排序数的最末尾
		nums[maxIndex] = nums[i];
		nums[i] = max;
	}
}

// 插入排序-升序
void insertAsc(int nums[], int len) {
	int i, j, min, minIndex;

	// 从未排序的数字中找到最小数，放到已排序数字的末尾
	for (i = 0; i < len - 1; i++) {
		// 将最小值假设为未排序数中的第一个数
		min = nums[minIndex = i];
		// 遍历未排序的数字
		for (j = i; j < len - 1; j++) {
			if (min > nums[j + 1]) {
				min = nums[minIndex = j + 1];
			}
		}
		// 将未排序数的最小值放到排序数的最末尾
		nums[minIndex] = nums[i];
		nums[i] = min;
	}
}

// 冒泡排序-降序
void bubbleDesc(int nums[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			// 如果前面的数小于后面的数，就交换
			if (nums[j] < nums[j + 1]) {
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

// 冒泡排序-升序
void bubbleAsc(int nums[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			// 如果前面的数大于后面的数，就交换
			if (nums[j] > nums[j + 1]) {
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}