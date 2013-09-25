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
    vector<int> post;
    vector<int> in;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = inorder.size();
        post = postorder;
        in = inorder;
        if (n == 0) return NULL;
        else return builder( 0, n-1, 0, n-1);
    }
    TreeNode *builder(int post_start, int post_end, int in_start, int in_end) {
        TreeNode *root;
        if (post_end < post_start) return NULL;
        int rv = post[post_end];
        root = new TreeNode(rv);
        if (post_end == post_start) {
            return root;
        }
        // find rv_pos in inorder
        int rv_pos;
        for (int i = in_start; i <= in_end; i++) {
            if (in[i] == rv) {
                rv_pos = i; break;
            }
        }

        // left definitions
        int l_post_start = post_start;
        int l_post_end = post_start + (rv_pos - in_start - 1);
        int l_in_start = in_start;
        int l_in_end = rv_pos - 1;
        
        // right definitions
        int r_post_start = l_post_end + 1;
        int r_post_end = post_end - 1;
        int r_in_start = l_in_end + 2;
        int r_in_end = in_end;
        
        root->left = builder(l_post_start, l_post_end, l_in_start, l_in_end);
        root->right = builder(r_post_start, r_post_end, r_in_start, r_in_end);
        return root;
    }
};