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
    int kthToLast(ListNode* head, int k)
    {
        int n = 0;

        for (auto *p = head; p; p = p->next)
            n++;

        if (n <= k)
            return head->val;

        n -= k;
        auto *res = head;

        for (int i = 0; i < n; i++)
            res = res->next;

        return res->val;
    }
};
