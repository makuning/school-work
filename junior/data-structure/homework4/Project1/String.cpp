#include "String.h"

// 获取子串t在主串s的位置
int String::StrSub(String s, String t) {
	return 0;
}

// 无参构造
String::String() {
	this->value = nullptr;
	this->length = 0;
}

// 有参构造函数
String::String(const char* str) {
	this->length = 0;
	this->value = str;

	while (*str != '\0') {
		this->length++;
		str++;
	}
}

// 析构函数
String::~String() {

}

// 获取值
const char* String::Value() {
	return this->value;
}

// 获取字符串长度
int String::Length() {
	return this->length;
}
