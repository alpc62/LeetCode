class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        int n = digits.length();
        if (n > 0)
        {
            dfs(digits, n, 0, "", res);
        }
        return res;
    }
private:
    void dfs(const string &digits, const int n, const int idx, string s, vector<string> &res)
    {
        if (idx == n)
        {
            res.push_back(s);
            return;
        }
        int d = digits[idx] - '0';
        switch (d)
        {
            case 2:
                dfs(digits, n, idx + 1, s + 'a', res);
                dfs(digits, n, idx + 1, s + 'b', res);
                dfs(digits, n, idx + 1, s + 'c', res);
                break;
            case 3:
                dfs(digits, n, idx + 1, s + 'd', res);
                dfs(digits, n, idx + 1, s + 'e', res);
                dfs(digits, n, idx + 1, s + 'f', res);
                break;
            case 4:
                dfs(digits, n, idx + 1, s + 'g', res);
                dfs(digits, n, idx + 1, s + 'h', res);
                dfs(digits, n, idx + 1, s + 'i', res);
                break;
            case 5:
                dfs(digits, n, idx + 1, s + 'j', res);
                dfs(digits, n, idx + 1, s + 'k', res);
                dfs(digits, n, idx + 1, s + 'l', res);
                break;
            case 6:
                dfs(digits, n, idx + 1, s + 'm', res);
                dfs(digits, n, idx + 1, s + 'n', res);
                dfs(digits, n, idx + 1, s + 'o', res);
                break;
            case 7:
                dfs(digits, n, idx + 1, s + 'p', res);
                dfs(digits, n, idx + 1, s + 'q', res);
                dfs(digits, n, idx + 1, s + 'r', res);
                dfs(digits, n, idx + 1, s + 's', res);
                break;
            case 8:
                dfs(digits, n, idx + 1, s + 't', res);
                dfs(digits, n, idx + 1, s + 'u', res);
                dfs(digits, n, idx + 1, s + 'v', res);
                break;
            case 9:
                dfs(digits, n, idx + 1, s + 'w', res);
                dfs(digits, n, idx + 1, s + 'x', res);
                dfs(digits, n, idx + 1, s + 'y', res);
                dfs(digits, n, idx + 1, s + 'z', res);
                break;
            default:
                break;
        }
    }
};
