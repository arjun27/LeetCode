#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return reverser(head, k);
    }
    ListNode *reverser(ListNode *head, int k) {
        if (head == NULL) return NULL;
        int i = 0;
        ListNode *final = head;
        while (++i < k) {
            final = final->next;
            if (final == NULL) return head;
        }
        // cout<<"final.val = "<<final->val<<endl;
        ListNode *remaining = reverser(final->next, k);
        ListNode *copy = head->next, *prev = head, *temp;
        for (i = 1; i < k; i++) {
            if (copy != NULL) cout<<"copy = "<<copy->val<<endl;
            if (prev != NULL) cout<<"prev = "<<prev->val<<endl;
            if (temp != NULL) cout<<"temp = "<<temp->val<<endl;
            temp = copy->next;
            copy->next = prev;
            // cout<<copy->val<<" -> "<<prev->val<<endl;
            prev = copy;
            copy = temp;
        }
        head->next = remaining;
        // cout<<"final val = "<<final->val<<endl;
        return final;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution sol;
    ListNode *res = sol.reverseKGroup(head, 3);
    while (res != NULL) {
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}