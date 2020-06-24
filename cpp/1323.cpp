class Solution
{
public:
    int maximum69Number (int num)
    {
        std::stack<int> st;

        while (num)
        {
            st.push(num % 10);
            num /= 10;
        }

        int res = 0;
        bool is_find = false;

        while (!st.empty())
        {
            int x = st.top();

            st.pop();
            if (!is_find && x == 6)
            {
                is_find = true;
                x = 9;
            }

            res = res * 10 + x;
        }

        return res;
    }
};
