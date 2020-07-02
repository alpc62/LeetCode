class Solution
{
public:
    double average(vector<int>& salary)
    {
        double all = 0.0;
        int smin = 123456789;
        int smax = 0;

        for (auto ele : salary)
        {
            if (ele > smax)
                smax = ele;

            if (ele < smin)
                smin = ele;

            all += ele;
        }

        return (all - smin - smax) / (salary.size() - 2);
    }
};
