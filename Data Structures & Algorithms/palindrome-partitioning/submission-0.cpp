class Solution {
    bool isPalindrome(const std::string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void dfs(std::string& s, int index, std::vector<std::string>& current,
             std::vector<std::vector<std::string>>& results) {

        if (index == s.size()) {
            results.push_back(current);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (!isPalindrome(s, index, i)) continue;

            current.push_back(s.substr(index, i - index + 1));
            dfs(s, i + 1, current, results);
            current.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> current;
        dfs(s, 0, current, results);
        return results;
    }
};