#pragma once

/**
* ���ַ������Ⱥ���
* param str ��Ҫ������ַ���
* return �ַ����ĳ���
*/
int GetLen(const char* str);

/**
* �ַ���ƴ�Ӻ���
* param legt ��Ҫƴ�ӵ�ǰ�벿���ַ���
* param right ��Ҫƴ�ӵĺ�벿���ַ���
* return ����ƴ�Ӻõ��ַ���
*/
const char* Splice(const char* left, const char* right);

/**
* �Ƚϴ�С����
* param left ��Ҫ�Ƚϵĵ�һ���ַ���
* param right ��Ҫ�Ƚϵĵڶ����ַ���
* return С��0��ʾ���С���ұߣ�����0��ʾ��ߴ����ұߣ�����0��ʾ���ַ������
*/
int Compare(const char* left, const char* right);
