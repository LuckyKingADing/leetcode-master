#include <iostream>

class Solution {
public:
    bool isPerfectSquare(int x) {
        // 请在此处实现你的代码
        // 二分查找，
        /* 完全平方数有个性质
        */
        if (x == 1) // 因为下面用到了完全平方数的平方根位于0~x/2的性质，因此这里要对1进行特殊处理，1这样不能处理。
        {   
            return true;
        }
        
        int left = 0;
        int right = x / 2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            //std::cout << std::endl;
            //std::cout << "middle " << middle;
            // 通用：防止大数溢出风险：当你写 sq == x，C++ 会把较窄的整型提升（promote）到较宽的整型再比较，所以 int x 会被提升为 long long 来与 sq 比较，比较本身是安全的。
            long long sq = 1LL * middle * middle;// 1LL等同于(long long )
            if(sq > x){ // 更进一步防止溢出的写法： if (mid != 0 && mid > x / mid)
                right = middle - 1;
               // std::cout << " right " << right;
            } else if(sq < x) { // 
                left = middle + 1;
                //std::cout << " left " << left << std::endl;
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

    // 测试 4: 大数完全平方数 2147395600 = 46340^2
    int num4 = 2147395600;
    std::cout << "Test Case 4: num = 2147395600, Result = " << (sol.isPerfectSquare(num4) ? "true" : "false") << " (Expected: true)" << std::endl;

    // 测试 5: 非完全平方数，接近 INT_MAX
    int num5 = 2147483647;
    std::cout << "Test Case 5: num = 2147483647, Result = " << (sol.isPerfectSquare(num5) ? "true" : "false") << " (Expected: false)" << std::endl;

    // 测试 6: 0
    int num6 = 0;
    std::cout << "Test Case 6: num = 0, Result = " << (sol.isPerfectSquare(num6) ? "true" : "false") << " (Expected: true)" << std::endl;

    return 0;
}