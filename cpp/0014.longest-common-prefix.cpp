class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (!strs.size())
        {
            return "";
        }
        string res = "";
        for (int i = 0; i < strs[0].length(); i++)
        {
            bool have_diff = false;
            for (int j = 1; j < strs.size(); j++)
            {
                if (i < strs[j].length() && strs[0][i] == strs[j][i])
                {
                    continue;
                }
                have_diff = true;
                break;
            }
            if (have_diff)
            {
                break;
            }
            res += strs[0][i];
        }
        return res;
    }
};
