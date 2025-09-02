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
    int maxDep;
    int bottom;

    void dfs(TreeNode* root, int curdep) {
        if(!root) {
            return;
        }
        if(curdep>maxDep) {
            maxDep = curdep;
            bottom = root->val;
        }
        dfs(root->left,curdep+1);
        dfs(root->right,curdep+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxDep = -1;
        dfs(root,0);
        return bottom;
    }
};