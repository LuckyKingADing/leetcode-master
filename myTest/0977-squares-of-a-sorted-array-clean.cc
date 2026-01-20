#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 思路1:先平方后sort排序
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     nums[i] = nums[i] * nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // return nums;

        // 思路2：双指针法，降低复杂度，
        // 原理：两边的平方大于中间的？向中间靠拢？比较两端的，谁大就放后面？
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size() - 1;

        // 补充：好吧，这里调用了一个新的容器来写入值
        vector<int> result(n + 1 ); // 注意！要先初始化大小才行，注意这里是n+1，因为上面的n减去了1
        while (left <= right)
        {
            if (nums[left] * nums[left] >= nums[right] * nums[right])
            {
               result[n] = nums[left] * nums[left];
               // right--; // 不是right -- 
                left++; // 因为要继续下一个left
               n--;
            } else { // nums[left] * nums[left] < nums[right] * nums[right]
                result[n] = nums[right] * nums[right];
                // left++; // 不是left++
                right--; // 因为要继续下一个right
                n--;
            }
        }
        
        return result;

    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    cout << "Test Case 1: nums = [-4, -1, 0, 3, 10]" << endl;
    vector<int> res1 = sol.sortedSquares(nums1);
    cout << "Result: ";
    for (int x : res1) cout << x << " ";
    cout << "(Expected: 0 1 9 16 100)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    cout << "Test Case 2: nums = [-7, -3, 2, 3, 11]" << endl;
    vector<int> res2 = sol.sortedSquares(nums2);
    cout << "Result: ";
    for (int x : res2) cout << x << " ";
    cout << "(Expected: 4 9 9 49 121)" << endl;
    cout << "----------------" << endl;

    return 0;
}