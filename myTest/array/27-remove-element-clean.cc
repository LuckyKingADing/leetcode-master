#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 请在此处实现你的代码
        // 快慢指针？slow fast
        /* 思路：
            1.slow fast = 0
            2.如果值nums[fast]!=val，则nums[slow] = nums[fast] slow++，否则slow 不加加，
            3.最后，返回的应该是slow+1？ */
        int slow = 0;
        for (int  fast = 0; fast < nums.size(); fast++)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            
        }
        // return slow  + 1; // 这里不能返回slow+1,slow是从0开始的，每找到一个不相等的就+1.那么slow就是所有的不相等的，也就是当前的新数组长度
        return slow;
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
    for (int i = 0; i < len1; i++) cout << nums1[i] << " ";
    cout << "(Expected: 2 2 )" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    cout << "Test Case 2: nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2" << endl;
    int len2 = sol.removeElement(nums2, val2);
    cout << "Result Length: " << len2 << " (Expected: 5)" << endl;
    cout << "Modified nums: ";
    for (int i = 0; i < len2; i++) cout << nums2[i] << " ";
    cout << "(Expected: 0 1 3 0 4 )" << endl;
    cout << "----------------" << endl;

    return 0;
}