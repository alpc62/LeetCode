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
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (!root)
            return NULL;

        TreeNode *res = new TreeNode(root->val);

        dfs(root, res);
        return res;
    }

    void dfs(const TreeNode *now, TreeNode *to)
    {
        if (now->right)
        {
            to->left = new TreeNode(now->right->val);
            dfs(now->right, to->left);
        }

        if (now->left)
        {
            to->right = new TreeNode(now->left->val);
            dfs(now->left, to->right);
        }
    }
};
