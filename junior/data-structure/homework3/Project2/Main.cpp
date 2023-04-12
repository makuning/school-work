#include "CirQueue.h"
#include <iostream>
#include <string>

using namespace std;

// ���ڴ洢������Ϣ�Ľṹ��
struct Sick {
	string id;	// ���
	string name;// ����
};

/*
	����˵�ѡ������ؽ����������
	choice��ѡ��
	sicks���ŶӵĲ���
	current����ǰ��������Ĳ���
	return�����ش������������Ĳ���
*/ 
Sick* choiceHandle(int choice, CirQueue<Sick*>* sicks, Sick* current);

int main() {
	int userIn = 0;
	CirQueue<Sick*>* sicks = new CirQueue<Sick*>;
	struct Sick* sick = nullptr;
	
	do {
		try {
			cout << "----------��������ѡ���Ӧ����----------" << endl;
			if (sick == nullptr) {
				cout << "----------------���ҿ���----------------" << endl;
			}
			else {
				cout << "---���[" + sick->id + "]|����[" + sick->name + "]��������-----" << endl;
			}
			if (sicks->Size()) {
				cout << "---����[" + sicks->GetHead()->id + "]|����[" + sicks->GetHead()->name + "]����׼��-----" << endl;
			}
			cout << "---------��ǰ����[" << sicks->Size() << "]�������Ŷ�----------" << endl;
			cout << "--------------1��¼�벡��---------------" << endl;
			cout << "--------------2�����в���---------------" << endl;
			cout << "--------------0���˳�ϵͳ---------------" << endl;
			cout << "��ѡ��";
			cin >> userIn;
			sick = choiceHandle(userIn, sicks, sick);
			cout << "----------------------------------------" << endl;
		}
		catch (const char* ex) {
			cout << "����Ĳ���" << endl;
			exit(-1);
		}
	} while (userIn);

	return 0;
}

/*
	����˵�ѡ������ؽ����������
	choice��ѡ��
	sicks���ŶӵĲ���
	current����ǰ��������Ĳ���
	return�����ش������������Ĳ���
*/
Sick* choiceHandle(int choice, CirQueue<Sick*>* sicks, Sick* current) {
	struct Sick* sick;
	switch (choice) {
	case 0:
		cout << "�ټ�" << endl;
		return nullptr;
	case 1:
		cout << "�������ż�����" << endl;
		sick = new Sick;
		cin >> sick->id >> sick->name;
		sicks->EnQueue(sick);
		return current;
	case 2:
		if (sicks->Size()) {
			sick = sicks->DeQueue();
		}
		else {
			cout << "���˵ȴ�" << endl;
			sick = nullptr;
		}
		return sick;
	default:
		cout << "��֧�ֵ�ѡ��" << endl;
		return current;
	}
}