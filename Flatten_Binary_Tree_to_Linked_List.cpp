/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flatten_tail(root);
    }
    TreeNode* flatten_tail(TreeNode *root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return root;
        TreeNode *left_tail = flatten_tail(root->left);
        TreeNode *right_tail = flatten_tail(root->right);
        TreeNode *cur = root;
        cur->left = NULL;
        cur->right = left_tail;
        while (cur->right != NULL) cur = cur->right;
        cur->right = right_tail;
        return root;
    }
};