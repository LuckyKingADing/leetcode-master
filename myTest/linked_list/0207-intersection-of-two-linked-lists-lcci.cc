/* [力扣题目链接](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/)

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：

题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

自定义评测：

评测系统 的输入如下（你设计的程序 不适用 此输入）：

intersectVal - 相交的起始节点的值。如果没有相交节点，这一值为 0
listA - 第一个链表
listB - 第二个链表
skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
如果没有交点，intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这些输入只用于自定义测试。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'

示例 2：
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'

示例 3：
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：No intersection

提示：
* listA 中节点数目为 m
* listB 中节点数目为 n
* 1 <= m, n <= 3 * 10^4
* 1 <= Node.val <= 10^5
* 0 <= skipA <= m
* 0 <= skipB <= n
* 如果 listA 和 listB 没有交点，intersectVal 为 0
* 如果 listA 和 listB 有交点，intersectVal == listA[skipA] == listB[skipB]

进阶：你能否设计一个时间复杂度 O(m + n) 并且只使用 O(1) 内存的解决方案？

*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 请在此处实现你的代码
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1: 有交点
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* result1 = sol.getIntersectionNode(headA, headB);
    if (result1) {
        std::cout << "Test Case 1: Intersected at " << result1->val << " (Expected: 8)" << std::endl;
    } else {
        std::cout << "Test Case 1: No intersection (Expected: 8)" << std::endl;
    }

    // 测试用例 2: 无交点
    ListNode* headA2 = new ListNode(2);
    headA2->next = new ListNode(6);
    headA2->next->next = new ListNode(4);

    ListNode* headB2 = new ListNode(1);
    headB2->next = new ListNode(5);

    ListNode* result2 = sol.getIntersectionNode(headA2, headB2);
    if (result2) {
        std::cout << "Test Case 2: Intersected at " << result2->val << " (Expected: No intersection)" << std::endl;
    } else {
        std::cout << "Test Case 2: No intersection (Expected: No intersection)" << std::endl;
    }

    return 0;
}