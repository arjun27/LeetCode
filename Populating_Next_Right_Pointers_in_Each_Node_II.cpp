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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) return;
        deque<TreeLinkNode*> q1, q2;
        q1.push_back(root);
        while (!q1.empty()) {
            TreeLinkNode *node = q1.front();
            q1.pop_front();
            if (node->left != NULL) q2.push_back(node->left);
            if (node->right != NULL) q2.push_back(node->right);
            if (q1.empty() && !q2.empty()) {
                q1.insert(q1.begin(), q2.begin(), q2.end());
                TreeLinkNode *front = q2.front();
                q2.pop_front();
                while (!q2.empty()) {
                    front->next = q2.front();
                    q2.pop_front();
                    front = front->next;
                }
            }
        }
    }
};