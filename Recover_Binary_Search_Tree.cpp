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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> inorder = inorderTraversal(root);
        // find mismatched pair
        int i, j; // assume i < j; 0 <= i < n-1 and 0 < j <= n - 1
        int n = inorder.size();
        for (int k = 0; k < n-1; k++) {
            if (inorder[k+1] < inorder[k]) {
                i = k; break;
            }
        }
        for (int k = n-1; k > 0; k--) {
            if (inorder[k] < inorder[k-1]) {
                j = k; break;
            }
        }
        // swap inorder[i] and inorder[j]
        // root = swapTree(root, inorder[i], inorder[j]);
        
        TreeNode *a = findVal(root, inorder[i]);
        TreeNode *b = findVal(root, inorder[j]);
        swap(a->val, b->val);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> trav;
        if (root == NULL) return trav;
        vector<int> leftT = inorderTraversal(root->left);
        vector<int> rightT = inorderTraversal(root->right);
        leftT.push_back(root->val);
        leftT.insert(leftT.end(), rightT.begin(), rightT.end());
        return leftT;
    }
    TreeNode* findVal(TreeNode *root, int v) {
        if (root == NULL) return NULL;
        if (root->val == v) return root;
        TreeNode *resL = findVal(root->left, v);
        TreeNode *resR = findVal(root->right, v);
        if (resL != NULL) return resL;
        else return resR;
    }
};

// TO DO: use O(1) space
