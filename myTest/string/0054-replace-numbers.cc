/* [卡码网题目链接](https://kamacoder.com/problempage.php?pid=1064)

给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。

例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"

输入：一个字符串 s,s 仅包含小写字母和数字字符。

输出：打印一个新的字符串，其中每个数字字符都被替换为了number

样例输入：a1b2c3

样例输出：anumberbnumbercnumber

数据范围：1 <= s.length < 10000。

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceNumbers(string s);

};

string Solution::replaceNumbers(string s) {
    int sOldIndex = s.size() - 1;
    int count = 0; // 统计数字的个数
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count++;
        }
    }

    s.resize(s.size() + count * 5);
    int sNewIndex = s.size() - 1;
    while (sOldIndex >= 0) {
        if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
            s[sNewIndex--] = 'r';
            s[sNewIndex--] = 'e';
            s[sNewIndex--] = 'b';
            s[sNewIndex--] = 'm';
            s[sNewIndex--] = 'u';
            s[sNewIndex--] = 'n';
        } else {
            s[sNewIndex--] = s[sOldIndex];
        }
        sOldIndex--;
    }
    return s;
    
}

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "a1b2c3";
    string result1 = sol.replaceNumbers(s1);
    cout << "Test Case 1: s=\"" << s1 << "\", Result=\"" << result1 << "\" (Expected: \"anumberbnumbercnumber\")" << endl;

    // 测试用例 2
    string s2 = "a5b";
    string result2 = sol.replaceNumbers(s2);
    cout << "Test Case 2: s=\"" << s2 << "\", Result=\"" << result2 << "\" (Expected: \"anumberb\")" << endl;

    // 测试用例 3: 没有数字
    string s3 = "abc";
    string result3 = sol.replaceNumbers(s3);
    cout << "Test Case 3: s=\"" << s3 << "\", Result=\"" << result3 << "\" (Expected: \"abc\")" << endl;

    // 测试用例 4: 只有数字
    string s4 = "123";
    string result4 = sol.replaceNumbers(s4);
    cout << "Test Case 4: s=\"" << s4 << "\", Result=\"" << result4 << "\" (Expected: \"numbernumbernumber\")" << endl;

    // 测试用例 5: 开头是数字
    string s5 = "1abc";
    string result5 = sol.replaceNumbers(s5);
    cout << "Test Case 5: s=\"" << s5 << "\", Result=\"" << result5 << "\" (Expected: \"numberabc\")" << endl;

    // 测试用例 6: 结尾是数字
    string s6 = "abc3";
    string result6 = sol.replaceNumbers(s6);
    cout << "Test Case 6: s=\"" << s6 << "\", Result=\"" << result6 << "\" (Expected: \"abcnumber\")" << endl;

    // 测试用例 7: 多个连续数字
    string s7 = "a12b";
    string result7 = sol.replaceNumbers(s7);
    cout << "Test Case 7: s=\"" << s7 << "\", Result=\"" << result7 << "\" (Expected: \"anumbernumberb\")" << endl;

    // 测试用例 8: 单个数字
    string s8 = "a1";
    string result8 = sol.replaceNumbers(s8);
    cout << "Test Case 8: s=\"" << s8 << "\", Result=\"" << result8 << "\" (Expected: \"anumber\")" << endl;

    // 测试用例 9: 数字在中间
    string s9 = "ab1c";
    string result9 = sol.replaceNumbers(s9);
    cout << "Test Case 9: s=\"" << s9 << "\", Result=\"" << result9 << "\" (Expected: \"abnumberc\")" << endl;

    return 0;
}