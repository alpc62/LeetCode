class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        if (x < 10)
        {
            return true;
        }
        long long y = 0;
        for (int xx = x; xx; xx /= 10)
        {
            y = y * 10 + xx % 10;
        }
        return (long long)x == y;
    }
};
