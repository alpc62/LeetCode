class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (!s.length())
        {
            return "";
        }
        map<char, vector<int> > char2reverseIndexArray;
        for (size_t i = 0; i < s.length(); i++)
        {
            int idx = s.length() - i - 1;
            char2reverseIndexArray[s[idx]].push_back(idx);
        }
        int maxLenP, st, ed;
        maxLenP = st = ed = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            vector<int> *pa = &(char2reverseIndexArray[ch]);
            for (size_t ii = 0; ii < pa->size(); ii++)
            {
                int j = pa->at(ii);
                if (j < i)
                {
                    break;
                }
                if (j - i + 1 <= maxLenP)
                {
                    break;
                }
                if (isPalindrome(s, i, j))
                {
                    maxLenP = j - i + 1;
                    st = i;
                    ed = j;
                    break;
                }
            }
        }
        if (!maxLenP)
        {
            return "";
        }
        return s.substr(st, ed - st + 1);
    }

private:
    bool isPalindrome(const string &s, int st, int ed)
    {
        int len = ed - st + 1;
        int checkLen = len / 2;
        for (int i = 0; i < checkLen; i++)
        {
            if (s[st + i] != s[ed - i])
            {
                return false;
            }
        }
        return true;
    }
};
