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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k <= 1)
        {
            return head;
        }
        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;
        ListNode *a, *b, *c, *d;
        a = beforeHead;
        b = head;
        c = NULL;
        d = NULL;

        c = b;
        for (int i = 1; c && i < k; i++)
        {
            c = c->next;
        }
        if (c)
        {
            d = c->next;
        }
        while (a && b && c)
        {
            ListNode *p, *q, *r;
            p = b;
            q = p->next;
            while (q != d)
            {
                r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            a->next = c;
            b->next = d;

            a = b;
            b = d;
            c = NULL;
            d = NULL;

            c = b;
            for (int i = 1; c && i < k; i++)
            {
                c = c->next;
            }
            if (c)
            {
                d = c->next;
            }
        }
        return beforeHead->next;
    }
};
