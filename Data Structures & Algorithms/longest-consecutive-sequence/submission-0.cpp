class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        for (int i = 0; i < nums.size(); i++){
            numset.insert(nums[i]);

        }

        int longest = 0;

        for (int i = 0; i< nums.size(); i++){
            if (!numset.count(nums[i]-1)){
                int length = 1;
                int current = nums[i];
                while (numset.count(current+1)){
                    length+=1;
                    current++;

                }longest = max(longest, length);
            }

        }
        return longest;
        
    }
};
