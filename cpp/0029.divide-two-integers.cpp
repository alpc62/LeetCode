const double e = exp(1);

class Solution
{
public:
    int divide(int a, int b)
    {
        if (!b)
        {
            return 2147483647;
        }
        if (!a)
        {
            return 0;
        }
        if (b == 1)
        {
            return a;
        }
        long long aa, bb;
        aa = a;
        bb = b;
        bool fu = false;
        if (aa < 0)
        {
            aa = -aa;
            fu = !fu;
        }
        if (bb < 0)
        {
            bb = -bb;
            fu = !fu;
        }
        double c = pow(e, log(aa) - log(bb));
        if (fu)
        {
            c = -c;
        }
        if (c > 2147483647 || c < -2147483648)
        {
            return 2147483647;
        }
        return int(c);
    }
};
