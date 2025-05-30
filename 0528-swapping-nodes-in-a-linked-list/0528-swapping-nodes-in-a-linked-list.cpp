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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* front = head;
        for(int i =1;i<k;i++) {
            front  = front->next;
        }
        ListNode*slow=head;
        ListNode*fast = front;

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        int temp = front->val;
        front ->val = slow->val;
        slow->val = temp;

        return head;
    }
    
};