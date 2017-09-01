class Solution
{
public:
    int removeDuplicates(vector<int>& a)
    {
        int n = a.size();
        if (n <= 1)
        {
            return n;
        }
        int i, j;
        i = 0;
        j = 1;
        while (i < n && j < n)
        {
            for (; j < n && a[j] == a[i]; j++);
            if (j < n)
            {
                a[++i] = a[j++];
            }
        }
        return i + 1;
    }
};
