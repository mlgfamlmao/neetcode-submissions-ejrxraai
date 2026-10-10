
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::queue<std::pair<std::string,int>> q;
        q.push({beginWord, 1});
        std::unordered_set<std::string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()){
            std::string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps;

            for (int i{0}; i < word.size(); i++){
                char original = word[i];
                for (char ch{'a'}; ch <= 'z'; ch++){
                    if (ch == original) continue;
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};
