/* [力扣题目链接](https://leetcode.cn/problems/reverse-linked-list/)

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]

提示：
* 链表中节点的数目范围是 [0, 5000]
* -5000 <= Node.val <= 5000

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 请在此处实现你的代码
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* result1 = sol.reverseList(head1);
    std::cout << "Test Case 1: Result = ";
    while (result1) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << "(Expected: 5 4 3 2 1)" << std::endl;

    // 测试用例 2
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    ListNode* result2 = sol.reverseList(head2);
    std::cout << "Test Case 2: Result = ";
    while (result2) {
        std::cout << result2->val << " ";
        result2 = result2->next;
    }
    std::cout << "(Expected: 2 1)" << std::endl;

    // 测试用例 3: 空链表
    ListNode* head3 = nullptr;
    ListNode* result3 = sol.reverseList(head3);
    std::cout << "Test Case 3: Result = (empty) (Expected: empty)" << std::endl;

    return 0;
}