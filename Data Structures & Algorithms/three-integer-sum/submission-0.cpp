class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());  
        vector<vector<int>> result;
        for(int i =0; i <nums.size(); i++){
            if (i > 0 && nums[i]== nums[i-1]){
                continue;
            }
            int l = i+1;
            int r = nums.size(); r--;
            while (l< r){
                int ThreeSum= nums[i] + nums[l] + nums[r];
                if (ThreeSum > 0) r--;
                else if (ThreeSum < 0 ) l++;

                else{
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l]== nums[l-1] && l<r){
                        l++;
                    }
                }


            }
        }return result;      
    }
};
