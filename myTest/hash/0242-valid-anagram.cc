/* [力扣题目链接](https://leetcode.cn/problems/valid-anagram/)

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false

提示:
* 1 <= s.length, t.length <= 5 * 10^4
* s 和 t 仅包含小写字母

进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

*/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
        
        // ps:本质也是数组的应用？只不过是涉及次数的统计
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "anagram", t1 = "nagaram";
    bool result1 = sol.isAnagram(s1, t1);
    cout << "Test Case 1: s=\"anagram\", t=\"nagaram\", Result = " << (result1 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 2
    string s2 = "rat", t2 = "car";
    bool result2 = sol.isAnagram(s2, t2);
    cout << "Test Case 2: s=\"rat\", t=\"car\", Result = " << (result2 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 3
    string s3 = "a", t3 = "ab";
    bool result3 = sol.isAnagram(s3, t3);
    cout << "Test Case 3: s=\"a\", t=\"ab\", Result = " << (result3 ? "true" : "false") << " (Expected: false)" << endl;

    return 0;
}