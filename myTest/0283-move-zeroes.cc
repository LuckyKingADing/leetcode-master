/* [力扣题目链接](https://leetcode.cn/problems/move-zeroes/)

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在原数组上操作，不能拷贝额外的数组。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 请在此处实现你的代码
        // 双指针法：
        // 1. 自己尝试实现的代码部分，O(n)时间复杂度，O(1)空间复杂度
        // int slow = 0;
        // int n = nums.size(); // 如果n要用于for中的循环结束条件，应该为nums.size()，而不是nums.size()-1，因为for中是<而不是<=
        // int zeroNum = 0;
        // for (int fast = 0; fast < n; fast++) {
        //     if (nums[fast] != 0) {
        //         nums[slow] = nums[fast];
        //         slow++;
        //     } else{
        //         zeroNum++;
        //     }
        // }
        // for (int i = 0; i < zeroNum; i++)
        // {
        //     nums[n - i - 1] = 0;
        // }
        // 逻辑优化：简化补零过程：在你原本的代码中，你通过 zeroNum 统计了 0 的个数，然后再从数组末尾向前填充。其实可以更自然一点：既然 slow 指针最后停留的位置就是所有非零元素填充完后的下一个位置，那么从 slow 开始到数组结束的所有位置，直接填 0 即可。这样就不需要额外维护一个 zeroNum 变量。
        // 即：for(int i = slow ... )

        // 代码进一步优化，ai提供
        /* 1. 可以利用“交换”的思想。当我们发现一个非零元素时，直接把它和 slow 指向的位置（通常是一个 0）进行交换。
            2. 只有一次遍历：不需要第二个循环来补零。
代码极其简洁：利用了 0 本身就在数组里的特性，通过交换把它们“踢”到后面。*/
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) 
        {
            if (nums[fast] != 0) {
                // swap函数是关键，直接替换，
                // swap函数进行左右两边替换，逐渐把0放到后面去；
                // 类似于滚雪球一样把0一步步滚到后面去，有点意思的
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {0, 1, 0, 3, 12};
    cout << "Test Case 1: nums = [0, 1, 0, 3, 12]" << endl;
    sol.moveZeroes(nums1);
    cout << "Modified nums: ";
    for (int x : nums1) cout << x << " ";
    cout << "(Expected: 1 3 12 0 0)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {0};
    cout << "Test Case 2: nums = [0]" << endl;
    sol.moveZeroes(nums2);
    cout << "Modified nums: ";
    for (int x : nums2) cout << x << " ";
    cout << "(Expected: 0)" << endl;
    cout << "----------------" << endl;

    return 0;
}