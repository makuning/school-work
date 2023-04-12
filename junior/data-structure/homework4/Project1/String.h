#pragma once

struct Node {
	char data;
	Node* next;
};

class String {
public:
	String();											// ���캯��
	String(const char* str);							// �вι���
	~String();											// ��������
	int Length();										// ��ȡ�ַ�������
	const char* Value();								// ��ȡֵ
	static int StrSub(String s, String t);				// ��ȡ�Ӵ���λ��
private:
	const char* value;
	int length;
};