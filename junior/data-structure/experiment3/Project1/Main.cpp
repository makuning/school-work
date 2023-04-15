#include "CirQueue.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
	default_random_engine engine;	// �������������
	engine.seed(time(0));			// ����ǰʱ���ʱ�������Ϊ���������

	try {
		CirQueue<> queue;				// ����ѭ������

		// ����10��0~100����������
		for (int i = 0; i < 10; i++) {
			queue.EnQueue(engine() % 101);	// ��������
		}

		if (queue.Empty()) {
			cout << "�ӿ�";
		}
		else {
			cout << "��ͷԪ��Ϊ��" << queue.GetHead();
		}
	}
	catch (const char * msg) {
		cout << "�����ˣ�" << msg << endl;
	}

	return 0;
}