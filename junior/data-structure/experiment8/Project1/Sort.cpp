#include "Sort.h"

// ��������ݹ麯��
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		// ���������һ��Ԫ����Ϊ��׼����С�ڻ�׼��Ԫ�ط�����ߣ����ڻ�׼��Ԫ�ط����ұ�
		int pivot = arr[high];  // ��׼Ԫ��
		int i = low - 1;  // ��СԪ�ص�����
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

		// �ݹ�Ի�׼����������������������
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

// ����������������һ��������������鳤����Ϊ����
void quickSort(int arr[], int length) {
	quickSort(arr, 0, length - 1);
}

// ϣ������-����
void shellAsc(int nums[], int len) {
	// �����������еĳ�ʼֵ
	int gap = len / 2;

	// ������С������ֱ������Ϊ1
	while (gap > 0) {
		// ��ÿ���������в�������
		for (int i = gap; i < len; i++) {
			int temp = nums[i];
			int j = i;

			// �ڵ�ǰ�����£���Ԫ�ز��뵽���������е���ȷλ��
			while (j >= gap && nums[j - gap] > temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}

			nums[j] = temp;
		}

		// ��С����
		gap /= 2;
	}
}

// ϣ������-����
void shellDesc(int nums[], int len) {
	// �����������еĳ�ʼֵ
	int gap = len / 2;

	// ������С������ֱ������Ϊ1
	while (gap > 0) {
		// ��ÿ���������в�������
		for (int i = gap; i < len; i++) {
			int temp = nums[i];
			int j = i;

			// �ڵ�ǰ�����£���Ԫ�ز��뵽���������е���ȷλ��
			while (j >= gap && nums[j - gap] < temp) {
				nums[j] = nums[j - gap];
				j -= gap;
			}

			nums[j] = temp;
		}

		// ��С����
		gap /= 2;
	}
}

// ��������-����
void insertDesc(int nums[], int len) {
	int i, j, max, maxIndex;

	// ��δ������������ҵ���������ŵ����������ֵ�ĩβ
	for (i = 0; i < len - 1; i++) {
		// �����ֵ����Ϊδ�������еĵ�һ����
		max = nums[maxIndex = i];
		// ����δ���������
		for (j = i; j < len - 1; j++) {
			if (max < nums[j + 1]) {
				max = nums[maxIndex = j + 1];
			}
		}
		// ��δ�����������ֵ�ŵ�����������ĩβ
		nums[maxIndex] = nums[i];
		nums[i] = max;
	}
}

// ��������-����
void insertAsc(int nums[], int len) {
	int i, j, min, minIndex;

	// ��δ������������ҵ���С�����ŵ����������ֵ�ĩβ
	for (i = 0; i < len - 1; i++) {
		// ����Сֵ����Ϊδ�������еĵ�һ����
		min = nums[minIndex = i];
		// ����δ���������
		for (j = i; j < len - 1; j++) {
			if (min > nums[j + 1]) {
				min = nums[minIndex = j + 1];
			}
		}
		// ��δ����������Сֵ�ŵ�����������ĩβ
		nums[minIndex] = nums[i];
		nums[i] = min;
	}
}

// ð������-����
void bubbleDesc(int nums[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			// ���ǰ�����С�ں���������ͽ���
			if (nums[j] < nums[j + 1]) {
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

// ð������-����
void bubbleAsc(int nums[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			// ���ǰ��������ں���������ͽ���
			if (nums[j] > nums[j + 1]) {
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}