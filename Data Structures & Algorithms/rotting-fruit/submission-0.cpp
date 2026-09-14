class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n{static_cast<int>(grid.size())};
        int m{static_cast<int>(grid[0].size())};
        std::queue<std::pair<int,int>> q;
        std::vector<int> drow{-1,1,0,0};
        std::vector<int> dcol{0,0,-1,1};
        int time{0};
        int fresh{0};

        for (int i{0}; i < n; i++){
            for (int j{0}; j < m; j++){
                if (grid[i][j] == 2) q.push({i,j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        while (!q.empty() && fresh > 0){
            int sz = q.size();
            for (int s{0}; s < sz; s++){
                auto [i,j] = q.front();
                q.pop();
                for (int k{0}; k < 4; k++){
                    int ni{i + drow[k]};
                    int nj{j + dcol[k]};
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1){
                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};