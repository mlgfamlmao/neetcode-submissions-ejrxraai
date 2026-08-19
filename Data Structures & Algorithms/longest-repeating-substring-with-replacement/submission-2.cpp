class Solution {
public:
    int characterReplacement(string s, int k) {

        int leftptr {0};
        int maxFrequency {0};
        int maxLength = {0};

        std::vector<int> count(26,0);

        for (int i {0}; i < s.size(); i++) {

            count[s[i] - 'A']++;

            maxFrequency = std::max(maxFrequency,
                                count[s[i] - 'A']);

            int windowLength = i - leftptr + 1;

            if (windowLength - maxFrequency > k) {
                count[s[leftptr] - 'A']--;
                leftptr++;
            }

            maxLength = std::max(maxLength,
                            i - leftptr + 1);
        }

        return maxLength;
    }
};