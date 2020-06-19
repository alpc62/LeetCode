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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode *res = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = res;
        ListNode *last = NULL;
        int add = 0;
        while (p || q || add)
        {
            int x = add;
            if (p)
            {
                x += p->val;
                p = p->next;
            }
            if (q)
            {
                x += q->val;
                q = q->next;
            }
            add = x / 10;
            x %= 10;
            r->val = x;
            r->next = new ListNode(0);
            last = r;
            r = r->next;
        }
        if (r != res && r->val == 0)
        {
            delete r;
            last->next = NULL;
        }
        return res;
    }
};
