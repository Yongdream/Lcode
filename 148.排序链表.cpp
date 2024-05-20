/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        // 并归排序
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        // 快慢指针找到链表中点，用于归并排序的分割操作
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = nullptr, * curr = nullptr;

        while (l1 && l2) {
            if (l1->val < l2->val) {    // 在merge对比两个数值 链表最先连接小的
                if (!head) {
                    head = l1;
                    curr = head;
                }
                else {
                    curr->next = l1;
                    curr = curr->next;
                }
                l1 = l1->next;
            }
            else {
                if (!head) {
                    head = l2;
                    curr = head;
                }
                else {
                    curr->next = l2;
                    curr = curr->next;
                }
                l2 = l2->next;
            }
        }

        // 连接剩余的节点
        if (l1) {
            curr->next = l1;
        }
        if (l2) {
            curr->next = l2;
        }
        return head;
    }

};
// @lc code=end

