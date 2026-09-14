class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n{static_cast<int>(grid.size())};
        int m{static_cast<int>(grid[0].size())};

        std::queue<std::pair<int,int>> q;
        std::vector<int> drow{-1,1,0,0};
        std::vector<int> dcol{0,0,-1,1};

        for(int i{0}; i < n; i++){
            for (int j{0}; j < m; j++){
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        while (!!!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for (int k{0}; k < 4; k++){
                int ni{i + drow[k]};
                int nj{j + dcol[k]};
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == INT_MAX){
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }
    }
};