#include <stdlib.h>
#include <iostream>

using namespace std;

// 用于装载数组
struct Arr {
	int* data;	// 数组指针
	int length;	// 数组长度
};
/*
	获取子串的next数组
	param t 子串的首地址
	return 返回next数组
*/
Arr* getNext(char* t);

/*
	通过KMP算法获取子串在主串中第一次出现的下标（从0起标），未找到返回-1
	param s 主串
	param t 子串
	return 子串在主串中第一次出现的下标（从0起标），未找到返回-1
*/
int KMP(char* s, char* t);

int main() {
	// 创建字符串接收变量
	char* s = (char*) malloc(1024);
	char* t = (char*)malloc(1024);

	// 终端输入
	cout << "请输入主串：";
	cin >> s;
	cout << "请输入子串：";
	cin >> t;

	// 输出结果
	int index = KMP(s, t);
	if (index == -1) {
		cout << "没有在主串中找到子串";
	}
	else {
		cout << "子串在主串中第一次出现的下标为：" << index;
	}
	
	// 释放内存
	free(s);
	free(t);

	return 0;
}

/*
	获取子串的next数组
	param t 子串的首地址
	return 返回next数组
*/
Arr* getNext(char* t) {
	Arr* next = new Arr{ nullptr,0 };

	// 计算数组长度
	while (t[next->length] != '\0') {
		next->length++;
	}

	// 给next数组分配空间
	next->data = (int*)malloc(sizeof(int) * (next->length));

	next->data[0] = 0;
	next->data[1] = 0;

	// 循环对应子串的每个字符下标
	for (int i = 2; i < next->length; i++) {
		int max = i - 1;	// 当前子串字符下标需要比对的前后缀的最长长度
		next->data[i] = 0;	// 假想没有前后缀
		// 根据前后缀最大长度，从最大前后缀一直比较到最小前后缀，找到下次对比子串的起始指针
		for (int j = max; j >= 1; j--) {
			int flag = true;
			// 比较前后缀
			for (int k = 0; k < j; k++) {
				// 依次比较前后缀，如果没配对就表示本次循环的前后缀长度不是最长的
				if (t[k] != t[max - j + k + 1]) {
					flag = false;
					break;
				}
			}
			// 如果flag为真，则写入偏移量，并结束找最大前后缀
			if (flag) {
				// 将最大前后缀长度赋值给next数组并退出
				next->data[i] = j;
				break;
			}
		}
	}

	return next;
}

/*
	通过KMP算法获取子串在主串中第一次出现的下标（从0起标），未找到返回-1
	param s 主串
	param t 子串
	return 子串在主串中第一次出现的下标（从0起标），未找到返回-1
*/
int KMP(char* s, char* t) {
	// 获取子串的next数组
	Arr* next = getNext(t);
	// 分别为主串的比较下标记录与子串的比较下标记录
	int start = 0, t_i = 0;

	// 当主串比较到完，或者子串比较完就终止循环
	// 子串比较完说明找到了子串的下标，主串比较完说明没有找到
	while (s[start] != '\0' && t[t_i] != '\0') {
		if (s[start] == t[t_i]) {
			t_i++;
		}
		else {
			t_i = next->data[t_i + 1];
		}
		start++;
	}

	// 子串比较完说明找到了子串的下标
	if (t[t_i] == '\0') {
		// 返回子串第一次出现的下标
		// 由于主串下标在比较时会往后走，所以返回时要减去子串的长度
		return start - next->length;
	}

	// 子串没有比较完说明没有在主串中找到子串，返回-1
	return -1;
}
