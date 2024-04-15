/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *res = new ListNode(-1);
       ListNode *cur = res;
       ListNode *del = cur;
       int carry = 0;

       while (l1 || l2)
       {
            int sum = (l1 != nullptr? l1->val : 0 ) + (l2 != nullptr? l2->val : 0) + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
       }
       if (carry) cur->next = new ListNode(1);
       return res->next;
       free(del);
    }
};
// @lc code=end

