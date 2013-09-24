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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        return validateSub(root->left, INT_MIN, root->val) && validateSub(root->right, root->val, INT_MAX);
    }
    bool validateSub(TreeNode *node, int lower, int upper) {
        if (node == NULL) return true;
        if (node->val >= upper || node->val <= lower) return false;
        else {
            return validateSub(node->left, lower, node->val) && validateSub(node->right, node->val, upper);
        }
    }
};