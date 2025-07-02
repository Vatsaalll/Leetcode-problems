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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) {return ans;}
        queue<TreeNode*>q;
        q.push(root);
        bool left2right = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int>res(n);

            for(int i = 0;i<n;i++) {
                TreeNode*frontNode = q.front();
                q.pop();

                int idx = left2right ? i : n-i-1;
                res[idx] = frontNode -> val;

                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);
            }
            left2right = !left2right;

            
                ans.push_back(res);
            

        }
        return ans;
    }
};