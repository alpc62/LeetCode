static inline bool is_div(int n)
{
    if (!n)
        return false;

    int x = n;

    while (x)
    {
        int y = x % 10;

        if (!y || n % y)
            return false;

        x /= 10;
    }

    return true;
}

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;

        for (int i = left; i <= right; i++)
        {
            if (is_div(i))
                res.push_back(i);
        }

        return res;
    }
};
