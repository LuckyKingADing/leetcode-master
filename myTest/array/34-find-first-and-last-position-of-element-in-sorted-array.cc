/* https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？
因为要求时间复杂度了，所以必须要使用二分查找，暴力查找是n^2的时间复杂度，因此不满足条件。

示例 1：
    输入：nums = [5,7,7,8,8,10], target = 8
    输出：[3,4]

示例 2：
    输入：nums = [5,7,7,8,8,10], target = 6
    输出：[-1,-1]

示例 3：
    输入：nums = [], target = 0
    输出：[-1,-1]

*/

#include <iostream>
#include <vector>
using namespace std; // 否则直接使用vector会直接报错，不加这一行代码需要使用std::vector;不过不推荐在大型项目中使用using namespace std，但是刷题很方便。
class Solution {
public:
    vector<int> findFirstAndLastPositionOfElementInSortedArray(vector<int>& nums, int target){

    
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        
        return {leftBorder, rightBorder}; // 补充，返回的是个vector向量，因此需要{left.., right..}，而不是[]，注意括号的区别
        
    }

    // 找左边界,[]
    int getLeftBorder(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        // 补充，记录最近一次找到的左边界的位置;让左右边界的值等于-1其实可以直接不用在主函数中加判断条件，
        int leftBorder = -1;

        while (left <= right) // 结束条件：left>right
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            } else if (nums[middle] < target)
            {
                left = middle + 1;
            } else { // 补充：当 nums[middle] == target 时，你不能直接返回，而是要继续向左收缩范围。
                leftBorder = middle;
                right = middle -1 ;// 要继续向左查找，而不是直接返回，因为当前找的不一定是最左边的边界
            }
        }
        return leftBorder; // PS：这个代码还是很清晰的

        /* 补充，这样模拟不太对，因为题目问的是target在数组中的位置，而不是应该插入哪个位置
            模拟： 
            [-2, 1, 3, 4, 7, 10]  5
            l0 r5 m2 n2=3 <5 l1
            l1 r5 m3 n3=4 < 5 l2
            l2 r5 m3 n3=4 <5 l3
            l3 r5 m4 n4=7 >5 r4
            l3 r4 m3 n3=4 <5 l4
            l4 r4 m4 n4=7 >5 r3 结束循环，l=4 r=3，左边界应该返回4,也就是返回l；右边界应该返回5？也就是left+1?
        */
    }

    // 找右边界,[]
    int getRightBorder(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int rightBorder = -1; // 补充，定义右边界

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle - 1;
            } else if (nums[middle] < target)
            {
                left = middle + 1;
            } else { // 
                rightBorder = middle;
                left = middle + 1; // 继续向右查找
            }
            
        }

        return rightBorder;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> res1 = sol.findFirstAndLastPositionOfElementInSortedArray(nums1, target1);
    cout << "Test Case 1: [5,7,7,8,8,10], target = 8, Result = [" << res1[0] << ", " << res1[1] << "] (Expected: [3, 4])" << endl;

    // 测试用例 2
    int target2 = 6;
    vector<int> res2 = sol.findFirstAndLastPositionOfElementInSortedArray(nums1, target2);
    cout << "Test Case 2: [5,7,7,8,8,10], target = 6, Result = [" << res2[0] << ", " << res2[1] << "] (Expected: [-1, -1])" << endl;

    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> res3 = sol.findFirstAndLastPositionOfElementInSortedArray(nums3, target3);
    cout << "Test Case 3: [], target = 0, Result = [" << res3[0] << ", " << res3[1] << "] (Expected: [-1, -1])" << endl;

    // 测试用例 4: 全是相同元素
    vector<int> nums4 = {2, 2, 2, 2};
    int target4 = 2;
    vector<int> res4 = sol.findFirstAndLastPositionOfElementInSortedArray(nums4, target4);
    cout << "Test Case 4: [2, 2, 2, 2], target = 2, Result = [" << res4[0] << ", " << res4[1] << "] (Expected: [0, 3])" << endl;

    return 0;
}