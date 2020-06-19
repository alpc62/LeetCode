struct zh
{
    int next, widx;
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

        map<string, int> word_map;
        for (int i = 0; i < nword; i++)
        {
            word_map[words[i]]++;
        }
        words.clear();
        map<int, int> idx2num;
        for (map<string, int>::iterator it = word_map.begin(); it != word_map.end(); ++it)
        {
            idx2num[words.size()] = it->second;
            words.push_back(it->first);
        }
        nword = words.size();

        map<int, zh> p;
        for (int i = 0; i < slen; i++)
        {
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
        vector<bool> simple_enough;
        for (int i = 0; i < slen; i++)
        {
            simple_enough.push_back(true);
        }
        map<int, int> mapxx;
        vector<int> jump;
        for (int i = 0; i < slen; i++)
        {
            if (!simple_enough[i])
            {
                continue;
            }
            mapxx.clear();
            jump.clear();
            int now = i;
            while (now >= 0 && now < slen)
            {
                jump.push_back(now);
                int widx = p[now].widx;
                if (widx < 0)
                {
                    break;
                }
                mapxx[widx]++;
                now = p[now].next;
            }
            bool is_enough = true;
            for (map<int, int>::iterator it = idx2num.begin(); it != idx2num.end(); ++it)
            {
                if (mapxx[it->first] < it->second)
                {
                    is_enough = false;
                    break;
                }
            }
            if (!is_enough)
            {
                for (size_t j = 0; j < jump.size(); j++)
                {
                    simple_enough[jump[j]] = false;
                }
            }
            else
            {
                mapxx = idx2num;
                for (size_t j = 0; j < jump.size(); j++)
                {
                    int widx = p[jump[j]].widx;
                    if (widx < 0 || mapxx[widx] <= 0)
                    {
                        break;
                    }
                    mapxx[widx]--;
                }
                bool is_match = true;
                for (map<int, int>::iterator it = mapxx.begin(); it != mapxx.end(); ++it)
                {
                    if (it->second > 0)
                    {
                        is_match = false;
                        break;
                    }
                }
                if (is_match)
                {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};
