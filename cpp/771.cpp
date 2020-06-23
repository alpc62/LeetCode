class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int res = 0;

        for (auto ch : S)
        {
            for (auto jch : J)
            {
                if (ch == jch)
                {
                    res++;
                    break;
                }
            }
        }

        return res;
    }
};
