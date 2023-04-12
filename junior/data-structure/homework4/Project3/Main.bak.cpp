/*
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 获取前缀数组
vector<int> get_prefix_array(string pattern) {
    int len = pattern.size();
    vector<int> prefix(len, 0);  // 初始化前缀数组
    int j = 0;
    for (int i = 1; i < len; i++) {
        // 如果当前字符不匹配，向前跳转直到找到匹配的位置
        while (j > 0 && pattern[j] != pattern[i]) {
            j = prefix[j - 1];
        }
        // 如果当前字符匹配，更新前缀数组并移动指针
        if (pattern[j] == pattern[i]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

// KMP算法主函数
void kmp(string text, string pattern) {
    vector<int> prefix = get_prefix_array(pattern);  // 获取前缀数组
    int n = text.size();
    int m = pattern.size();
    int j = 0;  // pattern的指针
    for (int i = 0; i < n; i++) {
        // 如果当前字符不匹配，向前跳转直到找到匹配的位置
        while (j > 0 && pattern[j] != text[i]) {
            j = prefix[j - 1];
        }
        // 如果当前字符匹配，更新指针
        if (pattern[j] == text[i]) {
            j++;
        }
        // 如果pattern指针到达了尾部，说明找到了一个匹配
        if (j == m) {
            cout << "Pattern found at index " << i - m + 1 << endl;
            j = prefix[j - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    getline(cin, text);  // 获取包含空格的输入字符串
    cout << "Enter pattern to be searched: ";
    getline(cin, pattern);  // 获取包含空格的输入字符串
    kmp(text, pattern);
    return 0;
}
*/