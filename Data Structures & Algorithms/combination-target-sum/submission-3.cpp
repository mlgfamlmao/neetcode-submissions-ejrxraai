class Solution {
    void dfsBacktrack(std::vector<int>& nums, int target, int index,
                       std::vector<std::vector<int>>& result,
                       std::vector<int>& current, int currentSum) {

        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        if (currentSum > target || index == nums.size()) {
            return;
        }

        
        
        
        dfsBacktrack(nums, target, index + 1, result, current, currentSum);

        current.push_back(nums[index]);
        dfsBacktrack(nums, target, index, result, current, currentSum + nums[index]);
        current.pop_back();

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;

        dfsBacktrack(nums, target, 0, result, current, 0);

        return result;
    }
};