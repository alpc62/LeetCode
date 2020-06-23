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
    int maxDepth(TreeNode* root)
    {
        dfs(root, 1);

        return maxd_;
    }

    void dfs(const TreeNode *now, int h)
    {
        if (now == NULL)
            return;

        if (h > maxd_)
            maxd_ = h;

        dfs(now->left, h + 1);
        dfs(now->right, h + 1);
    }

    int maxd_ = 0;
};
