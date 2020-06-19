class Solution
{
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b)
    {
        int m = a.size();
        int n = b.size();
        if (!m && !n)
        {
            return 0.0;
        }
        bool need_another = false;
        if ((m + n) % 2 == 0)
        {
            need_another = true;
            int v;
            if (m && n)
            {
                v = max(a.back(), b.back());
            }
            else if (m)
            {
                v = a.back();
            }
            else if (n)
            {
                v = b.back();
            }
            n++;
            b.push_back(v);
        }
        int half = ((m + n) >> 1);
        int x = findFromFirstArray(a, b);
        if (x < 0)
        {
            swap(a, b);
            x = findFromFirstArray(a, b);
        }
        double res = a[x];
        if (need_another)
        {
            int y = half - x;
            int v;
            if (x - 1 >= 0 && y - 1 >= 0)
            {
                v = max(a[x - 1], b[y - 1]);
            }
            else if (x - 1 >= 0)
            {
                v = a[x - 1];
            }
            else if (y - 1 >= 0)
            {
                v = b[y - 1];
            }
            res = (res + v) / 2.0;
        }
        return res;
    }

private:
    int findFromFirstArray(vector<int>& a, vector<int>& b)
    {
        int m = a.size();
        int n = b.size();
        int half = ((m + n) >> 1);
        int st = 0;
        int ed = m - 1;
        while (st <= ed)
        {
            int x = ((st + ed) >> 1);
            int y = half - x;
            if (y < 0)
            {
                ed = x - 1;
                continue;
            }
            if (y > n)
            {
                st = x + 1;
                continue;
            }
            if (y > 0 && b[y - 1] > a[x])
            {
                st = x + 1;
                continue;
            }
            if (y < n && a[x] > b[y])
            {
                ed = x - 1;
                continue;
            }
            return x;
        }
        return -1;
    }
};
