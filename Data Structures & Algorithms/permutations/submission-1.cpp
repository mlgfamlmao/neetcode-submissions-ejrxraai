class Solution {
     void dfsBacktrack( std::vector<std::vector<int>>&result, std::vector<int> &current,
    std::vector<int> &nums, std::vector<int>&used){

        if (current.size() == (nums.size())){
            result.push_back(current);
            return;}

    for (int i{0}; i < nums.size(); i++){
        if (used[i]){
            continue;
        }
        used[i] = true;
        current.push_back(nums[i]);

        dfsBacktrack(result,current,nums,used);

        current.pop_back();
        used[i] = false;
    }

    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
          std::vector<std::vector<int>> result;
        std::vector<int> current;

std::vector<int> used(nums.size(), false);
        dfsBacktrack(result,current,nums,used);

        return result;
        
        
    }
};

