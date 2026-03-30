class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> freq;
        // or use set 
        unordered_set<int> exists;
        //map
        for (auto i : nums){
            freq[i]++;
            if (freq[i] > 1){return true;

            }
        }
        //set
        for (auto i: nums){
            if (exists.count(i)){
                return true;
            }else{exists.insert(i);}
        }
        return false;
        
    }
};