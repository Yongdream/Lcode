/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; ++i) prev = prev->next; // 定位到left前一个
        
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i)
        {
            ListNode* next = curr->next;

            curr->next = next->next;
            next->next = prev->next; 
            // 1：13245 2：14325
            // 如果next->next = curr; 3在第二轮时候会被排除
            // 末尾的数字一定是要在prev之后，prev->next不一定是curr
            prev->next = next;
        }
        /**
         * 节点断开 a->next = b->next
         * 节点合并 a->next = b
        */
        ListNode* newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};
// @lc code=end

