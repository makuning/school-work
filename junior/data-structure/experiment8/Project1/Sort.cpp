#include "Sort.h"

// 快速排序递归函数
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		// 以数组最后一个元素作为基准，将小于基准的元素放在左边，大于基准的元素放在右边
		int pivot = arr[high];  // 基准元素
		int i = low - 1;  // 较小元素的索引
		int temp;

		for (int j = low; j < high; j++) {
			if (arr[j] <= pivot) {
				i++;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		pivot = i + 1;

		// 递归对基准左右两侧的子数组进行排序
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

// 快速排序函数，接受一个整数数组和数组长度作为参数
void quickSort(int arr[], int length) {
	quickSort(arr, 0, length - 1);
}

// 希尔排序-升序
void shellAsc(int nums[], int len) {
	// 计算增量序列的初始值
	int gap = len / 2;

	// 不断缩小增量，直到增量为1
	while (gap > 0) {
		// 对每个增量进行插入排序
		for (int i = gap; i < len; i++) {
			int temp = nums[i];
			int j = i;

			// 在当前增量下，将元素插入到已排序序列的正确位置
			while (j >= gap && nums[j - gap] > temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}

			nums[j] = temp;
		}

		// 缩小增量
		gap /= 2;
	}
}

// 希尔排序-降序
void shellDesc(int nums[], int len) {
	// 计算增量序列的初始值
	int gap = len / 2;

	// 不断缩小增量，直到增量为1
	while (gap > 0) {
		// 对每个增量进行插入排序
		for (int i = gap; i < len; i++) {
			int temp = nums[i];
			int j = i;

			// 在当前增量下，将元素插入到已排序序列的正确位置
			while (j >= gap && nums[j - gap] < temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}

			nums[j] = temp;
		}

		// 缩小增量
		gap /= 2;
	}
}

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