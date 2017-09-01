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
        if (!l1 && !l2)
        {
            return NULL;
        }
        if (!l1)
        {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }
        ListNode *head, *now, *p1, *p2;
        p1 = l1;
        p2 = l2;
        if (p1->val < p2->val)
        {
            head = p1;
            p1 = p1->next;
        }
        else
        {
            head = p2;
            p2 = p2->next;
        }
        now = head;
        while (p1 || p2)
        {
            ListNode *choose;
            if (!p1)
            {
                choose = p2;
            }
            if (!p2)
            {
                choose = p1;
            }
            if (p1 && p2)
            {
                if (p1->val < p2->val)
                {
                    choose = p1;
                }
                else
                {
                    choose = p2;
                }
            }
            if (choose == p1)
            {
                p1 = p1->next;
            }
            else
            {
                p2 = p2->next;
            }
            now->next = choose;
            now = choose;
        }
        return head;
    }
};
