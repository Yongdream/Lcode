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
        // 头节点和非头节点的移除是有区别
        // 如果使用虚拟头节点 就可以用统一的删除方法 

        // 使用while持续移除      
        while (head != NULL && head->val == val)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // 理解curr->是要被删除的node
        // 前后节点都要考虑
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
// @lc code=end

