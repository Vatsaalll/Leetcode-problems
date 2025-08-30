/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start,
                    int end, int& idx, map<int, int>& inList) {
        if (start > end) {
            return NULL;
        }
        int rootVal = preorder[idx];
        int inorderIdx = inList[rootVal];
        idx++;
        TreeNode* root = new TreeNode(rootVal);

        root->left =
            solve(preorder, inorder, start, inorderIdx - 1, idx, inList);
        root->right =
            solve(preorder, inorder, inorderIdx + 1, end, idx, inList);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int n = preorder.size();
        map<int, int> inList;
        for (int i = 0; i < inorder.size(); i++) {
            inList[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, n - 1, idx, inList);
    }
};