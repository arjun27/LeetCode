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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > rPaths = reversedPathSum(root, sum);
        vector<vector<int> > paths;
        for (int i = 0; i < rPaths.size(); i++) {
            vector<int> path = rPaths[i];
            reverse(path.begin(), path.end());
            paths.push_back(path);
        }
        return paths;
 
    }
    vector<vector<int> > reversedPathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        if (root == NULL) return paths;
        if (root->left == NULL && root->right == NULL) {
            if (sum == root->val) {
                vector<int> path; path.push_back(root->val);
                paths.push_back(path);
            }
            return paths;
        }
        vector<vector<int> > leftPaths = reversedPathSum(root->left, sum - (root->val));
        vector<vector<int> > rightPaths = reversedPathSum(root->right, sum - (root->val));
        
        for (int i = 0; i < leftPaths.size(); i++) {
            vector<int> path = leftPaths[i];
            path.push_back(root->val);
            paths.push_back(path);
        }
        for (int i = 0; i < rightPaths.size(); i++) {
            vector<int> path = rightPaths[i];
            path.push_back(root->val);
            paths.push_back(path);
        }
        return paths;
    }
};