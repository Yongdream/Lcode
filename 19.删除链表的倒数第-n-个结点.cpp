/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 该题目的 倒数第n个节点 的思想
        // 利用双指针 造成的间隔实现
        ListNode* dummy = new ListNode(0);  // 哑节点 next指向头部
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i < n + 1; ++i) {
            if (fast == nullptr) return head;
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 此时slow已经指向 倒数第n个节点（即删除节点）的前一个节点

        ListNode* toDel = slow->next;
        slow->next = slow->next->next;
        delete toDel;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
// @lc code=end

