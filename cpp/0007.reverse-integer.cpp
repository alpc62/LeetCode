class Solution
{
public:
    int reverse(int x)
    {
        if (!x)
        {
            return x;
        }
        bool isNegative = (x < 0);
        if (x < 0)
        {
            x *= -1;
        }
        int res32 = 0;
        long long res64 = 0;
        for (; x; x /= 10)
        {
            int v = x % 10;
            res32 = res32 * 10 + v;
            res64 = res64 * 10 + v;
        }
        if (isNegative)
        {
            res32 *= -1;
            res64 *= -1;
        }
        if ((long long)res32 != res64)
        {
            return 0;
        }
        return res32;
    }
};
