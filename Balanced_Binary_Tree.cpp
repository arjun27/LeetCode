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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (subDepths(root) < 0) return false;
        return true;
    }
    int subDepths(TreeNode* root) {
        if (root == NULL) return 0;
        int leftDepth = subDepths(root->left);
        int rightDepth = subDepths(root->right);
        if (leftDepth < 0 || rightDepth < 0 || abs(leftDepth-rightDepth) > 1) {
            return -1;
        } else {
            return max(leftDepth, rightDepth) + 1;
        }
    }
    int max (int a, int b) {
        return (a > b) ? a : b;
    }
};