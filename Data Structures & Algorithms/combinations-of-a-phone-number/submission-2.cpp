class Solution {
        std::vector<std::string> letters = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

   void dfsBacktrack(std::string &digits, int index, std::vector<std::string>&result, std::string &current){
        if (digits.size() == index){
            result.push_back(current);

            return;
        }
        std::string options {letters[digits[index]- '0']};

        for (auto it : options ){
            current.push_back(it);
            dfsBacktrack(digits, index +1, result, current);
            current.pop_back();
            
        }

    }
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty()) return {};

        std::vector<std::string> results;
        std::string current;
        dfsBacktrack(digits, 0, results, current);
        return results;


        
    }
};
