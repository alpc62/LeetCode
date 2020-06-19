class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n)
        {
            dfs(n, 0, "", res);
        }
        return res;
    }
private:
    void dfs(int leftP, int needRightP, string s, vector<string> &res)
    {
        if (!leftP && !needRightP)
        {
            res.push_back(s);
            return;
        }
        if (leftP)
        {
            dfs(leftP - 1, needRightP + 1, s + '(', res);
        }
        if (needRightP)
        {
            dfs(leftP, needRightP - 1, s + ')', res);
        }
    }
};
