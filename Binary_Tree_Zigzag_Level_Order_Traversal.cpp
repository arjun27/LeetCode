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
    vector<vector<int> > trav;
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        trav.resize(0);
        levelTrav(root, 0);
        // implement zig zag
        for (int i = 0 ; i < trav.size(); i++) {
            if (i % 2 == 1) {
                vector<int> now = trav[i];
                reverse(now.begin(), now.end());
                trav[i] = now;
            }
        }
        return trav;
    }
    void levelTrav(TreeNode *root, int level) {
        if (root == NULL) return;
        if (trav.size() > level) {
            vector<int> now = trav[level];
            now.push_back(root->val);
            trav[level] = now;
        } else {
            trav.resize(level + 1);
            vector<int> now; now.push_back(root->val);
            trav[level] = now;
        }
        levelTrav(root->left, level+1);
        levelTrav(root->right, level+1);
    }
};