class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A)
    {
        for (auto& arr : A)
        {
            std::reverse(arr.begin(), arr.end());
            for (auto& x : arr)
                x = 1 - x;
        }

        return A;
    }
};
