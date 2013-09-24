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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) return NULL;
        return createSub(num, 0, num.size());
    }
    TreeNode *createSub(vector<int> &num, int from, int to) {
        if (from > to-1) return NULL;
        int mid = (from + to) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = createSub(num, from, mid);
        root->right = createSub(num, mid+1, to);
        return root;
    }
};