class Solution
{
public:
    int balancedStringSplit(string s)
    {
        if (s.empty())
            return 1;

        int res = 0;
        size_t idx = 0;

        do
        {
            int n = 0;

            if (s[idx++] == 'L')
                n++;
            else
                n--;

            while (n && idx < s.size())
            {
                if (s[idx++] == 'L')
                    n++;
                else
                    n--;
            }

            res++;
        } while (idx < s.size());

        return res;
    }
};
