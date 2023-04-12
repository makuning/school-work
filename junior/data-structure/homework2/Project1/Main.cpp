#include <iostream>
#include "SeqList.h"

using namespace std;

// �˵�
template <typename DataType = int>
void Menu(int choose, SeqList<>* list);
// �������̨��δʹ�ã�
void Clear();

int main() {
	SeqList<> list;
	int choose = -1;

	while (choose) {
		cout << "--------------------------------" << endl;
		cout << "Ԫ��[" << list.Length() << "]��|�������[" << MaxSize << "]��|˳���״̬";
		list.PrintList();
		cout << "1������һ������" << endl;
		cout << "2��ָ��λ�ò���һ������" << endl;
		cout << "3����ȡĳ�����ľ���λ��" << endl;
		cout << "4����ȡһ������λ�õ���" << endl;
		cout << "5��ɾ��һ��ָ��λ�õ���" << endl;
		cout << "0���˳���ʾ" << endl;
		cout << "�������Ӧ�����ţ�";
		cin >> choose;
		try {
			Menu(choose, &list);
		}
		catch (const char * e) {
			cout << "��������������Ϣ��" << e << endl;
		}
		cout << endl << "--------------------------------" << endl;
	}
}

// �˵�
template <typename DataType = int>
void Menu(int choose, SeqList<>* list) {
	int in_1 = 0, in_2 = 0, temp_1 = 0;
	switch (choose) {
		// ����һ������
	case 1:
		cout << "������Ҫ��������֣�";
		cin >> in_1;
		list->Insert(list->Length() + 1, in_1);
		break;
		// ָ��λ�ò���һ������
	case 2:
		cout << "������ָ��λ����Ҫ��������֣�";
		cin >> in_1 >> in_2;
		list->Insert(in_1, in_2);
		break;
		// ��ȡĳ�����ľ���λ��
	case 3:
		cout << "������Ҫ��ѯ������";
		cin >> in_1;
		temp_1 = list->Locate(in_1);
		if (temp_1) {
			cout << "��������һ�γ��ֵ�λ���ǣ�" << temp_1 << endl;
		}
		else {
			cout << "û�в鵽Ŷ~" << endl;
		}
		break;
		// ��ȡһ������λ�õ���
	case 4:
		cout << "������Ҫ���ҵ�λ�ã�";
		cin >> in_1;
		temp_1 = list->Get(in_1);
		cout << "����λ�õ����ǣ�" << temp_1 << endl;
		break;
		// ɾ��һ��ָ��λ�õ���
	case 5:
		cout << "������Ҫɾ����λ�ã�";
		cin >> in_1;
		list->Delete(in_1);
		break;
	case 0:
		cout << "��л���飬�ټ�~" << endl;
		break;
	default:
		cout << "��������" << endl;
	}
}

// �����Ļ��δʹ�ã�
void Clear()
{
	cout << "\x1B[2J\x1B[H";
}
