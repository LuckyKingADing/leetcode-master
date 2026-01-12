/* https://leetcode.cn/problems/sqrtx/description/

给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
输入：x = 4
输出：2

示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

草稿：x，返回他的算术平方根的整数部分

*/

#include <iostream>

class Solution {
    public:
    int sqrtx(int x) {
        // 二分查找
        int left = 0;
        int right = x;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            // 补充：当 middle 比较大时，middle * middle 会超出 int 的范围（比如 x 为最大值时，middle 约为 46340，平方还在 int 内，但再大一点就会溢出变成负数）。
            // 解决方法：将 middle 强转为 long long 再进行平方比较，即 (long long)middle * middle
            if ((long long)middle * middle > x)        
            {
                right = middle - 1;
            } else if ((long long )middle * middle < x)
            {
                left = middle + 1;
            } // 补充相等的情况
            else {
                return middle;
            }
        }
        // 补充，如果不确定返回谁，则用一个简单的例子 模拟一下，比如输入的时8，返回的是2,看最终left和right谁等于2;最终应该是输出right，因为终止条件是是left>right,right小于left 1,应该是right才对，因为是向下取整
        return right;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    int x1 = 4;
    std::cout << "Test Case 1: x = 4, Result = " << sol.sqrtx(x1) << " (Expected: 2)" << std::endl;

    // 测试用例 2
    int x2 = 8;
    std::cout << "Test Case 2: x = 8, Result = " << sol.sqrtx(x2) << " (Expected: 2)" << std::endl;

    // 测试用例 3: 较大数值
    int x3 = 2147395600; // sqrt(2147395600) = 46340
    std::cout << "Test Case 3: x = 2147395600, Result = " << sol.sqrtx(x3) << " (Expected: 46340)" << std::endl;

    return 0;
}