class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<vector<int>> next;
        vector<bool> flag;
        int n = s.size();

        next.resize(n);
        flag.resize(n);
        res_.resize(n);
        for (int i = 0; i < n; i++)
        {
            res_[i] = -1;
            for (const auto& word : wordDict)
            {
                int m = word.size();

                if (m == 0)
                    continue;

                if (i + m <= n)
                {
                    bool match = true;

                    for (int j = 0; j < m; j++)
                    {
                        if (s[i + j] != word[j])
                        {
                            match = false;
                            break;
                        }
                    }

                    if (match)
                    {
                        next[i].push_back(i + m);
                        for (int j = i; j < i + m; j++)
                            flag[j] = true;
                    }
                }
            }
        }

        for (auto b : flag)
        {
            if (!b)
                return false;
        }

        for (int i = 0; i < n; i++)
            sort(next[i].begin(), next[i].end(), greater<int>());

        return dfs(0, n, next);
    }

    bool dfs(int now, int n, const vector<vector<int>>& next)
    {
        if (now == n)
            return true;

        if (res_[now] < 0)
        {
            for (auto to : next[now])
            {
                if (dfs(to, n, next))
                {
                    res_[now] = true;
                    return true;
                }
            }

            res_[now] = false;
            return false;
        }

        return res_[now];
    }

    vector<int> res_;
};
