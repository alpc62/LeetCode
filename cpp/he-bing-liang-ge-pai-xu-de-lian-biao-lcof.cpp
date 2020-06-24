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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;

        if (!l2)
            return l1;

        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->val = l1->val;
                l1 = l1->next;
            }
            else
            {
                cur->val = l2->val;
                l2 = l2->next;
            }

            if (l1 && l2)
            {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }

        if (l1)
            cur->next = l1;

        if (l2)
            cur->next = l2;

        return head;
    }
};
