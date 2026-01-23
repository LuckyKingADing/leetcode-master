#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 请在此处实现你的代码
        // 示例 1:
        // 输入: nums = [0,1,0,3,12]
        // 输出: [1,3,12,0,0]
        // 示例 2:
        // 输入: nums = [0]
        // 输出: [0]

        // 双指针法 从后往前？
        // (优先使用，比较难想)思路1：精简模式，使用swap交换，直接交换0和另外一个非零的数组元素，进行值交换,将0滚到后面
        // 补充：size_t 是一个无符号整数类型（通常写作 std::size_t），用于表示对象大小和容器的长度。常见要点：用途：sizeof 的返回类型、vector::size() / string::size() 的类型等；
        //这里用size_t代替int 都一样，但是ai说当前用 int n 和 int fast 但 nums.size() 返回 size_t，会产生有符号/无符号比较警告。
        // size_t slow = 0;
        // size_t n = nums.size();
        // for (size_t fast = 0; fast < n; ++fast)
        // {
        //     if (nums[fast] != 0) // nums[fast]不为0，则滚动处理
        //     {
        //         swap(nums[slow], nums[fast]);
        //         slow++;
        //     }
        // }
        // 该函数不返回任何值


        // 思路2：先把为0的填充调，然后记录0出现的次数，再把后面的替换为0。
        int slow = 0;
        int n = nums.size();
        int zeroNums = 0;
        for (int  fast = 0; fast < n; fast++) {
            if (nums[fast] != 0) {
                nums[slow] = nums[fast]; // 这里是=，不是==
                slow++;
            } else { // 等于0,才加
                zeroNums++;
            }
        }
        for (int i = 0; i < zeroNums; i++) { // nums的最后zeroNums设置为0
            nums[n - i -1] = 0;
            // i =0  nums[n -1]（就是最后一个元素） i =1 nums[n-2]到数第二个  i=2 依次类推
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

    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    cout << "Test Case 3: nums = []" << endl;
    sol.moveZeroes(nums3);
    cout << "Modified nums: ";
    for (int x : nums3) cout << x << " ";
    cout << "(Expected: )" << endl;
    cout << "----------------" << endl;

    // 测试用例 4: 全为零
    vector<int> nums4 = {0, 0, 0, 0};
    cout << "Test Case 4: nums = [0, 0, 0, 0]" << endl;
    sol.moveZeroes(nums4);
    cout << "Modified nums: ";
    for (int x : nums4) cout << x << " ";
    cout << "(Expected: 0 0 0 0)" << endl;
    cout << "----------------" << endl;

    // 测试用例 5: 没有零
    vector<int> nums5 = {1, 2, 3, 4};
    cout << "Test Case 5: nums = [1, 2, 3, 4]" << endl;
    sol.moveZeroes(nums5);
    cout << "Modified nums: ";
    for (int x : nums5) cout << x << " ";
    cout << "(Expected: 1 2 3 4)" << endl;
    cout << "----------------" << endl;

    // 测试用例 6: 混合
    vector<int> nums6 = {0, 0, 1, 0, 2, 0, 3};
    cout << "Test Case 6: nums = [0,0,1,0,2,0,3]" << endl;
    sol.moveZeroes(nums6);
    cout << "Modified nums: ";
    for (int x : nums6) cout << x << " ";
    cout << "(Expected: 1 2 3 0 0 0 0)" << endl;
    cout << "----------------" << endl;

    // 测试用例 7: 已经有序（零在末尾）
    vector<int> nums7 = {1, 2, 3, 0, 0};
    cout << "Test Case 7: nums = [1,2,3,0,0]" << endl;
    sol.moveZeroes(nums7);
    cout << "Modified nums: ";
    for (int x : nums7) cout << x << " ";
    cout << "(Expected: 1 2 3 0 0)" << endl;
    cout << "----------------" << endl;

    // 测试用例 8: 单个非零
    vector<int> nums8 = {5};
    cout << "Test Case 8: nums = [5]" << endl;
    sol.moveZeroes(nums8);
    cout << "Modified nums: ";
    for (int x : nums8) cout << x << " ";
    cout << "(Expected: 5)" << endl;
    cout << "----------------" << endl;

    return 0;
}