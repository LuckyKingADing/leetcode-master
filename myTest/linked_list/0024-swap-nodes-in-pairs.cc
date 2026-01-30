/* [力扣题目链接](https://leetcode.cn/problems/swap-nodes-in-pairs/)

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

示例 3：
输入：head = [1]
输出：[1]

提示：
* 链表中节点的数目在范围 [0, 100] 内
* 0 <= Node.val <= 100

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点
        dummyHead->next = head; //初始化虚拟头节点指向头节点
        ListNode* cur = dummyHead; // 当前节点从虚拟节点开始，方便控制head头节点
        while(cur->next != NULL && cur->next->next != NULL) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;

            cur = cur->next->next; // 移动两位，进行下一轮
        }

        ListNode* resultHead = dummyHead->next;
        delete dummyHead;
        return resultHead;
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    ListNode* result1 = sol.swapPairs(head1);
    std::cout << "Test Case 1: Result = ";
    while (result1) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << "(Expected: 2 1 4 3)" << std::endl;

    // 测试用例 2: 空链表
    ListNode* head2 = nullptr;
    ListNode* result2 = sol.swapPairs(head2);
    std::cout << "Test Case 2: Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 3: 单个节点
    ListNode* head3 = new ListNode(1);
    ListNode* result3 = sol.swapPairs(head3);
    std::cout << "Test Case 3: Result = ";
    while (result3) {
        std::cout << result3->val << " ";
        result3 = result3->next;
    }
    std::cout << "(Expected: 1)" << std::endl;

    return 0;
}