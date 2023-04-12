#include "SeqList.h"
#include <iostream>

// 无参构造，建立空的顺序表
template <typename DataType>
SeqList<DataType>::SeqList() {
	std::cout << "线性表已被创建" << std::endl;
};

// 有参构造，建立长度为n的顺序表
template <typename DataType>
SeqList<DataType>::SeqList(DataType a[], int n) {
	std::cout << "线性表已被创建，长度为" << n << std::endl;
}

// 析构函数，就是在对象销毁时会被执行
template <typename DataType>
SeqList<DataType>::~SeqList() {

}

// 获取线性表的长度
template <typename DataType>
int SeqList<DataType>::Length() {

}

// 按位查找，查找第i个元素
template <typename DataType>
DataType SeqList<DataType>::Get(int i) {

}

// 按值查找，查找值为x的元素
template <typename DataType>
int SeqList<DataType>::Locate(DataType x) {

}

// 插入操作，在第i个位置插入值为x的元素
template <typename DataType>
void SeqList<DataType>::Insert(int i, DataType x) {

}

// 删除操作，删除第i个元素
template <typename DataType>
DataType SeqList<DataType>::Delete(int i) {

}

// 判断线性表是否为空
template <typename DataType>
int SeqList<DataType>::Empty() {

}

// 遍历操作，按序号依次输出各元素
template <typename DataType>
void SeqList<DataType>::PrintList() {

}
