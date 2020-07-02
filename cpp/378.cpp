struct zh
{
    int i;
    int j;
    int v;
    zh() { }
    zh(int ii, int jj, int vv) { i = ii; j = jj; v = vv; }
};

static inline bool operator<(const zh& x, const zh& y)
{
    return x.v > y.v;
}

class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        zh res;
        int n = matrix.size();
        priority_queue<zh> heap;

        for (int i = 0; i < n; i++)
            heap.emplace(i, 0, matrix[i][0]);

        for (int i = 0; i < k; i++)
        {
            res = heap.top();
            heap.pop();
            if (res.j + 1 < n)
                heap.emplace(res.i, res.j + 1, matrix[res.i][res.j + 1]);
        }

        return res.v;
    }
};
