/* [力扣题目链接](https://leetcode.cn/problems/remove-linked-list-elements/)

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]

提示：
* 列表中的节点数目在范围 [0, 10^4] 内
* 1 <= Node.val <= 50
* 0 <= val <= 50

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
    ListNode* removeElements(ListNode* head, int val) {
        // 请在此处实现你的代码
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    // 创建链表: [1,2,6,3,4,5,6]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(6);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(4);
    head1->next->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next->next = new ListNode(6);
    int val1 = 6;
    ListNode* result1 = sol.removeElements(head1, val1);
    std::cout << "Test Case 1: val = 6, Result = ";
    while (result1) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << "(Expected: 1 2 3 4 5)" << std::endl;

    // 测试用例 2: 空链表
    ListNode* head2 = nullptr;
    int val2 = 1;
    ListNode* result2 = sol.removeElements(head2, val2);
    std::cout << "Test Case 2: val = 1, Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 3: 全是val
    ListNode* head3 = new ListNode(7);
    head3->next = new ListNode(7);
    head3->next->next = new ListNode(7);
    head3->next->next->next = new ListNode(7);
    int val3 = 7;
    ListNode* result3 = sol.removeElements(head3, val3);
    std::cout << "Test Case 3: val = 7, Result = (empty) (Expected: empty)" << std::endl;

    return 0;
}