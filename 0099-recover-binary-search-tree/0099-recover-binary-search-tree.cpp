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
    void validRight(TreeNode* node, TreeNode* orig) {
        if (node==nullptr) return;
        if (node->val<orig->val) {
            swap(node->val,orig->val);
        }
        validRight(node->left,orig); validRight(node->right,orig);
    }
    void validLeft(TreeNode* node, TreeNode* orig) {
        if (node==nullptr) return;
        if (node->val>orig->val) {
            swap(node->val,orig->val);
        }
        validLeft(node->left,orig); validLeft(node->right,orig);
    }
    void recoverTree0(TreeNode* root) {
        if (root==nullptr) return;

        validLeft(root->left,root); validRight(root->right,root);
        recoverTree0(root->left); recoverTree0(root->right);
        
    }
    void recoverTree(TreeNode* root) {

        recoverTree0(root);
        recoverTree0(root);

    }
};