#include "SeqTree.h"
#include <cmath>
#include <iostream>

using namespace std;

// ���캯��
SeqTree::SeqTree() {
    // ������Ĭ��Ϊ����ֵ����ʾ��λ��û������
    for (int i = 0; i < max_length; i++) {
        datas[i] = ignore_num;
    }
}


SeqTree::~SeqTree() {

}
// ˫�׽�����
int SeqTree::ParentsNum() {
    int cnt = 0;        // ������

    // ���һ�㲻�ò飬һ������˫�׽��
    int i = 0;
    for (; i < pow(2, floor(log(max_length) / log(2))) - 1; i++) {
        if (this->datas[i] == ignore_num) continue; // ����ǿյľ�����
        if (this->datas[i * 2 + 1] != ignore_num || this->datas[i * 2 + 2] != ignore_num) cnt++;    // ����к��Ӿ���˫�׽��
    }

    return cnt;
}

// Ҷ������
int SeqTree::LeavesNum() {
    int cnt = 0;        // ������

    // ���һ�㲻�ò飬һ����Ҷ�ӽ��
    int i = 0;
    for (; i < pow(2, floor(log(max_length) / log(2))) - 1; i++) {
        if (this->datas[i] == ignore_num) continue; // ����ǿյľ�����
        if (this->datas[i * 2 + 1] == ignore_num && this->datas[i * 2 + 2] == ignore_num) cnt++;    // ���û�к��Ӿ���Ҷ���
    }

    // �������һ�㣬��������ݾ���Ҷ���
    for (; i < max_length; i++) {
        if (this->datas[i] != ignore_num) cnt++;
    }

    return cnt;
}

// ������
void SeqTree::Insert(int index, int data) {
    this->datas[index] = data;
}

// ɾ�����
int SeqTree::Desert(int index) {
    int result = this->datas[index];
    this->datas[index] = ignore_num;
    return result;
}