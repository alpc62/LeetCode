static inline char itoch(char ch1, char ch2)
{
    return 'j' + ((ch1 - '0') * 10 + (ch2 - '0')) - 10;
}

class Solution
{
public:
    string freqAlphabets(string s)
    {
        string res;

        for (auto ch : s)
        {
            if (ch == '#')
            {
                auto ch2 = res.back();
                res.pop_back();
                auto ch1 = res.back();
                res.pop_back();
                res += itoch(ch1, ch2);
            }
            else
                res += ch;
        }

        for (auto& ch : res)
        {
            if (ch >= '1' && ch <= '9')
                ch = 'a' + ch - '1';
        }

        return res;
    }
};
