class Solution {
    bool dfsBacktracker(std::vector<std::vector<char>>& board, std::string& word,
                         int i, int j, int index) {

        if (index == word.size()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if (board[i][j] != word[index]) return false;

        char tempChar = board[i][j];
        board[i][j] = '*';

        bool found = dfsBacktracker(board, word, i + 1, j, index + 1) ||
                     dfsBacktracker(board, word, i - 1, j, index + 1) ||
                     dfsBacktracker(board, word, i, j + 1, index + 1) ||
                     dfsBacktracker(board, word, i, j - 1, index + 1);

        board[i][j] = tempChar;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowLength = board.size();
        int colLength = board[0].size();

        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < colLength; j++) {
                if (dfsBacktracker(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};