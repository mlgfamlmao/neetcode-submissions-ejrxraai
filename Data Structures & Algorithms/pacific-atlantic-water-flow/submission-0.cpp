class Solution {
    void bfs(queue<pair<int,int>>& q, vector<vector<int>>& h, vector<vector<int>>& vis, int n, int m){
        vector<int> dr{-1,1,0,0}, dc{0,0,-1,1};
        while(!q.empty()){
            auto [i,j] = q.front(); q.pop();
            for(int k{0}; k<4; k++){
                int ni{i+dr[k]}, nj{j+dc[k]};
                if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && h[ni][nj]>=h[i][j]){
                    vis[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n{static_cast<int>(heights.size())};
        int m{static_cast<int>(heights[0].size())};
        std::vector<std::vector<int>> pac(n, std::vector<int>(m,0)), atl(n, std::vector<int>(m,0));
        std::queue<pair<int,int>> pq, aq;

        for(int i{0}; i<n; i++){
            pac[i][0]=1; pq.push({i,0});
            atl[i][m-1]=1; aq.push({i,m-1});
        }
        for(int j{0}; j<m; j++){
            pac[0][j]=1; pq.push({0,j});
            atl[n-1][j]=1; aq.push({n-1,j});
        }

        bfs(pq, heights, pac, n, m);
        bfs(aq, heights, atl, n, m);

        vector<vector<int>> res;
        for(int i{0}; i<n; i++)
            for(int j{0}; j<m; j++)
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});

        return res;
    }
};