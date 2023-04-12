#include "CirQueue.h"
#include <iostream>
#include <string>

using namespace std;

// 用于存储病人信息的结构体
struct Sick {
	string id;	// 编号
	string name;// 姓名
};

/*
	处理菜单选项，并返回进入门诊的人
	choice：选项
	sicks：排队的病人
	current：当前正在门诊的病人
	return：返回处理后正在门诊的病人
*/ 
Sick* choiceHandle(int choice, CirQueue<Sick*>* sicks, Sick* current);

int main() {
	int userIn = 0;
	CirQueue<Sick*>* sicks = new CirQueue<Sick*>;
	struct Sick* sick = nullptr;
	
	do {
		try {
			cout << "----------输入数字选择对应功能----------" << endl;
			if (sick == nullptr) {
				cout << "----------------诊室空闲----------------" << endl;
			}
			else {
				cout << "---编号[" + sick->id + "]|姓名[" + sick->name + "]正在门诊-----" << endl;
			}
			if (sicks->Size()) {
				cout << "---请编号[" + sicks->GetHead()->id + "]|姓名[" + sicks->GetHead()->name + "]做好准备-----" << endl;
			}
			cout << "---------当前还有[" << sicks->Size() << "]人正在排队----------" << endl;
			cout << "--------------1、录入病人---------------" << endl;
			cout << "--------------2、呼叫病人---------------" << endl;
			cout << "--------------0、退出系统---------------" << endl;
			cout << "请选择：";
			cin >> userIn;
			sick = choiceHandle(userIn, sicks, sick);
			cout << "----------------------------------------" << endl;
		}
		catch (const char* ex) {
			cout << "错误的操作" << endl;
			exit(-1);
		}
	} while (userIn);

	return 0;
}

/*
	处理菜单选项，并返回进入门诊的人
	choice：选项
	sicks：排队的病人
	current：当前正在门诊的病人
	return：返回处理后正在门诊的病人
*/
Sick* choiceHandle(int choice, CirQueue<Sick*>* sicks, Sick* current) {
	struct Sick* sick;
	switch (choice) {
	case 0:
		cout << "再见" << endl;
		return nullptr;
	case 1:
		cout << "请输入编号及姓名" << endl;
		sick = new Sick;
		cin >> sick->id >> sick->name;
		sicks->EnQueue(sick);
		return current;
	case 2:
		if (sicks->Size()) {
			sick = sicks->DeQueue();
		}
		else {
			cout << "无人等待" << endl;
			sick = nullptr;
		}
		return sick;
	default:
		cout << "不支持的选项" << endl;
		return current;
	}
}