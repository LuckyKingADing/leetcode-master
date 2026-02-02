/* [力扣题目链接](https://leetcode.cn/problems/ransom-note/)

给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

示例 1：
输入：ransomNote = "a", magazine = "b"
输出：false

示例 2：
输入：ransomNote = "aa", magazine = "ab"
输出：false

示例 3：
输入：ransomNote = "aa", magazine = "aab"
输出：true

提示：
* 1 <= ransomNote.length, magazine.length <= 10^5
* ransomNote 和 magazine 由小写英文字母组成

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine);
};

int main() {
    Solution sol;

    // 测试用例 1
    string ransomNote1 = "a", magazine1 = "b";
    bool result1 = sol.canConstruct(ransomNote1, magazine1);
    cout << "Test Case 1: ransomNote=\"a\", magazine=\"b\", Result = " << (result1 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 2
    string ransomNote2 = "aa", magazine2 = "ab";
    bool result2 = sol.canConstruct(ransomNote2, magazine2);
    cout << "Test Case 2: ransomNote=\"aa\", magazine=\"ab\", Result = " << (result2 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 3
    string ransomNote3 = "aa", magazine3 = "aab";
    bool result3 = sol.canConstruct(ransomNote3, magazine3);
    cout << "Test Case 3: ransomNote=\"aa\", magazine=\"aab\", Result = " << (result3 ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}