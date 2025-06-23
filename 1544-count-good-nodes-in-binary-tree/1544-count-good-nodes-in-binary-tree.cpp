/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
       int count = 0;
       countGoodnodes(root,count,root->val);
       return count; 
    }

    void countGoodnodes(TreeNode*root, int&count, int maxx) {
        if(root==NULL) return;
        if(root->val>=maxx) {
            count++;
            maxx = root->val;
        }
        countGoodnodes(root->left, count, maxx);
        countGoodnodes(root->right, count,maxx);
    }
};