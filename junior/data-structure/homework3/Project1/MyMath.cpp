#include "MyMath.h"

// 判断运算符优先级
int Precedence(char op) {
	switch (op) {
	case '(':
		return 0;
	case '#':
		return 1;
	case '=':
		return 1;
	case '+':
		return 2;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 3;
	case ')':
		return 4;
	default:
		throw "不支持的运算符";
	}
}

// 根据二元运算符运算
float Operate(float left, float right, char op) {
	switch (op) {
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	default:
		throw "不支持的运算符";
	}
}