class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string res;
        int n = 0;

        for (auto ch : S)
        {
            if (n == 0)
                n++;
            else if (ch == '(')
            {
                res += '(';
                n++;
            }
            else if (--n > 0)
                res += ')';
        }

        return res;
    }
};
