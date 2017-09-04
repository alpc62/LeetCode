class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        int n = s.length();
        for (int i = 0; i < n;)
        {
            int l = validLength(s, n, i);
            if (l > res)
            {
                res = l;
            }
            if (!l)
            {
                l = 1;
            }
            i += l;
        }
        return res;
    }
private:
    int validLength(const string &s, const int n, int st)
    {
        int nump = 0;
        int ret = 0;
        int m = 0;
        bool is_finish = false;
        for (int i = st; !is_finish && i < n; i++)
        {
            switch (s[i])
            {
                case '(':
                    nump++;
                    break;
                case ')':
                    {
                        if (nump <= 0)
                        {
                            is_finish = true;
                            break;
                        }
                        nump--;
                        m++;
                        if (nump == 0)
                        {
                            ret = m * 2;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        return ret;
    }
};
