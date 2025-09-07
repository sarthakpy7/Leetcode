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
    TreeNode* maketree(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart, int inend ,map<int,int>& mp){
        if(poststart>postend || instart>inend) return NULL;
        TreeNode *root = new TreeNode(postorder[postend]);
        int inindex = mp[root->val];
        int numsleft = inindex - instart;
        
        root->left = maketree(postorder,poststart,poststart+numsleft-1,inorder,instart,inindex-1,mp);
        root->right = maketree(postorder,poststart+numsleft,postend-1,inorder,inindex+1,inend,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int m = inorder.size();
        map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = maketree(postorder,0,n-1,inorder,0,m-1,mp);
        return root;
    }
};