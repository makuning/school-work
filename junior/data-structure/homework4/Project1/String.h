#pragma once

struct Node {
	char data;
	Node* next;
};

class String {
public:
	String();											// 构造函数
	String(const char* str);							// 有参构造
	~String();											// 析构函数
	int Length();										// 获取字符串长度
	const char* Value();								// 获取值
	static int StrSub(String s, String t);				// 获取子串的位置
private:
	const char* value;
	int length;
};