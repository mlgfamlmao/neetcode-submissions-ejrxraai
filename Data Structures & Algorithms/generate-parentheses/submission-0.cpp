class Solution {
    void dfsBacktrack(int n, std::vector<std::string>& results, std::string& current,
                       int open, int close) {
        if (current.size() == n * 2) {
            results.push_back(current);
            return;
        }

        if (open < n) {
            current.push_back('(');
            dfsBacktrack(n, results, current, open + 1, close);
            current.pop_back();
        }

        if (open > close) {
            current.push_back(')');
            dfsBacktrack(n, results, current, open, close + 1);
            current.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> results;
        std::string current;

        dfsBacktrack(n, results, current, 0, 0);

        return results;
    }
};