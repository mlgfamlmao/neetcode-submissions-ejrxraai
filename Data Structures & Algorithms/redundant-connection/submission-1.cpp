class Solution {
    bool isValidTree(int n, vector<vector<int>>& adj){
        std::vector<int> vis(n+1, 0);
        std::queue<std::pair<int,int>> q;
        q.push({1,-1});
        vis[1]=1;
        int cnt{0};
        while(!q.empty()){
            auto [u,p] = q.front(); q.pop();
            cnt++;
            for (int nb : adj[u]){
                if (nb==p) continue;
                if (vis[nb]) return false;
                vis[nb]=1;
                q.push({nb,u});
            }
        }
        return cnt==n;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i{n-1}; i>=0; i--){
            std::vector<std::vector<int>> adj(n+1);
            for (int j{0}; j<n; j++){
                if (j==i) continue;
                adj[edges[j][0]].push_back(edges[j][1]);
                adj[edges[j][1]].push_back(edges[j][0]);
            }
            if (isValidTree(n, adj)) return edges[i];
        }
        return {};
    }
};