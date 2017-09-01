/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;
        ListNode *a, *b, *c, *d;
        a = beforeHead;
        b = head;
        c = NULL;
        d = NULL;
        if (b)
        {
            c = b->next;
            if (c)
            {
                d = c->next;
            }
        }
        while (a && b && c)
        {
            a->next = c;
            c->next = b;
            b->next = d;
            a = b;
            b = d;
            c = NULL;
            d = NULL;
            if (b)
            {
                c = b->next;
                if (c)
                {
                    d = c->next;
                }
            }
        }
        return beforeHead->next;
    }
};
