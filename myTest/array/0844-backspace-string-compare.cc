/* [力扣题目链接](https://leetcode.cn/problems/backspace-string-compare/)

给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

示例 2：
输入：s = "ab##", t = "c#d#"
输出：true
解释：s 和 t 都会变成 ""。

示例 3：
输入：s = "a#c", t = "b"
输出：false
解释：s 变成 "c"，但 t 变成 "b"。

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 1.解法1的：助手函数：模拟退格过程，构建最终显示的字符串
    string build(string str) {
        string res = ""; // 初始化定义空字符串
        for (char c : str) { //遍历
            if (c != '#') {
                res += c; // 普通字符，入栈（放入字符串末尾）
            } else if (!res.empty()) { // 包含两个条件：c == '#'以及!res.empty()
                res.pop_back(); // 退格，且当前不为空，就弹出最后一个字符
            }
        }
        return res;
    }

    // 2. 解法2：双指针法：定义j为str的末尾索引，从后往前遍历，遇到#，则skip++，j--，遇到普通字符，如果skip>0，说明要减少，j--，返回最终处理完毕的字符串
    int getNextValidIndex(const string& str, int index) {
        int skip = 0;
        while (index >= 0) {
            if (str[index] == '#') {
                skip++;
                index--;
            } else if (skip > 0) { // 发现字符，但手里的名额能把它抵消掉
                skip--;
                index--;
            } else {
                break; // 发现字符，且手里没名额了，这正是我们要找的“幸存者”
            }
        }
        return index;  // 返回这个幸存者的位置
    }
    /* PS:从前往后看：你看到打了一个 a，你不能确定这个 a 最后会不会出现在屏幕上，因为你不知道后面会不会紧跟着来一个退格键 # 把它的位置顶掉。从后往前看：如果你先看到了一个退格键 #，你就知道：“注意了！接下来左边出现的第 1 个字符，肯定是倒霉蛋，它会被删掉，不用管它。”


    */
    
    // 这个题完全借助ai的，后续需要重新打一遍
    // 助手函数：寻找字符串中从 index 开始往前的第一个真正“存活”的字符下标
    bool backspaceCompare(string s, string t) {
        // 1. 解法1：空间换时间
        // 将 s 和 t 分别转化为处理退格后的最终字符串，然后再比较
        // return build(s) == build(t);

        // 2. 解法双指针：逆向双指针
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (i >= 0 || j >= 0) {
            // 1. 分别找到 s 和 t 中下一个“存活”的字符下标
            i = getNextValidIndex(s, i);
            j = getNextValidIndex(t, j);

            // 2. 比较这两个字符:两个都有幸存者，那就比一下这两个字母一不一样。不一样就直接 false。
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else { // 这里else条件有：i<0或者j<0
                // 如果其中一个走完了（比如 i < 0），而另一个还有幸存者（j >= 0）： 
                // 如果其中一个走完了，另一个还没走完，说明最后肯定不相等
                if (i >= 0 || j >= 0) return false;
            }
            // 这里是对这两个字符串进行逐个字符进行比对
            i--;
            j--;
        }
        // 如果都走完了（i < 0 且 j < 0）：说明前面的比对都一样，且最后大家都变空了。返回 true。
        return true;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "ab#c", t1 = "ad#c";
    cout << "Test Case 1: s = \"ab#c\", t = \"ad#c\"" << endl;
    cout << "Result: " << (sol.backspaceCompare(s1, t1) ? "true" : "false") << " (Expected: true)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    string s2 = "ab##", t2 = "c#d#";
    cout << "Test Case 2: s = \"ab##\", t = \"c#d#\"" << endl;
    cout << "Result: " << (sol.backspaceCompare(s2, t2) ? "true" : "false") << " (Expected: true)" << endl;
    cout << "----------------" << endl;

    // 测试用例 3
    string s3 = "a#c", t3 = "b";
    cout << "Test Case 3: s = \"a#c\", t = \"b\"" << endl;
    cout << "Result: " << (sol.backspaceCompare(s3, t3) ? "true" : "false") << " (Expected: false)" << endl;
    cout << "----------------" << endl;

    return 0;
}