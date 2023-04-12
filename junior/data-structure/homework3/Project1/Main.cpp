#include "SeqStack.h"
#include "MyMath.h"
#include <string>

using namespace std;

int main() {
	string allOps = "#+-*/=()", userIn = "";	// ��������֧�ֵ���������û�����
	SeqStack<float> nums;						// ���ڴ洢������
	SeqStack<char> ops;						// ���ڴ洢�����
	char op = '\0';
	float num = 0, left = 0, right = 0;		// ���ڴ洢��������������
	ops.Push('#');							// ����������ѹ��ջ�У��������ȼ��Ƚ�
	
	cout << "��������ı��ʽ\nÿ������[������]or[�����]" << endl;
	do {
		if (userIn != "=") {
			cout << "������룺";
			cin >> userIn;
		}

		// �ж�������
		if (userIn == "(") {
			ops.Push('(');
			continue;
		}

		// �ж��Ƿ�Ϊ�����
		if (allOps.find(userIn) == string::npos) {
			// �����������Ϊ���֣�תΪ���ֲ�ѹ������ջ
			num = stof(userIn);	// תΪ����
			nums.Push(num);		// ������ѹ������ջ��
			continue;
		}

		// �ж�������
		if (userIn == ")") {
			while ((op = ops.Pop()) != '(') {
				right = nums.Pop();
				left = nums.Pop();
				nums.Push(Operate(left, right, op));
			}
			continue;
		}

		// �ж���������ȼ�
		if (Precedence(ops.GetTop()) >= Precedence(userIn[0])) {
			// �������������ȼ���ջ�е����ȵ�ջ��������
			right = nums.Pop();
			left = nums.Pop();
			nums.Push(Operate(left, right, ops.Pop()));	// ��������ѹ������ջ��
			// ���û�����������ѹ�������ջ��
			if (userIn != "=") {
				ops.Push(userIn[0]);
			}						
			continue;
		}

		// �������������ȼ���ջ�и���ֱ��ѹ�������ջ
		if (userIn != "=") {
			ops.Push(userIn[0]);
		}
	} while (userIn != "=" || ops.GetTop() != '#');

	cout << "��������" << nums.GetTop();

	return 0;
}