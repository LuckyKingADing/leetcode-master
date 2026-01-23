#include <iostream>

/* https://leetcode.cn/problems/valid-perfect-square/description/
https://programmercarl.com/0367.%E6%9C%89%E6%95%88%E7%9A%84%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html

给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
... (内容省略) ...
*/









class Solution {
public:
    // 补充，函数命名方式，小驼峰！！！
    bool isPerfectSquare(int x) {
        // 二分查找

        // 之前的left和right定义
        // int left = 1; //  补充：题目说是正整数，从1开始即可，从0开始也是能跑通的
        // int right = x;

        /* 补充：
        处理了 num < 2（即 num = 1）的特殊情况。
        对于 num >= 2，将 right 的初始值设为 num / 2。因为当 n ≥ 2 时，n≤n/2 恒成立，这可以缩小二分查找的初始搜索范围*/
        // 因此代码可以修改为：
        if (x == 1) {return true;}
        int left = 1;
        int right = x / 2; // 优化：num > 1 时，其平方根一定小于等于 num / 2

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            long long square = (long long)middle * middle;// 补充：long long square = (long long)mid * mid; // 提取出来写更清晰
            if (square > x)
            {
                right = middle - 1;
            } else if (square < x)
            {
                left = middle + 1;
            } else {
                return true;
            }
        }
        return false;
    }    
};

int main() {
    Solution sol;
    
    // 测试 1
    int num1 = 16;
    std::cout << "Test Case 1: num = 16, Result = " << (sol.isPerfectSquare(num1) ? "true" : "false") << " (Expected: true)" << std::endl;

    // 测试 2
    int num2 = 14;
    std::cout << "Test Case 2: num = 14, Result = " << (sol.isPerfectSquare(num2) ? "true" : "false") << " (Expected: false)" << std::endl;

    // 测试 3
    int num3 = 1;
    std::cout << "Test Case 3: num = 1, Result = " << (sol.isPerfectSquare(num3) ? "true" : "false") << " (Expected: true)" << std::endl;

    return 0;
}