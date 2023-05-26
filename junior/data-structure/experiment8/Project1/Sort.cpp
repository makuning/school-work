#include "Sort.h"

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