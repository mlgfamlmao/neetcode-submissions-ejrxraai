class Solution {
    void bfs(int row, int col, std::vector<std::vector<char>>& grid, std::vector<std::vector<int>>& vis, int n, int m){
        vis[row][col] = 1;
        std::queue<std::pair<int,int>> q;
        std::vector<int> drow{-1,1,0,0};
        std::vector<int> dcol{0,0,-1,1};
        q.push({row,col});
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for (int k{0}; k<4; k++){
                int ni{i + drow[k]};
                int nj{j + dcol[k]};

                if ((ni >=0 && ni < n) && (nj >= 0 && nj < m) && grid[ni][nj] == '1' && !vis[ni][nj]){
                    q.push({ni,nj});
                    vis[ni][nj] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n {static_cast<int>(grid.size())};
        int m {static_cast<int>(grid[0].size())};
        std::vector<std::vector<int>> vis(n, std::vector<int>(m,0));
        int cnt{0};
        for (int i{0}; i < n; i++){
            for (int j{0}; j < m; j++){
                if (!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};