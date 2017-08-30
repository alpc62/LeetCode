class Solution
{
public:
    bool isMatch(string s, string p)
    {
        lens = s.length();
        lenp = p.length();
        bool have_reg = false;
        for (size_t i = 0; i < lenp; i++)
        {
            if (p[i] == '.' || p[i] == '*')
            {
                have_reg = true;
                break;
            }
        }
        if (!have_reg)
        {
            return s == p;
        }
        if (!lenp && lens > 0)
        {
            return false;
        }
        size_t idx = 0;
        do
        {
            bool have_same = false;
            int pos = 0;
            for (; idx < lenp; idx++)
            {
                if (p[idx] == '*')
                {
                    if (idx - 1 >= 0 && idx + 2 < lenp && p[idx - 1] == p[idx + 1] && p[idx + 2] == '*')
                    {
                        have_same = true;
                        pos = idx + 1;
                        break;
                    }
                }
            }
            if (!have_same)
            {
                break;
            }
            p.erase(pos, 2);
            lenp = p.length();
        } while (1);
        return regMatch(s, p, 0, 0);
    }

private:
    bool regMatch(const string &s, const string &p, int is, int ip)
    {
        if (is >= lens && ip >= lenp)
        {
            return true;
        }
        if (ip >= lenp)
        {
            return false;
        }
        if (p[ip] == '*')
        {
            return false;
        }
        if (is >= lens)
        {
            if (ip + 1 >= lenp || p[ip + 1] != '*')
            {
                return false;
            }
            return regMatch(s, p, is, ip + 2);
        }
        if (ip + 1 < lenp && p[ip + 1] == '*')
        {
            if (p[ip] != '.' && s[is] != p[ip])
            {
                return regMatch(s, p, is, ip + 2);
            }
            return regMatch(s, p, is, ip + 2) || regMatch(s, p, is + 1, ip) || regMatch(s, p, is + 1, ip + 2);
        }
        else
        {
            if (p[ip] != '.' && s[is] != p[ip])
            {
                return false;
            }
            return regMatch(s, p, is + 1, ip + 1);
        }
    }
    int lenp;
    int lens;
};
