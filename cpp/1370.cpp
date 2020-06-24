class Solution
{
public:
    string sortString(string s)
    {
        string res;
        std::map<char, int> counter;

        for (auto ch : s)
            counter[ch]++;

        bool r = false;
        bool finish = false;

        while (!finish && !counter.empty())
        {
            finish = true;
            if (r)
            {
                for (auto it = counter.rbegin(); it != counter.rend(); ++it)
                {
                    if (it->second > 0)
                    {
                        finish = false;
                        res += it->first;
                        it->second--;
                    }
                }
            }
            else
            {
                for (auto it = counter.begin(); it != counter.end(); ++it)
                {
                    if (it->second > 0)
                    {
                        finish = false;
                        res += it->first;
                        it->second--;
                    }
                }
            }

            r = !r;
        }

        return res;
    }
};
