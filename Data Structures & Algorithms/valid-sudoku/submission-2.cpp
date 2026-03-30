class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows, cols;
        unordered_map<int, unordered_set<char>> squares; 

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
                if (board[i][j] == '.') {
                    continue; 
                }

                char current_val = board[i][j];
                
                
                int square_index = (i / 3) * 3 + (j / 3); 
                
                
                if (rows[i].count(current_val) || 
                    cols[j].count(current_val) ||
                    squares[square_index].count(current_val)) {
                    return false;
                }

                rows[i].insert(current_val);
                cols[j].insert(current_val);
                squares[square_index].insert(current_val);
            }
        }
        return true;
    }
};