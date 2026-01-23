/* [力扣题目链接](https://leetcode.cn/problems/remove-element/)

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并**原地**修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:
给定 nums = [3,2,2,3], val = 3,
函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
你不需要考虑数组中超出新长度后面的元素。

示例 2:
给定 nums = [0,1,2,2,3,0,4,2], val = 2,
函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

**你不需要考虑数组中超出新长度后面的元素。** 

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 要求：给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
        // 1.暴力解法：如果nums[i]等于val，就将其之后的所有元素全部覆盖上来
        // 错误的暴力解法
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == val)      
        //     {
        //         for (int j = i; j < n; j++)
        //         {
        //             // 补充，这样写会导致数组下标越界，会访问nums[n]
        //             // nums[j] = nums[j + 1];
        //         }

        //     }
            
        // }

        // 补充：问题，未更新数组新长度，且没有返回移除后的新长度；
        // 重写暴力解法
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == val) {
        //         // 将 i 之后的所有元素往前挪一位
        //         for (int j = i; j < n - 1; j++){
        //            nums[j] = nums[j + 1];
        //         }
        //         // 另一种写法：推荐上面，更直观
        //         // for (int j = i + 1; j < n; j++) { nums[j-1] = nums[j]; }
        //         i--; // 【关键】下标回退一位，下次循环检查新挪过来的元素
        //         n--; // 【关键】逻辑长度减一
                
        //     }
            
        // }
        // return n;

        // 2.双指针法：快慢指针，慢指针指向两者相等的初始位置，快指针不停，继续搜索索引，
        int n = nums.size();
        // 错误写法，还是没有完全理解
        // int fast = 0;
        // for (int slow = 0; slow < n; slow++){
        //     if (nums[slow] == val) {
        //         nums[slow] = nums[fast];
        //     }
        //     fast++;
        //     n--;
        // }
        // return n;

        //再次尝试
        int slow = 0;
        for (int  fast = 0; fast < n; fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                // n--; // 不需要n--,且就算写了也是不对的，逻辑错误
                slow++;
            }
           // slow++; 不能写在这里，相等的时候不能++，不相等才能++

           // 
            
        }
        // return n; // 错误
        // 返回 slow 
        return slow;

        /* 重新拆解逻辑：
            快指针：不管三七二十一，从头走到尾，负责看每一个元素。
            判断：如果快指针看到的元素 不是 val，说明这个元素是我们要保留的。
            搬运：把快指针看到的这个“好元素”丢给慢指针所在的位置。
            慢指针：每接收到一个好元素，就往后挪一步，为下一个好元素腾位置。 */
                    
        return 0;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    cout << "Test Case 1: nums = [3, 2, 2, 3], val = 3" << endl;
    int len1 = sol.removeElement(nums1, val1);
    cout << "Result Length: " << len1 << " (Expected: 2)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << " ";
    }
    cout << " (Expected: 2 2 )" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    cout << "Test Case 2: nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2" << endl;
    int len2 = sol.removeElement(nums2, val2);
    cout << "Result Length: " << len2 << " (Expected: 5)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << " ";
    }
    cout << " (Expected: 0 1 3 0 4 )" << endl;
    cout << "----------------" << endl;

    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    int val3 = 0;
    cout << "Test Case 3: nums = [], val = 0" << endl;
    int len3 = sol.removeElement(nums3, val3);
    cout << "Result Length: " << len3 << " (Expected: 0)" << endl;
    cout << "----------------" << endl;

    return 0;
}

