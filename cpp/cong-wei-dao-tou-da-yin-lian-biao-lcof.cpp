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
    vector<int> reversePrint(ListNode* head)
    {
        vector<int> arr;

        for (; head; head = head->next)
            arr.push_back(head->val);

        std::reverse(arr.begin(), arr.end());
        return arr;
    }
};
