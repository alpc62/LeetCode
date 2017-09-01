class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        if (!m)
        {
            return 0;
        }
        for (int i = 0; i <= n - m; i++)
        {
            bool is_same = true;
            for (int j = 0; i + j < n && j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    is_same = false;
                    break;
                }
            }
            if (is_same)
            {
                return i;
            }
        }
        return -1;
    }
};
