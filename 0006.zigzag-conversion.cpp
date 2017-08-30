class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
        {
            return s;
        }
        vector<string> a;
        for (int i = 0; i < numRows; i++)
        {
            a.push_back("");
        }
        int now = 0;
        int delta = 1;
        for (size_t i = 0; i < s.length(); i++)
        {
            a[now] += s[i];
            if ((delta > 0 && now == numRows - 1) || (delta < 0 && now == 0))
            {
                delta *= -1;
            }
            now += delta;
        }
        string res = "";
        for (int i = 0; i < numRows; i++)
        {
            res += a[i];
        }
        return res;
    }
};
