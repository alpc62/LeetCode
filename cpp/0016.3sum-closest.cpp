class Solution
{
public:
    int threeSumClosest(vector<int>& arr, int target)
    {
        int n = arr.size();
        if (n < 3)
        {
            return 0;
        }
        sort(arr.begin(), arr.end());
        int minD = -1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }
            int a = arr[i];
            for (int j = i + 1; j + 1 < n; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }
                int b = arr[j];
                int c = target - a - b;
                int k = _binarySearch(arr, j + 1, n - 1, c);
                if (j < k && k < n)
                {
                    int s = a + b + arr[k];
                    int d = abs(s - target);
                    if (!d)
                    {
                        return target;
                    }
                    if (minD < 0 || d < minD)
                    {
                        minD = d;
                        res = s;
                    }
                }
                if (j < k && k + 1 < n)
                {
                    int s = a + b + arr[k + 1];
                    int d = abs(s - target);
                    if (minD < 0 || d < minD)
                    {
                        minD = d;
                        res = s;
                    }
                }
            }
        }
        return res;
    }
private:
    int _binarySearch(const vector<int> &arr, int st, int ed, int val)
    {
        int ret = st;
        while (st <= ed)
        {
            int mid = ((st + ed) >> 1);
            if (arr[mid] == val)
            {
                ret = mid;
                break;
            }
            else if (arr[mid] < val)
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
