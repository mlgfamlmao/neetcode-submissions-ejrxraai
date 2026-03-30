class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i=0;

        
        unordered_map<string, vector<string>> ans;
        for (i; i < strs.size();i++){
            vector<int> id(26,0);
            for (auto it: strs[i]){
                id[it-'a']++;
            }
            string key;
            for (auto it: id){
                key += it;

            }
            ans[key].push_back(strs[i]);
            



        }
        vector<vector<string>> result;
        for (auto it : ans){
            result.push_back(it.second);
        }
        return result;
    }
};
