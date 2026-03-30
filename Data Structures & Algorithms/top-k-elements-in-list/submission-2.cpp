class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int i;
        unordered_map <int , int> count;
        vector <vector<int>> bucket(nums.size()+1);
        for (i=0; i< nums.size(); i ++){
            count[nums[i]]+=1;
        }
        for (auto it : count){
            bucket[it.second].push_back(it.first);


        }
        vector<int> ans; 
        int counter= 0;
        for (i= bucket.size()-1; i>=0;i--){
            if (counter == k){
                return ans;
            }
            
                for (int i : bucket[i]){
                    ans.push_back(i);
                    if (ans.size()==k) return ans;
            



            }

        }
        return ans;
        
        
        
    }
};
