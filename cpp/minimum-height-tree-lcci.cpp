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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty())
            return NULL;

        TreeNode *root = new TreeNode(0);

        dfs(root, 0, nums.size(), nums);

        return root;
    }

    void dfs(TreeNode *now, size_t st, size_t ed, const vector<int>& arr)
    {
        size_t mid = (st + ed) / 2;

        now->val = arr[mid];
        if (st < mid)
        {
            now->left = new TreeNode(0);
            dfs(now->left, st, mid, arr);
        }

        if (mid + 1 < ed)
        {
            now->right = new TreeNode(0);
            dfs(now->right, mid + 1, ed, arr);
        }
    }
};
