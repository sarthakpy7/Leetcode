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
    int find(TreeNode* root){
        if(!root)
        return 0;
        int l = find(root->left);
        int r = find(root->right);
        return 1 + max(l,r);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int level = find(root);
        vector<vector<int>> ans(level);
        queue<TreeNode*>q;
        if(!root)
        return ans;
        q.push(root);
        int i = level - 1;
        while(!q.empty()){
            int n = q.size();
            vector<int>temp;
            while(n--){
             TreeNode* node = q.front();
             temp.push_back(node->val);
             q.pop();
             if(node->left)
             q.push(node->left);
             if(node->right)
             q.push(node->right);
            }
            ans[i] = temp;
            i--;
        }

       
       return ans;
    }
};