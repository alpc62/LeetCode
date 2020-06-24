/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<int> postorder(Node* root)
    {
        vector<int> res;
        vector<pair<Node *, int>> arr;

        arr.emplace_back(root, 0);
        while (!arr.empty())
        {
            auto& cur = arr.back();

            if (!cur.first)
                arr.pop_back();
            else if (cur.second < cur.first->children.size())
                arr.emplace_back(cur.first->children[cur.second++], 0);
            else
            {
                res.push_back(cur.first->val);
                arr.pop_back();
            }
        }

        return res;
    }
};
