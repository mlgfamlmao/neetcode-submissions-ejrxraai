class Solution {
public:
    bool isAnagram(string s, string t) {
        // or u can use int  arr[26] method;
        unordered_map<char,int> freq;
        if (s.length() != t.length() ) {return false;}
        for (int i = 0; i< s.length();i++){
            freq[s[i]]++;
            freq[t[i]]--;
            
            

        }
        for (auto i : freq){
            if (i.second !=0){return false;}
        }return true;
    }
};
