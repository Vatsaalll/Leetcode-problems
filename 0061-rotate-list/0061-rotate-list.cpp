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
    ListNode* rotateRight(ListNode* head, int k) {
        int l = 0;
        ListNode* temp = head;
        if(head==NULL || head->next==NULL || k==0) return head;

        
        

        while(temp!=NULL) {
            l++;
            temp = temp->next;

        }

        k = k % l;
        if(k==0) return head;


        int traverse = l-k;
        temp = head;
        for(int  i=1; i<traverse;i++) {
            temp = temp->next;
        }
        ListNode* temp2 = temp;
        ListNode* newhead = temp->next;
        temp2->next = NULL;
        temp = newhead;
        while(temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = head;
        return newhead;
    }
};