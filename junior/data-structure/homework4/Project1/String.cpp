#include "String.h"

// ��ȡ�Ӵ�t������s��λ��
int String::StrSub(String s, String t) {
	return 0;
}

// �޲ι���
String::String() {
	this->value = nullptr;
	this->length = 0;
}

// �вι��캯��
String::String(const char* str) {
	this->length = 0;
	this->value = str;

	while (*str != '\0') {
		this->length++;
		str++;
	}
}

// ��������
String::~String() {

}

// ��ȡֵ
const char* String::Value() {
	return this->value;
}

// ��ȡ�ַ�������
int String::Length() {
	return this->length;
}
