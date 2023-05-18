#include "Find.h"

// Ë³Ğò²éÕÒ
int seqSearch(int arr[], int len, int search) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == search) {
			return i;
		}
	}
	return -1;
}

// ÕÛ°ë²éÕÒ
int binSearch(int arr[], int len, int search) {
	int low = 0, high = len, mid;
	

	while (low <= high) {
		mid = (low + high) / 2;

		if (arr[mid] < search) {
			low = mid;
		}
		else if (arr[mid] > search) {
			high = mid;
		}
		else {
			return mid;
		}
	}

	return -1;
}