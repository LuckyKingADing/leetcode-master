/* [力扣题目链接](https://leetcode.cn/problems/reverse-string-ii/)

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"

示例 2：
输入：s = "abcd", k = 2
输出："bacd"

提示：
* 1 <= s.length <= 10^4
* s 仅由小写英文组成
* 1 <= k <= 10^4

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k);

    // 原地翻转字符串中的字符.
    void reverse(string& s, int start, int end); 
};

// 二刷 通过
string Solution::reverseStr(string s, int k) {
    for (int i = 0; i < s.size() - 1; i += 2 * k) {
        if (i + k <= s.size()) {
            reverse(s, i, i + k -1);
        } else if (i + k > s.size()) {
            reverse(s, i, s.size());
        }
    }
    return s;

};

void Solution::reverse(string& s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}



int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "abcdefg";
    int k1 = 2;
    string result1 = sol.reverseStr(s1, k1);
    cout << "Test Case 1: s=\"" << s1 << "\", k=" << k1 << ", Result=\"" << result1 << "\" (Expected: \"bacdfeg\")" << endl;

    // 测试用例 2
    string s2 = "abcd";
    int k2 = 2;
    string result2 = sol.reverseStr(s2, k2);
    cout << "Test Case 2: s=\"" << s2 << "\", k=" << k2 << ", Result=\"" << result2 << "\" (Expected: \"bacd\")" << endl;

    // 测试用例 3: 剩余字符正好等于 k
    string s3 = "abc";
    int k3 = 2;
    string result3 = sol.reverseStr(s3, k3);
    cout << "Test Case 3: s=\"" << s3 << "\", k=" << k3 << ", Result=\"" << result3 << "\" (Expected: \"bac\")" << endl;

    // 测试用例 4: 剩余字符少于 k
    string s4 = "a";
    int k4 = 2;
    string result4 = sol.reverseStr(s4, k4);
    cout << "Test Case 4: s=\"" << s4 << "\", k=" << k4 << ", Result=\"" << result4 << "\" (Expected: \"a\")" << endl;

    // 测试用例 5: k = 3, 字符串长度是 2k 的倍数
    string s5 = "abcdef";
    int k5 = 3;
    string result5 = sol.reverseStr(s5, k5);
    cout << "Test Case 5: s=\"" << s5 << "\", k=" << k5 << ", Result=\"" << result5 << "\" (Expected: \"cbadef\")" << endl;

    // 测试用例 6: k = 3, 剩余字符少于 k
    string s6 = "abcdefg";
    int k6 = 3;
    string result6 = sol.reverseStr(s6, k6);
    cout << "Test Case 6: s=\"" << s6 << "\", k=" << k6 << ", Result=\"" << result6 << "\" (Expected: \"cbadefg\")" << endl;

    // 测试用例 7: k = 3, 剩余字符等于 k
    string s7 = "abcdefgh";
    int k7 = 3;
    string result7 = sol.reverseStr(s7, k7);
    cout << "Test Case 7: s=\"" << s7 << "\", k=" << k7 << ", Result=\"" << result7 << "\" (Expected: \"cbadefhg\")" << endl;

    return 0;
}