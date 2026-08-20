class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }

        int leftptr{0};

        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);

        for (int i{0}; i < s1.size(); i++) {
            hash1[s1[i] - 'a']++;
        }

      
        for (int i{0}; i < s1.size(); i++) {
            hash2[s2[i] - 'a']++;
        }

        
        if (hash1 == hash2) {
            return true;
        }

        
        for (int i{static_cast<int>(s1.size())}; i < s2.size(); i++) {

           
            hash2[s2[i] - 'a']++;

            
            hash2[s2[leftptr] - 'a']--;

            leftptr++;

            
            if (hash1 == hash2) {
                return true;
            }
        }

        return false;
    }
};