class SingleMap
{
public:
    static SingleMap *getInstance()
    {
        static SingleMap obj;
        return &obj;
    }
    map<int, string> i2r;
    map<string, int> r2i;
private:
    SingleMap()
    {
        c[0] = "";
        c[1] = "I";
        c[2] = "II";
        c[3] = "III";
        c[4] = "IV";
        c[5] = "V";
        c[6] = "VI";
        c[7] = "VII";
        c[8] = "VIII";
        c[9] = "IX";
        c[10] = "X";
        c[20] = "XX";
        c[30] = "XXX";
        c[40] = "XL";
        c[50] = "L";
        c[60] = "LX";
        c[70] = "LXX";
        c[80] = "LXXX";
        c[90] = "XC";
        c[100] = "C";
        c[200] = "CC";
        c[300] = "CCC";
        c[400] = "CD";
        c[500] = "D";
        c[600] = "DC";
        c[700] = "DCC";
        c[800] = "DCCC";
        c[900] = "CM";
        c[1000] = "M";
        c[2000] = "MM";
        c[3000] = "MMM";
        for (int i = 1; i <= 3999; i++)
        {
            string r = intToRoman(i);
            i2r[i] = r;
            r2i[r] = i;
        }
    }
    string intToRoman(int num)
    {
        string res = "";
        stack<int> s;
        for (int x = 1; num; num /= 10)
        {
            s.push((num % 10) * x);
            x *= 10;
        }
        while (!s.empty())
        {
            res += c[s.top()];
            s.pop();
        }
        return res;
    }
    map<int, string> c;
};

class Solution
{
public:
    string intToRoman(int num)
    {
        SingleMap *sm = SingleMap::getInstance();
        return sm->i2r[num];
    }
};
