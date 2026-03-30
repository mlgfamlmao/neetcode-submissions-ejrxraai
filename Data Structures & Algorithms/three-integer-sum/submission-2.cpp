class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;   // ✅ fix

            while (l < r) {
                int ThreeSum = nums[i] + nums[l] + nums[r];

                if (ThreeSum > 0) r--;
                else if (ThreeSum < 0) l++;       // ✅ fix
                else {
                    result.push_back({nums[i], nums[l], nums[r]});

                    l++;
                                            

                    while (l < r && nums[l] == nums[l - 1]) l++;   
                    while (l < r && nums[r] == nums[r + 1]) r--;   
                }
            }
        }

        return result;
    }
};