class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target)
    {
        int n = arr.size();
        vector<vector<int> > res;
        if (n < 4)
        {
            return res;
        }
        sort(arr.begin(), arr.end());
        vector<int> tmp;
        for (int i = 0; i < 4; i++)
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
            for (int j = i + 1; j < n; j++)
            {
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }
                int b = arr[j];
                int l = n - 1;
                for (int k = j + 1; k < n; k++)
                {
                    if (k >= l)
                    {
                        break;
                    }
                    if (k > j + 1 && arr[k] == arr[k - 1])
                    {
                        continue;
                    }
                    int c = arr[k];
                    int d = target - a - b - c;
                    if (c > d)
                    {
                        break;
                    }
                    for (; l > k; l--)
                    {
                        if (arr[l] < d)
                        {
                            break;
                        }
                        if (arr[l] == d)
                        {
                            tmp[0] = a;
                            tmp[1] = b;
                            tmp[2] = c;
                            tmp[3] = d;
                            res.push_back(tmp);
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
