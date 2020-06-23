class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        if (!n)
            return 0;

        int x = 1;
        int y = 0;

        while (n)
        {
            x *= n % 10;
            y += n % 10;
            n /= 10;
        }

        return x - y;
    }
};
