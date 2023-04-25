#pragma once

const int max_length = 100;             // 最大长度
const int ignore_num = 0x7FFFFFFF;      // 忽略数据

// 顺序
class SeqTree {
public:
    SeqTree();                          // 构造函数
    ~SeqTree();                         // 析构函数
    void Insert(int index, int data);   // 插入结点
    int Desert(int index);              // 删除结点
    int ParentsNum();                   // 双亲结点个数
    int LeavesNum();                    // 叶结点个数
private:
    int datas[max_length];              // 数据
};
