class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n{static_cast<int>(board.size())};
        int m{static_cast<int>(board[0].size())};
        queue<pair<int,int>> q;
        vector<int> dr{-1,1,0,0}, dc{0,0,-1,1};

        for(int i{0}; i<n; i++){
            if(board[i][0]=='O'){ board[i][0]='T'; q.push({i,0}); }
            if(board[i][m-1]=='O'){ board[i][m-1]='T'; q.push({i,m-1}); }
        }
        for(int j{0}; j<m; j++){
            if(board[0][j]=='O'){ board[0][j]='T'; q.push({0,j}); }
            if(board[n-1][j]=='O'){ board[n-1][j]='T'; q.push({n-1,j}); }
        }

        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(int k{0}; k<4; k++){
                int ni{i+dr[k]}, nj{j+dc[k]};
                if(ni>=0 && ni<n && nj>=0 && nj<m && board[ni][nj]=='O'){
                    board[ni][nj]='T';
                    q.push({ni,nj});
                }
            }
        }

        for(int i{0}; i<n; i++){
            for(int j{0}; j<m; j++){
                if(board[i][j]=='O') board[i][j]='X';

                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
    }
};