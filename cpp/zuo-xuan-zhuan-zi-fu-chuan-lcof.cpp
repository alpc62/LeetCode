class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        string res;

        if (n > s.size())
            n = s.size();

        res.append(s.c_str() + n);
        res.append(s.c_str(), n);

        return res;
    }
};
