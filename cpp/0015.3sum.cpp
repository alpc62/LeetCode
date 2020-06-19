class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& arr)
    {
        int n = arr.size();
        vector<vector<int> > res;
        if (n < 3)
        {
            return res;
        }
        sort(arr.begin(), arr.end());
        vector<int> tmp;
        for (int i = 0; i < 3; i++)
        {
            tmp.push_back(0);
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }
            int a = arr[i];
            int k = n - 1;
            for (int j = i + 1; j < n; j++)
            {
                if (j >= k)
                {
                    break;
                }
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }
                int b = arr[j];
                int c = 0 - a - b;
                if (b > c)
                {
                    break;
                }
                for (; k > j; k--)
                {
                    if (arr[k] < c)
                    {
                        break;
                    }
                    if (arr[k] == c)
                    {
                        tmp[0] = a;
                        tmp[1] = b;
                        tmp[2] = c;
                        res.push_back(tmp);
                        break;
                    }
                }
            }
        }
        return res;
    }
};
