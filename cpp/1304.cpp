class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> arr;

        if (n == 0)
            return arr;

        if (n % 2)
            arr.push_back(0);

        n /= 2;
        for (int i = 0; i < n; i++)
        {
            arr.push_back(i + 1);
            arr.push_back(-i - 1);
        }

        return arr;
    }
};
