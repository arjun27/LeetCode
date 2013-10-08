/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        RandomListNode *copied = doCopy(head);
        RandomListNode *copy = copied;
        while (copy != NULL) {
            if (copy->random != NULL) copy->next->random = copy->random->next;
            else copy->next->random = NULL;
            copy = copy->next->next;
        }
        copy = copied;
        RandomListNode *final = copied->next;
        RandomListNode *finalcopy = final;
        while (copy != NULL) {
            copy->next = copy->next->next;
            if (final->next != NULL) final->next = final->next->next;
            else final->next = NULL;
            copy = copy->next;
            final = final->next;
        }
        return finalcopy;
    }
    RandomListNode *doCopy(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *temp = head->next;
        RandomListNode *copy = new RandomListNode(head->label);
        head->next = copy;
        copy->next = doCopy(temp);
        return head;
    }
};
