class Solution
{
public:
    vector<int> searchRange(vector<int>& a, int target)
    {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int n = a.size();
        if (!n)
        {
            return res;
        }
        int low = searchLow(a, n, target);
        if (low + 1 < n && a[low + 1] == target)
        {
            low++;
        }
        if (!(low >= 0 && low < n && a[low] == target))
        {
            low = -1;
        }
        int high = searchHigh(a, n, target);
        if (high - 1 >= 0 && a[high - 1] == target)
        {
            high--;
        }
        if (!(high >= 0 && high < n && a[high] == target))
        {
            high = -1;
        }
        res[0] = low;
        res[1] = high;
        return res;
    }
private:
    int searchLow(const vector<int> &a, const int n, const int v)
    {
        int ret = -1;
        int st, ed;
        st = 0;
        ed = n - 1;
        while (st <= ed)
        {
            int mid = ((st + ed) >> 1);
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
    int searchHigh(const vector<int> &a, const int n, const int v)
    {
        int ret = n;
        int st, ed;
        st = 0;
        ed = n - 1;
        while (st <= ed)
        {
            int mid = ((st + ed) >> 1);
            if (a[mid] > v)
            {
                ret = mid;
                ed = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ret;
    }
};
