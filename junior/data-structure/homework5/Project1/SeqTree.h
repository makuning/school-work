#pragma once

const int max_length = 100;             // ��󳤶�
const int ignore_num = 0x7FFFFFFF;      // ��������

// ˳��
class SeqTree {
public:
    SeqTree();                          // ���캯��
    ~SeqTree();                         // ��������
    void Insert(int index, int data);   // ������
    int Desert(int index);              // ɾ�����
    int ParentsNum();                   // ˫�׽�����
    int LeavesNum();                    // Ҷ������
private:
    int datas[max_length];              // ����
};
