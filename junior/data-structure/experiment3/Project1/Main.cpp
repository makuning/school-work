#include "CirQueue.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
	default_random_engine engine;	// 创建随机数引擎
	engine.seed(time(0));			// 将当前时间的时间戳设置为随机数种子

	try {
		CirQueue<> queue;				// 创建循环队列

		// 设置10个0~100的随机数入队
		for (int i = 0; i < 10; i++) {
			queue.EnQueue(engine() % 101);	// 随机数入队
		}

		if (queue.Empty()) {
			cout << "队空";
		}
		else {
			cout << "队头元素为：" << queue.GetHead();
		}
	}
	catch (const char * msg) {
		cout << "出错了：" << msg << endl;
	}

	return 0;
}