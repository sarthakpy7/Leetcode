/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);

        // Initialize pointers to find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Find the middle node (slow) and its previous node (prev)
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half from the mid node
        if (prev)
            prev->next = nullptr;

        // Create root with mid value
        TreeNode* root = new TreeNode(slow->val);

        // Recursively build left and right subtrees
        root->left = sortedListToBST(head == slow ? nullptr : head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};