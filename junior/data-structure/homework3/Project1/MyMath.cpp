#include "MyMath.h"

// �ж���������ȼ�
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
		throw "��֧�ֵ������";
	}
}

// ���ݶ�Ԫ���������
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
		throw "��֧�ֵ������";
	}
}