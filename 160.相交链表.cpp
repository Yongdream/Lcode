/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *pA = headA, *pB = headB;
        while (pA != nullptr)
        {
            lenA++;
            pA = pA->next;
        }
        while (pB != nullptr)
        {
            lenB++;
            pB = pB->next;
        }
        
        pA = headA;
        pB = headB;
        // 求出两个链表长度的差值 |lenA - lenB|
        if (lenA > lenB){
            for (int i = 0; i < lenA - lenB; ++i) pA = pA->next;
        }
        else{
            for (int i = 0; i < lenB - lenA; ++i) pB = pB->next;
        }

        while (pA != nullptr && pB != nullptr)
        {
            if (pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;      
    }
};
// @lc code=end

