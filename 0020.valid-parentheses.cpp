class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.length();
        if (!n)
        {
            return true;
        }
        stack<char> a;
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            switch (ch)
            {
                case '(':
                case '[':
                case '{':
                    a.push(ch);
                    break;
                case ')':
                case ']':
                case '}':
                    if (a.empty() || (a.top() + 1 != ch && a.top() + 2 !=ch))
                    {
                        return false;
                    }
                    a.pop();
                    break;
                default:
                    return false;
                    break;
            }
        }
        return a.empty();
    }
};
