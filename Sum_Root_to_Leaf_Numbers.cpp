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
    int total;
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        total = 0;
        addPath(root, 0);
        return total;
    }
    void addPath(TreeNode *root, int ongoing) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            total += (ongoing * 10) + root->val;
        } else {
            addPath(root->left, ongoing*10 + root->val);
            addPath(root->right, ongoing*10 + root->val);
        }
    }
};