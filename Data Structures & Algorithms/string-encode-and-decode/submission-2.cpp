class Solution {
public:
// go for length based version if you want.

    string encode(vector<string>& strs) {

        string encoded;
        for (auto &str : strs) {
    encoded += str + ":;";
}

        return encoded;
        

    }

    vector<string> decode(string s) {
    vector<string> result;
    string temp;

    for (int i = 0; i < s.size(); i++) {
        
        if (i + 1 < s.size() && s[i] == ':' && s[i + 1] == ';') {
            result.push_back(temp);
            temp.clear();
            i++; 
        } else {
            temp += s[i];
        }
    }
    return result;
}

};
