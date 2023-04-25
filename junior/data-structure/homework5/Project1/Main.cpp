#include "SeqTree.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	SeqTree tree;
	
	int cnt = 0;
	string user_in;
	cout << "#表示此位置为空，$结束输入" << endl;
	while (1) {
		cout << "请输入第" << cnt << "个结点的数据：";
		cin >> user_in;
		// 判断输入
		if (!user_in.compare("$")) {
			cout << "----------------结束输入-------------------" << endl;
			cout << "双亲结点个数为：" << tree.ParentsNum() << "个" << endl;
			cout << "叶子结点个数为：" << tree.LeavesNum() << "个" << endl;
			break;
		}
		else if (!user_in.compare("#")) {
			// 什么都不做
		}
		else {
			tree.Insert(cnt, stoi(user_in));
		}
		
		cnt++;	// 计数器自加
	}

	return 0;
}
