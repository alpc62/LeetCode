class Solution
{
public:
    int removeElement(vector<int>& a, int val)
    {
        int n = a.size();
        int i, j;
        for (i = j = 0; i < n; i++)
        {
            if (a[i] != val)
            {
                a[j++] = a[i];
            }
        }
        return j;
    }
};
