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
    vector<int> pre;
    vector<int> in;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        pre = preorder;
        in = inorder;
        if (n == 0) return NULL;
        else return builder( 0, n-1, 0, n-1);
    }
    TreeNode *builder(int pre_start, int pre_end, int in_start, int in_end) {
        TreeNode *root;
        if (pre_end < pre_start) return NULL;
        int rv = pre[pre_start];
        root = new TreeNode(rv);
        if (pre_end == pre_start) {
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
        int l_pre_start = pre_start + 1;
        int l_pre_end = pre_start + 1 + (rv_pos - in_start - 1);
        int l_in_start = in_start;
        int l_in_end = rv_pos - 1;
        
        // right definitions
        int r_pre_start = l_pre_end + 1;
        int r_pre_end = pre_end;
        int r_in_start = l_in_end + 2;
        int r_in_end = in_end;
        
        root->left = builder(l_pre_start, l_pre_end, l_in_start, l_in_end);
        root->right = builder(r_pre_start, r_pre_end, r_in_start, r_in_end);
        return root;
    }    
};