#include <iostream>
#include "MyString.h"

using namespace std;

/**
* 奇数阶幻方函数
* 构造方法：
* 1. 将数字 1 放置在第一行的中间位置，即第一行的正中间列。
* 2. 从数字 2 开始，依次填充到 n*n。
* 3. 如果当前位置在第一行，则下一个位置是当前位置的正上方。
* 4. 如果当前位置在最后一列，则下一个位置是当前位置的正右方。
* 5. 如果当前位置在第一行且在最后一列，则下一个位置是当前位置的正下方。
* 6. 如果当前位置已经被填充，则下一个位置是当前位置的正下方。
* 7. 如果下一个位置超出边界，则将其移到相应的边界上。
* 8. 重复步骤 3-7，直到填充完所有的数字。
*/
void MagicSquareOfOddOrder(int n, int magic_square[][29]) {
    // 如果不是1-30的奇数就抛出异常
    if (!(n % 2) || (n < 1 && n > 29)) throw "odd number & range from 1 to 30";

    int row = 0;  // 当前行
    int col = n / 2;  // 当前列

    // 从1到n*n依次填充幻方矩阵
    for (int num = 1; num <= n * n; num++) {
        magic_square[row][col] = num;  // 填充当前位置

        // 计算下一个位置的行和列
        int next_row = (row - 1 + n) % n;   // 上移一行
        int next_col = (col + 1) % n;       // 右移一列

        // 如果下一个位置已经被填充，向下移一行
        if (magic_square[next_row][next_col] != 0) {
            row = (row + 1) % n;
        }
        else {
            row = next_row;
            col = next_col;
        }
    }
    
}

void PrintMagicSquare(int arr[][29], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    char first[100], second[100];

    cout << "输入两个字符串：" << endl;
    cin >> first >> second;


	cout << "拼接后的结果：" << Splice(first, second) << endl;
	cout << "比较后的结果：" << Compare(first, second) << endl;

    int n = 0;
    cout << "输入奇数阶幻方的阶数：" << endl;
    cin >> n;

    int magic_square[29][29] = { 0 }; // 定义并初始化
    MagicSquareOfOddOrder(n, magic_square);

    cout << "某一" << n << "阶奇数阶幻方如下：" << endl;
    PrintMagicSquare(magic_square, n);

	return 0;
}
