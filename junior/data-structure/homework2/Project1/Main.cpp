#include <iostream>
#include "SeqList.h"

using namespace std;

// 菜单
template <typename DataType = int>
void Menu(int choose, SeqList<>* list);
// 清除控制台（未使用）
void Clear();

int main() {
	SeqList<> list;
	int choose = -1;

	while (choose) {
		cout << "--------------------------------" << endl;
		cout << "元素[" << list.Length() << "]个|最大容量[" << MaxSize << "]个|顺序表状态";
		list.PrintList();
		cout << "1、插入一个数字" << endl;
		cout << "2、指定位置插入一个数字" << endl;
		cout << "3、获取某个数的具体位置" << endl;
		cout << "4、获取一个具体位置的数" << endl;
		cout << "5、删除一个指定位置的数" << endl;
		cout << "0、退出演示" << endl;
		cout << "请输入对应服务编号：";
		cin >> choose;
		try {
			Menu(choose, &list);
		}
		catch (const char * e) {
			cout << "出错啦，错误消息：" << e << endl;
		}
		cout << endl << "--------------------------------" << endl;
	}
}

// 菜单
template <typename DataType = int>
void Menu(int choose, SeqList<>* list) {
	int in_1 = 0, in_2 = 0, temp_1 = 0;
	switch (choose) {
		// 插入一个数字
	case 1:
		cout << "请输入要插入的数字：";
		cin >> in_1;
		list->Insert(list->Length() + 1, in_1);
		break;
		// 指定位置插入一个数字
	case 2:
		cout << "请输入指定位置与要插入的数字：";
		cin >> in_1 >> in_2;
		list->Insert(in_1, in_2);
		break;
		// 获取某个数的具体位置
	case 3:
		cout << "请输入要查询的数：";
		cin >> in_1;
		temp_1 = list->Locate(in_1);
		if (temp_1) {
			cout << "所查数第一次出现的位置是：" << temp_1 << endl;
		}
		else {
			cout << "没有查到哦~" << endl;
		}
		break;
		// 获取一个具体位置的数
	case 4:
		cout << "请输入要查找的位置：";
		cin >> in_1;
		temp_1 = list->Get(in_1);
		cout << "所在位置的数是：" << temp_1 << endl;
		break;
		// 删除一个指定位置的数
	case 5:
		cout << "请输入要删除的位置：";
		cin >> in_1;
		list->Delete(in_1);
		break;
	case 0:
		cout << "感谢体验，再见~" << endl;
		break;
	default:
		cout << "输入有误" << endl;
	}
}

// 清除屏幕（未使用）
void Clear()
{
	cout << "\x1B[2J\x1B[H";
}
