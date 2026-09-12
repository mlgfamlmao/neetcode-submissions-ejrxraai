class Solution {
    void dfsBacktrack(std::vector<std::vector<std::string>>& results,
                       std::vector<bool>& cols,
                       std::vector<bool>& posDiagonal,
                       std::vector<bool>& negDiagonal,
                       std::vector<std::string>& board, int row, int n) {

        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int neg = row - col + n - 1;
            int pos = row + col;

            if (cols[col] || negDiagonal[neg] || posDiagonal[pos]) continue;

            cols[col] = true;
            negDiagonal[neg] = true;
            posDiagonal[pos] = true;
            board[row][col] = 'Q';

            dfsBacktrack(results, cols, posDiagonal, negDiagonal, board, row + 1, n);

            board[row][col] = '.';
            cols[col] = false;
            negDiagonal[neg] = false;
            posDiagonal[pos] = false;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> board(n, std::string(n, '.'));
        std::vector<bool> cols(n, false);
        std::vector<bool> posDiagonal(2 * n - 1, false);
        std::vector<bool> negDiagonal(2 * n - 1, false);

        dfsBacktrack(results, cols, posDiagonal, negDiagonal, board, 0, n);

        return results;
    }
};