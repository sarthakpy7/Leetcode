class Solution {
public:
    struct Result {
        TreeNode* node;
        int depth;
    };

    Result dfs(TreeNode* root, int depth) {
        if (!root) return {nullptr, depth};

        auto left = dfs(root->left, depth + 1);
        auto right = dfs(root->right, depth + 1);

        if (left.depth == right.depth) return {root, left.depth};
        return left.depth > right.depth ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).node;
    }
};