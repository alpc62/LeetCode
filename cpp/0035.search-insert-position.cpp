class Solution
{
public:
    int searchInsert(vector<int>& a, int target)
    {
        int n = a.size();
        if (!n)
        {
            return 0;
        }
        int res = searchLowOrEqual(a, n, target);
        if (res < 0)
        {
            res = 0;
        }
        if (a[res] < target)
        {
            res++;
        }
        return res;
    }
private:
    int searchLowOrEqual(const vector<int> &a, const int n, const int v)
    {
        int ret = -1;
        int st, ed;
        st = 0;
        ed = n - 1;
        while (st <= ed)
        {
            int mid = ((st + ed) >> 1);
            if (a[mid] == v)
            {
                return mid;
            }
            if (a[mid] < v)
            {
                ret = mid;
                st = mid + 1;
            }
            else
            {
                ed = mid - 1;
            }
        }
        return ret;
    }
};
