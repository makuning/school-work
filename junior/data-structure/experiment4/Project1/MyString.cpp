#include <iostream>
#include <stdlib.h>

using namespace std;

/**
* ���ַ������Ⱥ���
* param str ��Ҫ������ַ���
* return �ַ����ĳ���
*/
int GetLen(const char* str) {
	int cnt = 0;
	
	while (*(str++) != '\0') {
		cnt++;
	}

	return cnt;
}

/**
* �ַ���ƴ�Ӻ���
* param legt ��Ҫƴ�ӵ�ǰ�벿���ַ���
* param right ��Ҫƴ�ӵĺ�벿���ַ���
* return ����ƴ�Ӻõ��ַ���
*/
const char* Splice(const char* left, const char* right) {
	// �ֱ��ȡ�����ַ����ĳ���
	int left_size = GetLen(left), right_size = GetLen(right);
	int length = left_size + right_size;	// ����ƴ�Ӻ��ַ����ĳ���
	char* str = (char*)malloc((length + 1) * sizeof(char));	// ����һ�������Ŀռ���ƴ�Ӻ�����飬���Ҽ������Ŀ��ַ�λ
	
	int i = 0;
	// ����һ���ַ������뵽�¿��ٵĿռ���
	for (; i < left_size; i++) {
		str[i] = left[i];
	}
	// ���ڶ����ַ������뵽�¿��ٵĿռ���
	for (; i < length; i++) {
		str[i] = right[i - left_size];
	}
	// �����ַ���������
	str[i] = '\0';

	return str;
}

/**
* �Ƚϴ�С����
* param left ��Ҫ�Ƚϵĵ�һ���ַ���
* param right ��Ҫ�Ƚϵĵڶ����ַ���
* return С��0��ʾ���С���ұߣ�����0��ʾ��ߴ����ұߣ�����0��ʾ���ַ������
*/
int Compare(const char* left, const char* right) {
	// �ֱ��ȡ�����ַ����ĳ���
	int left_len = GetLen(left), right_len = GetLen(right);
	
	// ���Ȳ�һ����ֱ�ӷ������ĳ���
	if (left_len != right_len) return left_len - right_len;

	// ���Ȳ�һ���ͷ���ASCII��Ĳ�ֵ
	// һֱѭ���������ַ�����ĳ���ַ�����Ȼ���ѭ����ͷ
	while (*(left++) == *(right++) && *left != '\0') {}
	// ����ASCII��Ĳ�ֵ
	return *(--left) - *(--right);
}