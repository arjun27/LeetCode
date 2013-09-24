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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return true;
        return symCheck(root->left, root->right);
    }
    bool symCheck(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL) return true;
        if (left != NULL && right != NULL) {
            if (left->val != right->val) return false;
            bool leftCheck = symCheck(left->left, right->right);
            bool rightCheck = symCheck(left->right, right->left);
            return leftCheck && rightCheck;
        } else {
            return false;
        }
    }
};