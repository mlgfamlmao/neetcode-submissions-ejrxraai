class Solution {
    void dfsBacktrack(int index, std::vector<std::vector<int>>&result, std::vector<int> &current,
    std::vector<int> &nums){

        if (index == (nums.size())){
            result.push_back(current);
            return;}

        dfsBacktrack(index+ 1,result, current, nums);

        current.push_back(nums[index]);

        dfsBacktrack(index+1,result, current , nums);
        current.pop_back();
    }
    
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        dfsBacktrack(0, result,current , nums);

        return result;
     
    }
};
