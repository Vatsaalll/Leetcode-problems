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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        // Check if there are at least k nodes left
        while (curr != nullptr && count < k) {
            curr = curr->next;
            count++;
        }
        // If there are k nodes, then reverse them
        if (count == k) {
            ListNode* next = nullptr;
            ListNode* curr = head;
            ListNode* prev = nullptr;
            count = 0;
            while (count < k) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                count++;
            }
            // Now head is the tail of the reversed group
            // Recursively reverse the next k-group and link it to the current tail
            head->next = reverseKGroup(curr, k);
            return prev;
        } else {
            // If there are fewer than k nodes, return head without reversing
            return head;
        }
    }
};