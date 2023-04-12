/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ��ȡǰ׺����
vector<int> get_prefix_array(string pattern) {
    int len = pattern.size();
    vector<int> prefix(len, 0);  // ��ʼ��ǰ׺����
    int j = 0;
    for (int i = 1; i < len; i++) {
        // �����ǰ�ַ���ƥ�䣬��ǰ��תֱ���ҵ�ƥ���λ��
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j - 1];
        }
        // �����ǰ�ַ�ƥ�䣬����ǰ׺���鲢�ƶ�ָ��
        if (pattern[j] == pattern[i]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

// KMP�㷨������
void kmp(string text, string pattern) {
    vector<int> prefix = get_prefix_array(pattern);  // ��ȡǰ׺����
    int n = text.size();
    int m = pattern.size();
    int j = 0;  // pattern��ָ��
    for (int i = 0; i < n; i++) {
        // �����ǰ�ַ���ƥ�䣬��ǰ��תֱ���ҵ�ƥ���λ��
        while (j > 0 && pattern[j] != text[i]) {
            j = prefix[j - 1];
        }
        // �����ǰ�ַ�ƥ�䣬����ָ��
        if (pattern[j] == text[i]) {
            j++;
        }
        // ���patternָ�뵽����β����˵���ҵ���һ��ƥ��
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            j = prefix[j - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);  // ��ȡ�����ո�������ַ���
    cout << "Enter pattern to be searched: ";
    getline(cin, pattern);  // ��ȡ�����ո�������ַ���
    kmp(text, pattern);
    return 0;
}
*/