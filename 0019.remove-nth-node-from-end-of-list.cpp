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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!n || head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            if (n == 1)
            {
                delete head;
                head = NULL;
            }
            return head;
        }
        ListNode *beforeHead = new ListNode(0);
        beforeHead->next = head;
        ListNode *last = beforeHead;
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i < n; i++)
        {
            p2 = p2->next;
        }
        while (p2 != NULL)
        {
            last = last->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1 != NULL)
        {
            ListNode *tmp = p1;
            last->next = p1->next;
            delete tmp;
        }
        return beforeHead->next;
    }
};
