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
    ListNode* reverseList(ListNode* head)
    {
        if (!head)
            return NULL;

        auto *last = head;
        auto *cur = head->next;

        last->next = NULL;
        while (cur)
        {
            auto *next = cur->next;

            cur->next = last;
            last = cur;
            cur = next;
        }

        return last;
    }
};
