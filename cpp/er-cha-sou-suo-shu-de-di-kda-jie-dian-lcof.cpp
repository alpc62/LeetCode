/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int kthLargest(TreeNode* root, int k)
    {
        if (!root)
            return 0;

        int nr = count(root->right);

        if (k <= nr)
            return kthLargest(root->right, k);

        k -= nr;

        if (k == 1)
            return root->val;

        return kthLargest(root->left, k - 1);
    }

    int count(TreeNode *cur)
    {
        if (!cur)
            return 0;

        return count(cur->left) + count(cur->right) + 1;
    }
};
