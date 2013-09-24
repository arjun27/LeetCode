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
    int maxValue;
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return 0;
        maxValue = root->val;
        
        int leftExtendable = maxExtendableSum(root->left);
        int rightExtendable = maxExtendableSum(root->right);
        return max(maxValue, root->val+leftExtendable, root->val+rightExtendable,
                   root->val+leftExtendable+rightExtendable);
    }
    int maxExtendableSum(TreeNode *root) {
        if (root == NULL) return 0;
        int leftSum = maxExtendableSum(root->left);
        int rightSum = maxExtendableSum(root->right);
        
        int maxExtendable = max(root->val, root->val+leftSum, root->val+rightSum);
        maxValue = max(maxValue, maxExtendable, root->val+rightSum+leftSum);
        return maxExtendable;
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    int max(int a, int b, int c) {
        return max(a, max(b, c));
    }
    int max(int a, int b, int c, int d) {
        return max(a, max(b, c, d));
    }
};