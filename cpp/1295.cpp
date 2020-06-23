static inline bool mycheck(int n)
{
    if (n == 0)
        return false;

    int s = 0;

    for (; n; n /= 10)
        s++;

    return s % 2 == 0;
}

class Solution
{
public:
    int findNumbers(vector<int>& nums)
    {
        int res = 0;

        for (auto n : nums)
        {
            if (mycheck(n))
                res++;
        }

        return res;
    }
};
