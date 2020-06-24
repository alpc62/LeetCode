static std::vector<std::string> code_str = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

class Solution
{
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        std::set<std::string> res;

        for (const auto& s : words)
        {
            std::string msg;

            for (auto ch : s)
                msg += code_str[ch - 'a'];

            res.insert(msg);
        }

        return res.size();
    }
};
