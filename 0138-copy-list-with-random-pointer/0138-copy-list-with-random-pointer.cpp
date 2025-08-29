/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map <Node*,Node*>mape;
        Node* cur = head;
        while(cur) {
            mape[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;

        while(cur) {
            Node* copy = mape[cur];
            copy->next = mape[cur->next];
            copy->random = mape[cur->random];
            cur = cur->next;
        }
        return mape[head];
    }
};