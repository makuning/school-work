#pragma once

/**
* 求字符串长度函数
* param str 需要计算的字符串
* return 字符串的长度
*/
int GetLen(const char* str);

/**
* 字符串拼接函数
* param legt 需要拼接的前半部分字符串
* param right 需要拼接的后半部分字符串
* return 返回拼接好的字符串
*/
const char* Splice(const char* left, const char* right);

/**
* 比较大小函数
* param left 需要比较的第一个字符串
* param right 需要比较的第二个字符串
* return 小于0表示左边小于右边，大于0表示左边大于右边，等于0表示两字符串相等
*/
int Compare(const char* left, const char* right);
