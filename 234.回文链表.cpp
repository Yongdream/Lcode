/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    // 反转链表的函数
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转链表的后半部分
        ListNode* secondHalf = reverseList(slow->next);
        
        // slow是中点，所以比较前半部分和反转后的后半部分是否相同
        ListNode* firstHalf = head;
        bool isPalindrome = true;
        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // 恢复链表的后半部分（如果之前被反转了）
        if (slow->next != nullptr) {
            slow->next = reverseList(slow->next);
        }

        return isPalindrome;
    }
};
// @lc code=end

