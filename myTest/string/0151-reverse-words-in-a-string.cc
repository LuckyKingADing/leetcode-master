/* [力扣题目链接](https://leetcode.cn/problems/reverse-words-in-a-string/)

给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回一个按单词顺序颠倒且 单词 之间用单个空格连接的字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：
输入：s = "  hello world  "
输出："world hello"

示例 3：
输入：s = "a good   example"
输出："example good a"

提示：
* 1 <= s.length <= 10^4
* s 包含英文大小写字母、数字和空格 ' '
* s 中 至少存在一个 单词

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s);
};

string Solution::reverseWords(string s) {
    // TODO: Implement the reverseWords function
    return "";
}

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "the sky is blue";
    string result1 = sol.reverseWords(s1);
    cout << "Test Case 1: s=\"" << s1 << "\", Result=\"" << result1 << "\" (Expected: \"blue is sky the\")" << endl;

    // 测试用例 2
    string s2 = "  hello world  ";
    string result2 = sol.reverseWords(s2);
    cout << "Test Case 2: s=\"" << s2 << "\", Result=\"" << result2 << "\" (Expected: \"world hello\")" << endl;

    // 测试用例 3
    string s3 = "a good   example";
    string result3 = sol.reverseWords(s3);
    cout << "Test Case 3: s=\"" << s3 << "\", Result=\"" << result3 << "\" (Expected: \"example good a\")" << endl;

    return 0;
}