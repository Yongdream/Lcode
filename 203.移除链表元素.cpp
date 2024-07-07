/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* nohead = head;
        while (nohead != NULL && nohead->next != NULL)
        {
            if (nohead->next->val == val){
                ListNode* temp = nohead->next;
                nohead->next = nohead->next->next;
                delete temp;
            }
            else{
                nohead = nohead->next;
            }
        }
        return head;
    }
};
// @lc code=end

