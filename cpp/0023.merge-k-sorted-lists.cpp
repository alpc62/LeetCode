/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct zh
{
    ListNode *p;
};

bool operator<(const zh &x, const zh &y)
{
    return x.p->val > y.p->val;
}

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& a)
    {
        int n = a.size();
        if (!n)
        {
            return NULL;
        }
        ListNode beforeHead(0);
        ListNode *last = &beforeHead;
        priority_queue<zh> q;
        zh now;
        for (int i = 0; i < n; i++)
        {
            if (a[i])
            {
                now.p = a[i];
                q.push(now);
            }
        }
        while (!q.empty())
        {
            zh now = q.top();
            q.pop();
            last->next = now.p;
            last = last->next;
            if (now.p->next)
            {
                now.p = now.p->next;
                q.push(now);
            }
        }
        return beforeHead.next;
    }
};
