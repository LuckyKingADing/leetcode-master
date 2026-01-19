#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 二刷20260119
        // 又不知道啥思路了。。。  
        // 双指针法？
        // 1.slow fast
        // 2.fast先移动，如果nums[fast] != nums[slow]了，那么slow就更新到fast这里来，否则不更新，然后把这个值赋值给数组第二个值，

        // 双指针法

        // 补充：更完善，处理空数组
        if (nums.empty()) return 0;  // 处理空数组

        int n = nums.size();
        int slow = 0;
        int index = 1;
        for (int fast = 0; fast < n; fast++)
        {
            if (nums[fast] != nums[slow])
            {
                nums[index] = nums[fast];
                index++;
                slow = fast;
            }
            
        }
        return index;

        // 又写错了！！！为什么？



        // 这是正确的：
        // int slow = 0;
        // for (int  fast = 0; fast < nums.size(); fast++)
        // {
        //     /* code */
        //     if (nums[fast] != nums[slow])
        //     {
        //         ++slow;
        //         nums[slow] = nums[fast];
        //     }
            
        // }

        //  // 可选(不是必须的，没有也没关系？)：清空后面元素
        // for (int i = slow + 1; i < nums.size(); ++i) {
        //     nums[i] = 0;  // 或其他值
        // }

        // return slow + 1;
        
        
        
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

    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    cout << "Test Case 3: nums = []" << endl;
    int len3 = sol.removeDuplicates(nums3);
    cout << "Result Length: " << len3 << " (Expected: 0)" << endl;
    cout << "Modified nums: (empty)" << endl;
    cout << "(Expected: empty)" << endl;
    cout << "----------------" << endl;

    // 测试用例 4: 单个元素
    vector<int> nums4 = {5};
    cout << "Test Case 4: nums = [5]" << endl;
    int len4 = sol.removeDuplicates(nums4);
    cout << "Result Length: " << len4 << " (Expected: 1)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len4; i++) cout << nums4[i] << " ";
    cout << "(Expected: 5)" << endl;
    cout << "----------------" << endl;

    // 测试用例 5: 所有元素相同
    vector<int> nums5 = {1, 1, 1, 1};
    cout << "Test Case 5: nums = [1, 1, 1, 1]" << endl;
    int len5 = sol.removeDuplicates(nums5);
    cout << "Result Length: " << len5 << " (Expected: 1)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len5; i++) cout << nums5[i] << " ";
    cout << "(Expected: 1)" << endl;
    cout << "----------------" << endl;

    // 测试用例 6: 多个重复但有不同
    vector<int> nums6 = {1, 1, 1, 2};
    cout << "Test Case 6: nums = [1, 1, 1, 2]" << endl;
    int len6 = sol.removeDuplicates(nums6);
    cout << "Result Length: " << len6 << " (Expected: 2)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len6; i++) cout << nums6[i] << " ";
    cout << "(Expected: 1 2)" << endl;
    cout << "----------------" << endl;

    // 测试用例 7: 递增无重复
    vector<int> nums7 = {1, 2, 3, 4};
    cout << "Test Case 7: nums = [1, 2, 3, 4]" << endl;
    int len7 = sol.removeDuplicates(nums7);
    cout << "Result Length: " << len7 << " (Expected: 4)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len7; i++) cout << nums7[i] << " ";
    cout << "(Expected: 1 2 3 4)" << endl;
    cout << "----------------" << endl;

    return 0;
}