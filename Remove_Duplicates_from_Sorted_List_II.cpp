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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode *final = new ListNode(head->val);
        ListNode *copy = final;
        int last = head->val;
        bool duplicate = false;
        head = head->next;
        while (head != NULL) {
            if (head->val == last) {
                duplicate = true;
            } else {
                if (!duplicate) {
                    copy->val = last;
                    copy->next = new ListNode(head->val);
                    last = head->val;
                    copy = copy->next;
                } else {
                    copy->val = head->val;
                    last = head->val;
                    duplicate = false;
                }
            }
            head = head->next;
        }
        if (duplicate) {
            // remove last element
            final = deleteLast(final);
        }
        return final;
    }
    ListNode* deleteLast(ListNode *head) {
        ListNode *final;
        if (head->next == NULL) return NULL;
        final = new ListNode(head->val);
        final->next = deleteLast(head->next);
        return final;
    }
};