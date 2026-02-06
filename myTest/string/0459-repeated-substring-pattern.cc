/* [力扣题目链接](https://leetcode.cn/problems/repeated-substring-pattern/)

给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

示例 1:
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。

示例 2:
输入: s = "aba"
输出: false

示例 3:
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

提示：
* 1 <= s.length <= 10^4
* s 由小写英文字母组成

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s);
};

bool Solution::repeatedSubstringPattern(string s) {
    // TODO: Implement the repeatedSubstringPattern function
    return false;
}

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "abab";
    bool result1 = sol.repeatedSubstringPattern(s1);
    cout << "Test Case 1: s=\"" << s1 << "\", Result=" << (result1 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 2
    string s2 = "aba";
    bool result2 = sol.repeatedSubstringPattern(s2);
    cout << "Test Case 2: s=\"" << s2 << "\", Result=" << (result2 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 3
    string s3 = "abcabcabcabc";
    bool result3 = sol.repeatedSubstringPattern(s3);
    cout << "Test Case 3: s=\"" << s3 << "\", Result=" << (result3 ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}