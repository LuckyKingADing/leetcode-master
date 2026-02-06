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
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k);
};

string Solution::reverseStr(string s, int k) {
    // TODO: Implement the reverseStr function
    return "";
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

    return 0;
}