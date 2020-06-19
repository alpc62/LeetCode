static inline bool isNumber(const char ch)
{
    return ch >= '0' && ch <= '9';
}

class Solution
{
public:
    int myAtoi(string str)
    {
        int slen = str.length();
        if (!slen)
        {
            return 0;
        }
        int st, ed;
        for (st = 0; st < slen && str[st] == ' '; st++);
        if (st == slen)
        {
            return 0;
        }
        if (str[st] != '+' && str[st] != '-' && !isNumber(str[st]))
        {
            return 0;
        }
        bool isNegative = (str[st] == '-');
        if (!isNumber(str[st]))
        {
            st++;
            if (st == slen || !isNumber(str[st]))
            {
                return 0;
            }
        }
        for (; st < slen && str[st] == '0'; st++);
        if (st == slen || !isNumber(str[st]))
        {
            return 0;
        }
        for (ed = st; ed < slen && isNumber(str[ed]); ed++);
        if (ed - st > 10)
        {
            return (isNegative ? INT_MIN : INT_MAX);
        }
        long long res = 0;
        for (int i = st; i < ed; i++)
        {
            res = res * 10 + (str[i] - '0');
        }
        if (isNegative)
        {
            res *= -1;
        }
        if (res < (long long)INT_MIN)
        {
            res = INT_MIN;
        }
        if (res > (long long)INT_MAX)
        {
            res = INT_MAX;
        }
        return (int)res;
    }
};
