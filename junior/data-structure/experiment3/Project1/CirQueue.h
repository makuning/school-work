#pragma once

const int QueueSize = 50;		// ����ѭ�����еĳ���

template <typename DataType = int>
class CirQueue {
public:
	CirQueue();					// ���캯��
	~CirQueue();				// ��������
	void EnQueue(DataType x);	// ��Ӳ�������Ԫ��x���
	DataType DeQueue();			// ���Ӳ���
	DataType GetHead();			// ȡ��ͷԪ��
	int Empty();				// �п�
	int Size();					// ����
private:
	DataType data[QueueSize];	// ����
	int start, end, length;		// ��ͷ�Ͷ�β�Լ�����
};

// ����
template <typename DataType>
int CirQueue<DataType>::Size() {
	return length;
}

// ���캯��
template <typename DataType>
CirQueue<DataType>::CirQueue() {
	// ��ͷβ��ָ�����һ��λ��
	this->start = QueueSize - 1;
	this->end = QueueSize - 1;
	this->length = 0;	// ����Ϊ0
}

// ��������
template <typename DataType>
CirQueue<DataType>::~CirQueue() {

}

// ���
template <typename DataType>
void CirQueue<DataType>::EnQueue(DataType x) {
	if ((this->end + 1) % QueueSize == this->start) throw "��";
	this->data[this->end = ((this->end + 1) % QueueSize)] = x;
	this->length++;
}

// ����
template <typename DataType>
DataType CirQueue<DataType>::DeQueue() {
	if (this->start == this->end) throw "�ն�";
	this->length--;
	return this->data[this->start = (this->start + 1) % QueueSize];
}

// ȡ��ͷ
template <typename DataType>
DataType CirQueue<DataType>::GetHead() {
	if (this->start == this->end) throw "�ն�";
	return this->data[(this->start + 1) % QueueSize];
}

// �п�
template <typename DataType>
int CirQueue<DataType>::Empty() {
	return length ? 0 : 1;
}