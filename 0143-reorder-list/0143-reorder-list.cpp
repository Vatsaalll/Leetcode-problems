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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next ==NULL) return;

        //Find the mid
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        //reverse
        ListNode* mide = p1;
        ListNode* precur = p1->next;
        while(precur->next != NULL) {
            ListNode* curr = precur->next;
            precur->next = curr->next;
            curr->next = mide->next;
            mide->next = curr;
        }

        //reorder
        p1 = head;
        p2 = mide->next;
        while(p1!=mide) {
            mide->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = mide->next;
        }
    }
};