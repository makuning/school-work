#include <iostream>
#include "LinkList.h"
#include <random>

using namespace std;

// 菜单
template <typename DataType = int>
void Menu(int choose, LinkList<>* list);

int main() {
	/*int init1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int init2[] = { 11,12,13,14,15,16,17,18,19,20 };
	LinkList<> list1(init1, 10);
	LinkList<> list2(init2, 10);

	LinkList<>* list3 = list1.Merge(&list1, &list2);

	list3->PrintList();*/

	default_random_engine rand;	// 创建随机数引擎
	rand.seed(time(0));			// 将当前时间的时间戳作为种子

	int init[10]{};				// 定义用于装10个随机1~100的数字的数组容器

	// 随机10个1~100的数字
	for (int i = 0; i < 10; i++) {
		init[i] = rand() % 101;
	}

	LinkList<> list(init, 10);	// 将数字装进链表中

	int choose = -1;

	while (choose) {
		cout << "--------------------------------" << endl;
		cout << "元素[" << list.Length() << "]个|单链表状态";
		list.PrintList();
		cout << "1、插入一个数字" << endl;
		cout << "2、指定位置插入一个数字" << endl;
		cout << "3、获取某个数的具体位置" << endl;
		cout << "4、获取一个具体位置的数" << endl;
		cout << "5、删除一个指定位置的数" << endl;
		cout << "6、合并单链表" << endl;
		cout << "0、退出演示" << endl;
		cout << "请输入对应服务编号：";
		cin >> choose;
		try {
			Menu(choose, &list);
		}
		catch (const char* e) {
			cout << "出错啦，错误消息：" << e << endl;
		}
		cout << endl << "--------------------------------" << endl;
	}
}

// 菜单
template <typename DataType = int>
void Menu(int choose, LinkList<>* list) {
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
