class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //check out 2 pointer sorted approach too
        unordered_map <int,int> hash;
        for (int i =0; i < nums.size();i++){
            if (hash.count(target - nums[i])){
                if (i < hash[(target)- nums[i]]){
                    vector<int> ans = {i,hash[target-nums[i]]};
                    return ans;
                }else{
                    vector<int>  ans = {hash[target- nums[i]], i}; return ans;
                }
            }else{
                hash[nums[i]]= i;
            }
        }

        
    }
};
