#include <iostream>

class Solution {
    public:
    int sqrtx(int x) {
        // 请在此处实现你的代码
        // 二分查找
        int left = 0;
        int right = x;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            long long square = (long long)middle * middle; // (long long)强制将其转为long long数据类型，否则，如果遇到大数就不行了,避免溢出

            if (square > x)
            {
                right = middle - 1;
            } else if (square < x)
            {
                left = middle +1;
            }
            else{
                return middle;
            }
            
        }
        // return left; // 错误，这里容易错，因为while终止的条件是left > right 1,也就是right小于left = left -1,所以应该返回right
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