/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* temp = new ListNode(-1, head);
        ListNode* p1 = temp;
        ListNode* p2 = head;
        while (p2 != nullptr && p2->next != nullptr) {
            ListNode* t = p2->next->next;
            p1->next = p2->next;
            p2->next->next = p2;
            p2->next = t;
            p1 = p1->next->next;
            p2 = p2->next;
        }
        return temp->next;



    }
};
// @lc code=end

