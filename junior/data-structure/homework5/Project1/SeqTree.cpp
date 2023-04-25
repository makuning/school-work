#include "SeqTree.h"
#include <cmath>
#include <iostream>

using namespace std;

// 构造函数
SeqTree::SeqTree() {
    // 将数据默认为忽略值，表示此位置没有数据
    for (int i = 0; i < max_length; i++) {
        datas[i] = ignore_num;
    }
}


SeqTree::~SeqTree() {

}
// 双亲结点个数
int SeqTree::ParentsNum() {
    int cnt = 0;        // 计数器

    // 最后一层不用查，一定不是双亲结点
    int i = 0;
    for (; i < pow(2, floor(log(max_length) / log(2))) - 1; i++) {
        if (this->datas[i] == ignore_num) continue; // 如果是空的就跳过
        if (this->datas[i * 2 + 1] != ignore_num || this->datas[i * 2 + 2] != ignore_num) cnt++;    // 如果有孩子就是双亲结点
    }

    return cnt;
}

// 叶结点个数
int SeqTree::LeavesNum() {
    int cnt = 0;        // 计数器

    // 最后一层不用查，一定是叶子结点
    int i = 0;
    for (; i < pow(2, floor(log(max_length) / log(2))) - 1; i++) {
        if (this->datas[i] == ignore_num) continue; // 如果是空的就跳过
        if (this->datas[i * 2 + 1] == ignore_num && this->datas[i * 2 + 2] == ignore_num) cnt++;    // 如果没有孩子就是叶结点
    }

    // 遍历最后一层，如果有数据就是叶结点
    for (; i < max_length; i++) {
        if (this->datas[i] != ignore_num) cnt++;
    }

    return cnt;
}

// 插入结点
void SeqTree::Insert(int index, int data) {
    this->datas[index] = data;
}

// 删除结点
int SeqTree::Desert(int index) {
    int result = this->datas[index];
    this->datas[index] = ignore_num;
    return result;
}