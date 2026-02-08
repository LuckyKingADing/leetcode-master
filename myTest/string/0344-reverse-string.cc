/* [力扣题目链接](https://leetcode.cn/problems/reverse-string/)

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]

示例 2：
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]

提示：
* 1 <= s.length <= 10^5
* s[i] 都是 ASCII 码表中的可打印字符

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s);
};

void Solution::reverseString(vector<char>& s) {
    // TODO: Implement the reverseString function
    // 双指针法，双向查找法
    for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
        // 方法1 直接用库函数swap
        //swap(s[i], s[j]);

        // 方法2 用临时字符tmp交换
        // char tmp = s[i];
        // s[i] = s[j];
        // s[j] = tmp;

        // 方法3 
        /* 使用**位运算（XOR 异或运算）**来交换两个变量的值，而不使用临时变量。这是 C++ 中的经典技巧，基于 XOR 的数学性质：
            a ^ a = 0（任何数与自己异或为 0）。
            a ^ 0 = a（任何数与 0 异或不变）。
            a ^ b ^ a = b（异或运算满足交换律和结合律）。 */
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];


    }
}

int main() {
    Solution sol;

    // 测试用例 1
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s1);
    cout << "Test Case 1: s = [";
    for (size_t i = 0; i < s1.size(); i++) {
        cout << "\"" << s1[i] << "\"";
        if (i < s1.size() - 1) cout << ",";
    }
    cout << "] (Expected: [\"o\",\"l\",\"l\",\"e\",\"h\"])" << endl;

    // 测试用例 2
    vector<char> s2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(s2);
    cout << "Test Case 2: s = [";
    for (size_t i = 0; i < s2.size(); i++) {
        cout << "\"" << s2[i] << "\"";
        if (i < s2.size() - 1) cout << ",";
    }
    cout << "] (Expected: [\"h\",\"a\",\"n\",\"n\",\"a\",\"H\"])" << endl;

    return 0;
}