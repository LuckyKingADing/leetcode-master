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
    void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) { // 传入&,带引用
        // 法二 快慢指针法,更简洁
        int slow = 0; // slow慢指针,i是快指针
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                while (i < s.size() && s[i] != ' ') {
                    s[slow] = s[i];
                    slow++;
                    i++;
                }
            }
        }
        s.resize(slow);

    }

    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] ==' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

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

    // 测试用例 4: 单个单词
    string s4 = "hello";
    string result4 = sol.reverseWords(s4);
    cout << "Test Case 4: s=\"" << s4 << "\", Result=\"" << result4 << "\" (Expected: \"hello\")" << endl;

    // 测试用例 5: 多个单词
    string s5 = "I love coding";
    string result5 = sol.reverseWords(s5);
    cout << "Test Case 5: s=\"" << s5 << "\", Result=\"" << result5 << "\" (Expected: \"coding love I\")" << endl;

    // 测试用例 6: 前导和尾随空格
    string s6 = "  world peace  ";
    string result6 = sol.reverseWords(s6);
    cout << "Test Case 6: s=\"" << s6 << "\", Result=\"" << result6 << "\" (Expected: \"peace world\")" << endl;

    // 测试用例 7: 单词间多个空格
    string s7 = "one   two    three";
    string result7 = sol.reverseWords(s7);
    cout << "Test Case 7: s=\"" << s7 << "\", Result=\"" << result7 << "\" (Expected: \"three two one\")" << endl;

    // 测试用例 8: 包含数字
    string s8 = "leet123 code456";
    string result8 = sol.reverseWords(s8);
    cout << "Test Case 8: s=\"" << s8 << "\", Result=\"" << result8 << "\" (Expected: \"code456 leet123\")" << endl;

    // 测试用例 9: 只有两个单词
    string s9 = "a b";
    string result9 = sol.reverseWords(s9);
    cout << "Test Case 9: s=\"" << s9 << "\", Result=\"" << result9 << "\" (Expected: \"b a\")" << endl;

    return 0;
}