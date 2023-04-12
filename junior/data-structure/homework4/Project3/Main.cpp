#include <stdlib.h>
#include <iostream>

using namespace std;

// ����װ������
struct Arr {
	int* data;	// ����ָ��
	int length;	// ���鳤��
};
/*
	��ȡ�Ӵ���next����
	param t �Ӵ����׵�ַ
	return ����next����
*/
Arr* getNext(char* t);

/*
	ͨ��KMP�㷨��ȡ�Ӵ��������е�һ�γ��ֵ��±꣨��0��꣩��δ�ҵ�����-1
	param s ����
	param t �Ӵ�
	return �Ӵ��������е�һ�γ��ֵ��±꣨��0��꣩��δ�ҵ�����-1
*/
int KMP(char* s, char* t);

int main() {
	// �����ַ������ձ���
	char* s = (char*) malloc(1024);
	char* t = (char*)malloc(1024);

	// �ն�����
	cout << "������������";
	cin >> s;
	cout << "�������Ӵ���";
	cin >> t;

	// ������
	int index = KMP(s, t);
	if (index == -1) {
		cout << "û�����������ҵ��Ӵ�";
	}
	else {
		cout << "�Ӵ��������е�һ�γ��ֵ��±�Ϊ��" << index;
	}
	
	// �ͷ��ڴ�
	free(s);
	free(t);

	return 0;
}

/*
	��ȡ�Ӵ���next����
	param t �Ӵ����׵�ַ
	return ����next����
*/
Arr* getNext(char* t) {
	Arr* next = new Arr{ nullptr,0 };

	// �������鳤��
	while (t[next->length] != '\0') {
		next->length++;
	}

	// ��next�������ռ�
	next->data = (int*)malloc(sizeof(int) * (next->length));

	next->data[0] = 0;
	next->data[1] = 0;

	// ѭ����Ӧ�Ӵ���ÿ���ַ��±�
	for (int i = 2; i < next->length; i++) {
		int max = i - 1;	// ��ǰ�Ӵ��ַ��±���Ҫ�ȶԵ�ǰ��׺�������
		next->data[i] = 0;	// ����û��ǰ��׺
		// ����ǰ��׺��󳤶ȣ������ǰ��׺һֱ�Ƚϵ���Сǰ��׺���ҵ��´ζԱ��Ӵ�����ʼָ��
		for (int j = max; j >= 1; j--) {
			int flag = true;
			// �Ƚ�ǰ��׺
			for (int k = 0; k < j; k++) {
				// ���αȽ�ǰ��׺�����û��Ծͱ�ʾ����ѭ����ǰ��׺���Ȳ������
				if (t[k] != t[max - j + k + 1]) {
					flag = false;
					break;
				}
			}
			// ���flagΪ�棬��д��ƫ�����������������ǰ��׺
			if (flag) {
				// �����ǰ��׺���ȸ�ֵ��next���鲢�˳�
				next->data[i] = j;
				break;
			}
		}
	}

	return next;
}

/*
	ͨ��KMP�㷨��ȡ�Ӵ��������е�һ�γ��ֵ��±꣨��0��꣩��δ�ҵ�����-1
	param s ����
	param t �Ӵ�
	return �Ӵ��������е�һ�γ��ֵ��±꣨��0��꣩��δ�ҵ�����-1
*/
int KMP(char* s, char* t) {
	// ��ȡ�Ӵ���next����
	Arr* next = getNext(t);
	// �ֱ�Ϊ�����ıȽ��±��¼���Ӵ��ıȽ��±��¼
	int start = 0, t_i = 0;

	// �������Ƚϵ��꣬�����Ӵ��Ƚ������ֹѭ��
	// �Ӵ��Ƚ���˵���ҵ����Ӵ����±꣬�����Ƚ���˵��û���ҵ�
	while (s[start] != '\0' && t[t_i] != '\0') {
		if (s[start] == t[t_i]) {
			t_i++;
		}
		else {
			t_i = next->data[t_i + 1];
		}
		start++;
	}

	// �Ӵ��Ƚ���˵���ҵ����Ӵ����±�
	if (t[t_i] == '\0') {
		// �����Ӵ���һ�γ��ֵ��±�
		// ���������±��ڱȽ�ʱ�������ߣ����Է���ʱҪ��ȥ�Ӵ��ĳ���
		return start - next->length;
	}

	// �Ӵ�û�бȽ���˵��û�����������ҵ��Ӵ�������-1
	return -1;
}
