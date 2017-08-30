class Solution
{
public:
    int maxArea(vector<int>& a)
    {
        if (a.size() < 2)
        {
            return 0;
        }
        int i = 0;
        int j = a.size() - 1;
        int res = min(a[i], a[j]) * (j - i);
        while (i < j)
        {
            if (a[i] < a[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            int area = min(a[i], a[j]) * (j - i);
            if (area > res)
            {
                res = area;
            }
        }
        return res;
    }
};
