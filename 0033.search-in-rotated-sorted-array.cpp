class Solution
{
public:
    int search(vector<int>& a, int target)
    {
        int st, ed;
        st = 0;
        ed = a.size() - 1;
        while (st <= ed)
        {
            if (a[st] == target)
            {
                return st;
            }
            if (a[ed] == target)
            {
                return ed;
            }
            int mid = ((st + ed) >> 1);
            if (a[mid] == target)
            {
                return mid;
            }
            if (a[st] < a[ed])
            {
                if (a[mid] < target)
                {
                    st = mid + 1;
                }
                else
                {
                    ed = mid - 1;
                }
            }
            else if (a[st] < a[mid])
            {
                if (a[st] < target && target < a[mid])
                {
                    ed = mid - 1;
                }
                else
                {
                    st = mid + 1;
                }
            }
            else
            {
                if (a[mid] < target && target < a[ed])
                {
                    st = mid + 1;
                }
                else
                {
                    ed = mid - 1;
                }
            }
        }
        return -1;
    }
};
