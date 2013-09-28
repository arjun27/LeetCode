/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min = INT_MAX, pos = -1;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL && lists[i]->val < min) {
                pos = i;
                min = lists[i]->val;
            }
        }
        if (pos < 0) return NULL;
        ListNode *l = new ListNode(min);
        lists[pos] = lists[pos]->next;
        l->next = mergeKLists(lists);
        return l;
    }
};