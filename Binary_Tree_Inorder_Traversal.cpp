#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        // val(x), left(NULL), right(NULL);
        val = x;
        left = NULL;
        right = NULL;
    }
};

/**
 * Recursive solution
 */

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            vector <int> t; t.resize(0);
            return t;
        }
        vector <int> leftT = inorderTraversal(root->left);
        leftT.push_back(root->val);
        vector <int> rightT = inorderTraversal(root->right);
        leftT.insert(leftT.end(), rightT.begin(), rightT.end());
        return leftT;
    }
};
*/

/**
 * Iterative solution
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        vector<int> trav;
        TreeNode* current = root;
        // nodes.push(root);
        while(!nodes.empty() || current != NULL) {
            if (current != NULL) {
                nodes.push(current);
                current = current->left;
            }
            else {
                current = nodes.top();
                nodes.pop();
                trav.push_back(current->val);
                current = current->right;
            }
        }
        return trav;
    }
};

void printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<endl;
    }
}

int main() {
    Solution sol;
    printVector(sol.inorderTraversal(NULL));
    return 0;
}