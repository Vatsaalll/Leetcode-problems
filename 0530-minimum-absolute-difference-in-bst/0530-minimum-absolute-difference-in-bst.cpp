class Solution {
private:
    int res = INT_MAX, prev = INT_MAX;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        res = min(res, abs(root->val - prev));
        prev = root->val;
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return res;
    }
};