#include "SeqTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	SeqTree tree;
	
	int cnt = 0;
	string user_in;
	cout << "#��ʾ��λ��Ϊ�գ�$��������" << endl;
	while (1) {
		cout << "�������" << cnt << "���������ݣ�";
		cin >> user_in;
		// �ж�����
		if (!user_in.compare("$")) {
			cout << "----------------��������-------------------" << endl;
			cout << "˫�׽�����Ϊ��" << tree.ParentsNum() << "��" << endl;
			cout << "Ҷ�ӽ�����Ϊ��" << tree.LeavesNum() << "��" << endl;
			break;
		}
		else if (!user_in.compare("#")) {
			// ʲô������
		}
		else {
			tree.Insert(cnt, stoi(user_in));
		}
		
		cnt++;	// �������Լ�
	}

	return 0;
}
