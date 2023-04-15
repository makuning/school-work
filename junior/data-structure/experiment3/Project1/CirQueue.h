#pragma once

const int QueueSize = 50;		// 设置循环队列的长度

template <typename DataType = int>
class CirQueue {
public:
	CirQueue();					// 构造函数
	~CirQueue();				// 析构函数
	void EnQueue(DataType x);	// 入队操作，将元素x入队
	DataType DeQueue();			// 出队操作
	DataType GetHead();			// 取队头元素
	int Empty();				// 判空
	int Size();					// 长度
private:
	DataType data[QueueSize];	// 数据
	int start, end, length;		// 队头和队尾以及长度
};

// 长度
template <typename DataType>
int CirQueue<DataType>::Size() {
	return length;
}

// 构造函数
template <typename DataType>
CirQueue<DataType>::CirQueue() {
	// 将头尾都指向最后一个位置
	this->start = QueueSize - 1;
	this->end = QueueSize - 1;
	this->length = 0;	// 长度为0
}

// 析构函数
template <typename DataType>
CirQueue<DataType>::~CirQueue() {

}

// 入队
template <typename DataType>
void CirQueue<DataType>::EnQueue(DataType x) {
	if ((this->end + 1) % QueueSize == this->start) throw "满";
	this->data[this->end = ((this->end + 1) % QueueSize)] = x;
	this->length++;
}

// 出队
template <typename DataType>
DataType CirQueue<DataType>::DeQueue() {
	if (this->start == this->end) throw "空队";
	this->length--;
	return this->data[this->start = (this->start + 1) % QueueSize];
}

// 取队头
template <typename DataType>
DataType CirQueue<DataType>::GetHead() {
	if (this->start == this->end) throw "空队";
	return this->data[(this->start + 1) % QueueSize];
}

// 判空
template <typename DataType>
int CirQueue<DataType>::Empty() {
	return length ? 0 : 1;
}