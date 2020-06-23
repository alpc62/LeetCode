class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;

        while (x || y)
        {
            if (x % 2 != y % 2)
                res++;

            x /= 2;
            y /= 2;
        }

        return res;
    }
};
