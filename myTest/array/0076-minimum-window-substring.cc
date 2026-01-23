/* [力扣题目链接](https://leetcode.cn/problems/minimum-window-substring/)

给你一个字符串 s 、一个字符串 t 。
返回 s 中包含 t 所有字符的最小子串。
如果 s 中不存在符合条件的子串，则返回空字符串 "" 。

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

我的思路：
1.如果t的长度大于s，肯定s包含不了t，输出空""
2.如果t的长度等于s，判断s中是否有所有的t字符？，如果是，输出s，其实长度相等可以合并到3中？
3.t长度小于s，使用滑动窗口，在s中

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 请在此处实现你的代码
        // 滑动窗口
        if (s.size() < t.size()) { return ""; }

        unordered_map<char, int> need; // t中字符及其数量
        unordered_map<char, int> window; // 窗口内的字符及其数量
        
        // 初始化need
        for (char c : t) {
            need[c]++;
        }

        int left = 0, right = 0;
        int minLen = INT_MAX; // 定义最小长度，从INT_MAX最大值开始赋值。
        int start = 0;// 最小子串的起始位置
        int count = 0; // 覆盖的字符种类数

        // 滑动窗口循环：
        // 我的思路：1.把s的字符加到win中，记录到window map，2.比对need和windows，是否windows能够包含need,如果能，打出长度，不能，收缩左边，扩展右边，继续探索。

        for (int right = 0; right < s.size(); ++right) {
            // 把s加到win中
            char c = s[right];
            window[c]++;

            // 注意：如果不包含need.count(c)会失败
            if (need.count(c) && window[c] == need[c]) {// 检查覆盖：如果c在need中，且window[c]正好等于need[c]，则count++
                count++;
            }
            
            // 用while是因为只要窗口还覆盖t，且左指针没超过右指针，就继续收缩。为什么循环：因为在覆盖t的情况下，我们想尽可能缩小窗口（移动left），看看能不能找到更短的子串。一旦left移动太多，导致不再覆盖t（count减少），循环就停了。
            while (count == need.size() && left <= right) { // 要小于等于 而不是小于。
                // 更新最小长度：如果当前窗口长度(right - left + 1) < minLen，更新minLen和start
                if (right - left + 1 < minLen) {
                    start = left;
                    minLen = right - left + 1;
                }

                // 左指针收缩：获取左字符d，减少window[d]的数量
                char d = s[left]; // 获取s的左指针
                window[d]--; //减少窗口中的d的数量，因为左指针收缩了

                // 如果d在need中，且window[d] < need[d]，说明移除后，window不能覆盖need了，则把windows覆盖住的字符数量 count--，表示这个字符种类不再覆盖
                if (need.count(d) && window[d] < need[d]) // need.count(d)是unordered_map 的成员函数，返回 d 在 need 中出现的次数。
                {
                    count--;
                }

                // 左指针右移
                left++;
            }
        }  

        if (minLen == INT_MAX) return ""; // 如果minLen没有更新过，说明没找到，直接返回空""
        return s.substr(start, minLen); // 用函数substr返回s中从索引start开始到minLen的子字符串


        // PS:借助ai思维，拆解，先理清宏观思路，然后拆解，反映每个变量是如何变化的，分成多个步骤，逐步填写。
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