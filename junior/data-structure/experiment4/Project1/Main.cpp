#include <iostream>
#include "MyString.h"

using namespace std;

/**
* �����׻÷�����
* ���췽����
* 1. ������ 1 �����ڵ�һ�е��м�λ�ã�����һ�е����м��С�
* 2. ������ 2 ��ʼ��������䵽 n*n��
* 3. �����ǰλ���ڵ�һ�У�����һ��λ���ǵ�ǰλ�õ����Ϸ���
* 4. �����ǰλ�������һ�У�����һ��λ���ǵ�ǰλ�õ����ҷ���
* 5. �����ǰλ���ڵ�һ���������һ�У�����һ��λ���ǵ�ǰλ�õ����·���
* 6. �����ǰλ���Ѿ�����䣬����һ��λ���ǵ�ǰλ�õ����·���
* 7. �����һ��λ�ó����߽磬�����Ƶ���Ӧ�ı߽��ϡ�
* 8. �ظ����� 3-7��ֱ����������е����֡�
*/
void MagicSquareOfOddOrder(int n, int magic_square[][29]) {
    // �������1-30���������׳��쳣
    if (!(n % 2) || (n < 1 && n > 29)) throw "odd number & range from 1 to 30";

    int row = 0;  // ��ǰ��
    int col = n / 2;  // ��ǰ��

    // ��1��n*n�������÷�����
    for (int num = 1; num <= n * n; num++) {
        magic_square[row][col] = num;  // ��䵱ǰλ��

        // ������һ��λ�õ��к���
        int next_row = (row - 1 + n) % n;   // ����һ��
        int next_col = (col + 1) % n;       // ����һ��

        // �����һ��λ���Ѿ�����䣬������һ��
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

    cout << "���������ַ�����" << endl;
    cin >> first >> second;


	cout << "ƴ�Ӻ�Ľ����" << Splice(first, second) << endl;
	cout << "�ȽϺ�Ľ����" << Compare(first, second) << endl;

    int n = 0;
    cout << "���������׻÷��Ľ�����" << endl;
    cin >> n;

    int magic_square[29][29] = { 0 }; // ���岢��ʼ��
    MagicSquareOfOddOrder(n, magic_square);

    cout << "ĳһ" << n << "�������׻÷����£�" << endl;
    PrintMagicSquare(magic_square, n);

	return 0;
}
