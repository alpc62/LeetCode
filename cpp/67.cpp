class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        size_t m = a.size();
        size_t n = b.size();
        size_t i = 0;
        int add = 0;
        int c;

        for (; i < m && i < n; i++)
        {
            c = (a[m - 1 - i] - '0') + (b[n - 1 - i] - '0') + add;
            add = c / 2;
            res += c % 2 + '0';
        }

        for (; i < m; i++)
        {
            c = (a[m - 1 - i] - '0') + add;
            add = c / 2;
            res += c % 2 + '0';
        }

        for (; i < n; i++)
        {
            c = (b[n - 1 - i] - '0') + add;
            add = c / 2;
            res += c % 2 + '0';
        }

        if (add)
            res += '1';

        std::reverse(res.begin(), res.end());

        if (res.empty())
            res = "0";

        return res;
    }
};
