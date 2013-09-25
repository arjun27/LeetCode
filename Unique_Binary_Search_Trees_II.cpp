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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> trees;
        return rootedTrees(1, n);
    }
    vector<TreeNode *> rootedTrees(int start, int n) {
        // start <= root <= start+(n-1)
        vector<TreeNode *> trees;
        if (n == 0) {
            trees.push_back(NULL); return trees;
        }
        if (n == 1) {
            // root = start
            TreeNode *root = new TreeNode(start);
            trees.push_back(root);
            return trees;
        }
        if (n == 2) {
            // root = start or start+1
            TreeNode *root = new TreeNode(start);
            root->right = new TreeNode(start+1);
            trees.push_back(root);
            TreeNode *root2 = new TreeNode(start+1);
            root2->left = new TreeNode(start);
            trees.push_back(root2);
            return trees;
        }
        for (int rv = start; rv <= start+(n-1) ; rv++) {
            vector<TreeNode *> rightTrees = rootedTrees(rv+1, n-(rv-start+1));
            vector<TreeNode *> leftTrees = rootedTrees(start, rv-start);
            int n = rightTrees.size(); int m = leftTrees.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    TreeNode *root = new TreeNode(rv);
                    root->right = rightTrees[i];
                    root->left = leftTrees[j];
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};