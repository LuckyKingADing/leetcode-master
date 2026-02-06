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
    bool canConstruct(string ransomNote, string magazine) {
        // // 方法1：hash哈希表
        // for (int i = 0; i < magazine.length(); i++) {
        //     for (int j = 0; j < ransomNote.length(); j++) {
        //         if (magazine[i] == ransomNote[j]) {
        //             ransomNote.erase(ransomNote.begin() + j); // 在ransoNote中删除这个字符
        //             break; //这个很关键，是为了防止重复删除
        //         }
        //     }
        // }
        // if (ransomNote.length() == 0) {
        //     return true;
        // }
        // return false;

        // 方法2：使用数组
        int record[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.size(); i++) {
            record[magazine[i] - 'a']++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0) {
                return false;
            }
        }
        return true;

    }
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

    // 测试用例 4
    string ransomNote4 = "abc", magazine4 = "aabbc";
    bool result4 = sol.canConstruct(ransomNote4, magazine4);
    cout << "Test Case 4: ransomNote=\"abc\", magazine=\"aabbc\", Result = " << (result4 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 5
    string ransomNote5 = "hello", magazine5 = "olleh";
    bool result5 = sol.canConstruct(ransomNote5, magazine5);
    cout << "Test Case 5: ransomNote=\"hello\", magazine=\"olleh\", Result = " << (result5 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 6
    string ransomNote6 = "hello", magazine6 = "world";
    bool result6 = sol.canConstruct(ransomNote6, magazine6);
    cout << "Test Case 6: ransomNote=\"hello\", magazine=\"world\", Result = " << (result6 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 7
    string ransomNote7 = "aaa", magazine7 = "aa";
    bool result7 = sol.canConstruct(ransomNote7, magazine7);
    cout << "Test Case 7: ransomNote=\"aaa\", magazine=\"aa\", Result = " << (result7 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 8
    string ransomNote8 = "z", magazine8 = "abcdefghijklmnopqrstuvwxyz";
    bool result8 = sol.canConstruct(ransomNote8, magazine8);
    cout << "Test Case 8: ransomNote=\"z\", magazine=\"abcdefghijklmnopqrstuvwxyz\", Result = " << (result8 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 9
    string ransomNote9 = "bb", magazine9 = "b";
    bool result9 = sol.canConstruct(ransomNote9, magazine9);
    cout << "Test Case 9: ransomNote=\"bb\", magazine=\"b\", Result = " << (result9 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 10
    string ransomNote10 = "test", magazine10 = "tteesstt";
    bool result10 = sol.canConstruct(ransomNote10, magazine10);
    cout << "Test Case 10: ransomNote=\"test\", magazine=\"tteesstt\", Result = " << (result10 ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}