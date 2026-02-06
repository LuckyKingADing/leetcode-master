/* [力扣题目链接](https://leetcode.cn/problems/implement-strstr/)

实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

示例 1：
输入：haystack = "hello", needle = "ll"
输出：2

示例 2：
输入：haystack = "aaaaa", needle = "bba"
输出：-1

提示：
* 1 <= haystack.length, needle.length <= 10^4
* haystack 和 needle 仅由小写英文字符组成

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle);
};

int Solution::strStr(string haystack, string needle) {
    // TODO: Implement the strStr function
    return -1;
}

int main() {
    Solution sol;

    // 测试用例 1
    string haystack1 = "hello";
    string needle1 = "ll";
    int result1 = sol.strStr(haystack1, needle1);
    cout << "Test Case 1: haystack=\"" << haystack1 << "\", needle=\"" << needle1 << "\", Result=" << result1 << " (Expected: 2)" << endl;

    // 测试用例 2
    string haystack2 = "aaaaa";
    string needle2 = "bba";
    int result2 = sol.strStr(haystack2, needle2);
    cout << "Test Case 2: haystack=\"" << haystack2 << "\", needle=\"" << needle2 << "\", Result=" << result2 << " (Expected: -1)" << endl;

    // 测试用例 3
    string haystack3 = "hello";
    string needle3 = "";
    int result3 = sol.strStr(haystack3, needle3);
    cout << "Test Case 3: haystack=\"" << haystack3 << "\", needle=\"\", Result=" << result3 << " (Expected: 0)" << endl;

    return 0;
}