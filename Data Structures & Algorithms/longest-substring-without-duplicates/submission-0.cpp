class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hash;

        int maxSubstring{0};
        int leftptr{0};

        for (int i{0}; i < s.size(); i++) {

            if (hash.count(s[i]) &&
                hash[s[i]] >= leftptr) {

                leftptr = hash[s[i]] + 1;
            }

            hash[s[i]] = i;

            int windowLength = i - leftptr + 1;

            maxSubstring = std::max(maxSubstring, windowLength);
        }

        return maxSubstring;
    }
};