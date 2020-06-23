static inline int MAX(int x, int y)
{
    return x > y ? x : y;
}

static inline int ABS(int x)
{
    return x > 0 ? x : -x;
}

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
    {
        int res = 0;

        for (int i = 1; i < points.size(); i++)
            res += MAX(ABS(points[i][0] - points[i - 1][0]), ABS(points[i][1] - points[i - 1][1]));

        return res;
    }
};
