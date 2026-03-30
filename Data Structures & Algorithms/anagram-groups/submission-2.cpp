class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> ans;

        for (int i = 0 ; i< strs.size(); i++){
            vector<int> id(26,0);
            for (auto it: strs[i]){
                id[it-'a']++;
            }
            string key;

            for (int j = 0 ; j < id.size(); j++){
                key+= id[j];
            } 
            ans[key].push_back(strs[i]);
            
          
        }
        vector<vector<string>> result;

        for (auto i : ans){
            result.push_back(i.second);
            
        }
        return result;
        
    }
};
