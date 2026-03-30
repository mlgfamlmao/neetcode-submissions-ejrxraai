class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(),1);
        int prefix = 1; int i;

        for(i=0 ; i< output.size(); i++){
            output[i]= prefix;
            prefix = prefix * nums[i];
        }
        int postfix = 1;

        for(i = nums.size()-1; i>=0; i--){
            output[i] = postfix * output[i];
            postfix = postfix * nums[i];


        }
        return output;




        



    }
};
