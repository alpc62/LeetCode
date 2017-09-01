struct zh
{
    int st, next, widx;
}tmp;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        int slen = s.length();
        int nword = words.size();
        if (!nword)
        {
            return res;
        }
        int wlen = words[0].size();
        if (!wlen)
        {
            for (int i = 0; i < slen; i++)
            {
                res.push_back(i);
            }
            return res;
        }
        map<int, zh> p;
        for (int i = 0; i < slen; i++)
        {
            tmp.st = i;
            tmp.next = -1;
            tmp.widx = -1;
            for (int j = 0; j < nword; j++)
            {
                bool is_match = true;
                int ii;
                for (ii = 0; ii < wlen && i + ii < slen; ii++)
                {
                    if (s[i + ii] != words[j][ii])
                    {
                        break;
                    }
                }
                if (ii < wlen)
                {
                    is_match = false;
                }
                if (is_match)
                {
                    tmp.next = i + wlen;
                    tmp.widx = j;
                    break;
                }
            }
            p[i] = tmp;
        }
        set<int> idx_set;
        for (int i = 0; i < slen; i++)
        {
            idx_set.clear();
            int now = i;
            while (now >= 0 && now < slen)
            {
                int widx = p[now].widx;
                if (widx < 0 || idx_set.count(widx) > 0)
                {
                    break;
                }
                idx_set.insert(widx);
                now = p[now].next;
            }
            if (idx_set.size() == nword)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
