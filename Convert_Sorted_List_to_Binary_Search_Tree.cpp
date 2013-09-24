/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int totalSize;
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        totalSize = listSize(head);
        return createBST(head, totalSize);
    }
    TreeNode *createBST(ListNode *head, int n) {
        TreeNode *root;
        if (n <= 0) return NULL;
        if (n == 1) {
            root = new TreeNode(head->val);
            return root;
        }
        int mid = n / 2;
        TreeNode *leftTree = createBST(head, mid);
        ListNode *copy = head;
        int midc = mid;
        while (midc > 0) {
            copy = copy->next;
            midc--;
        }
        root = new TreeNode(copy->val);
        TreeNode *rightTree = createBST(copy->next, n-mid-1);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
    int listSize(ListNode *head) {
        ListNode *start = head;
        int size = 0;
        while (start != NULL) {
            start = start->next;
            size++;
        }
        return size;
    }
};