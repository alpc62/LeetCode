class Solution
{
public:
    string replaceSpace(string s)
    {
        string res;

        for (auto ch : s)
        {
            if (ch == ' ')
                res += "%20";
            else
                res += ch;
        }

        return res;
    }
};
