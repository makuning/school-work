#pragma once
// √∞≈›≈≈–Ú-Ωµ–Ú
void bubbleOrderDesc(int arr[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		
		for (j = 0; j < len - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// √∞≈›≈≈–Ú-…˝–Ú
void bubbleOrderAsc(int arr[], int len) {
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {

		for (j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}