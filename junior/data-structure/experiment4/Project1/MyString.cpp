#include <iostream>
#include <stdlib.h>

using namespace std;

/**
* 求字符串长度函数
* param str 需要计算的字符串
* return 字符串的长度
*/
int GetLen(const char* str) {
	int cnt = 0;
	
	while (*(str++) != '\0') {
		cnt++;
	}

	return cnt;
}

/**
* 字符串拼接函数
* param legt 需要拼接的前半部分字符串
* param right 需要拼接的后半部分字符串
* return 返回拼接好的字符串
*/
const char* Splice(const char* left, const char* right) {
	// 分别获取两个字符串的长度
	int left_size = GetLen(left), right_size = GetLen(right);
	int length = left_size + right_size;	// 计算拼接后字符串的长度
	char* str = (char*)malloc((length + 1) * sizeof(char));	// 定义一串连续的空间存放拼接后的数组，并且计算最后的空字符位
	
	int i = 0;
	// 将第一个字符串加入到新开辟的空间中
	for (; i < left_size; i++) {
		str[i] = left[i];
	}
	// 将第二个字符串加入到新开辟的空间中
	for (; i < length; i++) {
		str[i] = right[i - left_size];
	}
	// 设置字符串结束符
	str[i] = '\0';

	return str;
}

/**
* 比较大小函数
* param left 需要比较的第一个字符串
* param right 需要比较的第二个字符串
* return 小于0表示左边小于右边，大于0表示左边大于右边，等于0表示两字符串相等
*/
int Compare(const char* left, const char* right) {
	// 分别获取两个字符串的长度
	int left_len = GetLen(left), right_len = GetLen(right);
	
	// 长度不一样就直接返回相差的长度
	if (left_len != right_len) return left_len - right_len;

	// 长度不一样就返回ASCII码的差值
	// 一直循环到两个字符串的某个字符不相等或者循环到头
	while (*(left++) == *(right++) && *left != '\0') {}
	// 返回ASCII码的差值
	return *(--left) - *(--right);
}