/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) return nullptr;

        /*快慢指针法*/
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                ListNode *p1 = head, *p2 = fast; // 重新开始找
                // 循环到相同的就是入环了
                while (p1 != p2)
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p2;
            }
        }
        return nullptr;
    }
};
// @lc code=end

