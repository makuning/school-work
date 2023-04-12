#include "SeqStack.h"
#include "MyMath.h"
#include <string>

using namespace std;

int main() {
	string allOps = "#+-*/=()", userIn = "";	// 定义所有支持的运算符与用户输入
	SeqStack<float> nums;						// 用于存储运算数
	SeqStack<char> ops;						// 用于存储运算符
	char op = '\0';
	float num = 0, left = 0, right = 0;		// 用于存储程序会产生的数字
	ops.Push('#');							// 将结束符号压入栈中，方便优先级比较
	
	cout << "请输入你的表达式\n每次输入[运算数]or[运算符]" << endl;
	do {
		if (userIn != "=") {
			cout << "你的输入：";
			cin >> userIn;
		}

		// 判断左括号
		if (userIn == "(") {
			ops.Push('(');
			continue;
		}

		// 判断是否为运算符
		if (allOps.find(userIn) == string::npos) {
			// 不是运算符则为数字，转为数字并压入数字栈
			num = stof(userIn);	// 转为数字
			nums.Push(num);		// 将数字压入数字栈中
			continue;
		}

		// 判断右括号
		if (userIn == ")") {
			while ((op = ops.Pop()) != '(') {
				right = nums.Pop();
				left = nums.Pop();
				nums.Push(Operate(left, right, op));
			}
			continue;
		}

		// 判断运算符优先级
		if (Precedence(ops.GetTop()) >= Precedence(userIn[0])) {
			// 如果新运算的优先级比栈中低则先弹栈进行运算
			right = nums.Pop();
			left = nums.Pop();
			nums.Push(Operate(left, right, ops.Pop()));	// 将运算结果压入数字栈中
			// 将用户输入的运算符压入运算符栈中
			if (userIn != "=") {
				ops.Push(userIn[0]);
			}						
			continue;
		}

		// 如果新运算的优先级比栈中高则直接压入运算符栈
		if (userIn != "=") {
			ops.Push(userIn[0]);
		}
	} while (userIn != "=" || ops.GetTop() != '#');

	cout << "计算结果：" << nums.GetTop();

	return 0;
}