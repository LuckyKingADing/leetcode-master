/* [卡码网题目链接](https://kamacoder.com/problempage.php?pid=1065)

字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

输入：输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。

输出：输出共一行，为进行了右旋转操作后的字符串。

样例输入：
2
abcdefg

样例输出：
fgabcde

数据范围：1 <= k < 10000, 1 <= s.length < 10000;

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string rightRotateString(string s, int k);

};

string Solution::rightRotateString(string s, int k) {
    
    /*  注意： 
        std::reverse(first, last) 的区间是左闭右开（[first, last)）。
        first：指向要反转范围的起始位置（包含）。
        last：指向要反转范围的结束位置（不包含）。*/

    // // 方法1：先整体再局部
    // // 整体反转
    // int len = s.size();
    // reverse(s.begin(), s.end());
    // // 反转前 k 个字符
    // reverse(s.begin(), s.begin() + k); // 翻转索引为0~k-1,也就是翻转前k个
    // // 反转后 len - k 个字符
    // reverse(s.begin() + k, s.end()); // 翻转索引为k-1 ~ len，也就是翻转剩余的len-k
    // return s;

    // 方法2：先局部再整体，也可以
    int len = s.size();
    // 错误 reverse(s.begin(), s.end() + len - k);  // 前len-k个字符进行翻转
    reverse(s.begin(), s.begin() + len - k); // 注意是s.begin()+len-k
    reverse(s.begin() + len - k, s.end()); // 后k个字符进行翻转
    reverse(s.begin(), s.end());
    return s;
    



}

int main() {
    Solution sol;

    // 测试用例 1
    string s1 = "abcdefg";
    int k1 = 2;
    string result1 = sol.rightRotateString(s1, k1);
    cout << "Test Case 1: s=\"" << s1 << "\", k=" << k1 << ", Result=\"" << result1 << "\" (Expected: \"fgabcde\")" << endl;

    return 0;
}