class Solution {
    void dfsBacktrack(int index, std::vector<std::vector<int>> &results, std::vector<int>&nums, std::vector<int>&current){
        
            results.push_back(current);
         
        
        for(int i{index}; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;

            }
            current.push_back(nums[i]);
            dfsBacktrack(i +1, results, nums, current);
            current.pop_back();
        }
        

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        std::vector<std::vector<int>> results;
        std::vector<int> current;
        std::sort(nums.begin() ,nums.end());
        dfsBacktrack(0,results,nums,current);
        return results;

        
    }
};
