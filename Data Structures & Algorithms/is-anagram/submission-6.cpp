class Solution {
public:
    bool isAnagram(string s, string t) {
        // or u can use int  arr[26] method;
        int arr[26]= {0};
        if (s.length() != t.length() ) {return false;}
        for (int i = 0; i< s.length();i++){
            arr[s[i]- 'a']++;
            arr[t[i]-'a']--;
            
            

        }
        for (auto i : arr){
            if (i != 0){return false;}
        }return true;
    }
};
