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
    
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* curr = dummyHead;
        while(curr->next != NULL){
            if (curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
// @lc code=end

