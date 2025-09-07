class Solution {
public:
    bool helper(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;

        return helper(root->left, mini, root->val) &&
               helper(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};