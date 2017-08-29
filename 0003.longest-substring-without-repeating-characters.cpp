class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        bool bj[256] = {0};
        int st = 0;
        int ed = 0;
        while (ed < s.length())
        {
            while (ed < s.length())
            {
                int ch = s[ed] + 128;
                if (bj[ch])
                {
                    break;
                }
                bj[ch] = true;
                ed++;
            }
            if (ed - st > res)
            {
                res = ed - st;
            }
            if (ed < s.length())
            {
                for (;st < ed; st++)
                {
                    int ch = s[st] + 128;
                    bj[ch] = false;
                    if (s[st] == s[ed])
                    {
                        st++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};
