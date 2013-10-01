/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        connect(root->left, root->right);
        connect(root->right, NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode *right) {
        if (root == NULL) return;
        root->next = right;
        if (root->left == NULL && root->right == NULL) return;
        connect(root->left, root->right);
        if (root->next != NULL) connect(root->right, root->next->left);
        else connect(root->right, NULL);
    }
};