/* [力扣题目链接](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

给你一个 
升序
排列 
的数组 nums ，请你 
原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。

元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]

示例 2：
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]

// 思考
升序 原地删除重复 返回删除后数组的新长度，即唯一元素的个数
双指针思路：升序！
slow=0 
result=0
for (fast =1 ;fast<n;fast ++ )
    if nums[fast] == nums[slow]
        slow++;
    else // 不相等的话，不用动阿
        if(fast >= 2) {
            nums[slow] = nums[fast];
        }
        result++;


return result;

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 请在此处实现你的代码
        // 双指针法
        // 1.自己写的，有点问题
        // int slow = 0; 
        // int result = 0;
        // for (int fast = 1 ;fast < nums.size(); fast++) {
        //     if (nums[fast] == nums[slow]) {
        //         slow++;
        //     } else {
        //         if(fast >= 2) {
        //             nums[slow] = nums[fast];
        //         }
        //         result++;
        //     }
        // }
        // return result;

        // 2.再次写，其实就是把前几个元素填充成不一样的几个元素就行了，其他的不用管
        int slow = 0;
            // 补充，加一个保护逻辑，处理空数组
        if (nums.size() == 0) return 0; // 处理空数组
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]){
                slow++;
                nums[slow] = nums[fast];
            }
        }
        // 返回长度。由于 slow 是下标，长度 = 下标 + 1
        return slow + 1;


    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {1, 1, 2};
    cout << "Test Case 1: nums = [1, 1, 2]" << endl;
    int len1 = sol.removeDuplicates(nums1);
    cout << "Result Length: " << len1 << " (Expected: 2)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len1; i++) cout << nums1[i] << " ";
    cout << "(Expected: 1 2)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << "Test Case 2: nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]" << endl;
    int len2 = sol.removeDuplicates(nums2);
    cout << "Result Length: " << len2 << " (Expected: 5)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len2; i++) cout << nums2[i] << " ";
    cout << "(Expected: 0 1 2 3 4)" << endl;
    cout << "----------------" << endl;

    return 0;
}