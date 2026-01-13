/* [力扣题目链接](https://leetcode.cn/problems/minimum-window-substring/)

给你一个字符串 s 、一个字符串 t 。返回 s 中包含 t 所有字符的最小子串。如果 s 中不存在符合条件的子串，则返回空字符串 "" 。

注意：
对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"

示例 3：
输入：s = "a", t = "aa"
输出：""

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 请在此处实现你的代码
        return "";
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "ADOBECODEBANC", t1 = "ABC";
    cout << "Test Case 1: s = \"ADOBECODEBANC\", t = \"ABC\"" << endl;
    cout << "Result: " << sol.minWindow(s1, t1) << " (Expected: \"BANC\")" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    string s2 = "a", t2 = "aa";
    cout << "Test Case 2: s = \"a\", t = \"aa\"" << endl;
    cout << "Result: \"" << sol.minWindow(s2, t2) << "\" (Expected: \"\")" << endl;
    cout << "----------------" << endl;

    return 0;
}