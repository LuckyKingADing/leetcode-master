/* [力扣题目链接](https://leetcode.cn/problems/happy-number/)

编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：
输入：19
输出：true
解释：
1^2 + 9^2 = 1 + 81 = 82
8^2 + 2^2 = 64 + 4 = 68
6^2 + 8^2 = 36 + 64 = 100
1^2 + 0^2 + 0^2 = 1 + 0 + 0 = 1

*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n);
};

int main() {
    Solution sol;

    // 测试用例 1
    int n1 = 19;
    bool result1 = sol.isHappy(n1);
    cout << "Test Case 1: n=19, Result = " << (result1 ? "true" : "false") << " (Expected: true)" << endl;

    // 测试用例 2
    int n2 = 2;
    bool result2 = sol.isHappy(n2);
    cout << "Test Case 2: n=2, Result = " << (result2 ? "true" : "false") << " (Expected: false)" << endl;

    // 测试用例 3
    int n3 = 1;
    bool result3 = sol.isHappy(n3);
    cout << "Test Case 3: n=1, Result = " << (result3 ? "true" : "false") << " (Expected: true)" << endl;

    return 0;
}