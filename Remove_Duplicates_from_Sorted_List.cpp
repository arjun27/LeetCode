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
        if (head == NULL) return NULL;
        ListNode *final = new ListNode(head->val);
        ListNode *copy = final;
        int last = head->val;
        head = head->next;
        while (head != NULL) {
            if (head->val != last) {
                last = head->val;
                copy->next = new ListNode(last);
                copy = copy->next;
            }
            head = head->next;
        }
        return final;
    }
};

// attempted recursive, but gives wrong answer
/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) return NULL;
        ListNode *final = new ListNode(head->val);
        deleteDuplicates(head->next, final, head->val);
        return final;
    }
    ListNode *deleteDuplicates(ListNode *old, ListNode *final, int last) {
        if (old == NULL) return final;
        if (old -> val) return deleteDuplicates(old->next, final, last);
        else {
            final->next = new ListNode(old->val);
            return deleteDuplicates(old->next, final->next, old->val);
        }
    }
};
*/