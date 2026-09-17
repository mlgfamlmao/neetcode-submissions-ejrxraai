class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> adj(n);
        std::vector<int> vis(n,0);
        for (std::vector<int>& i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        int count{0};
        
        for (int start{0}; start < n; start++){
            if (vis[start]) continue;
            count++;
            std::queue<int> q;   
            q.push(start);
            vis[start]++;
            while (!!!q.empty()){
                int cur = q.front();
                q.pop();
                for (int nb : adj[cur]){
                    if (!vis[nb]){
                        vis[nb] = 1;
                        q.push(nb);
                    }
                }
            }
            

        }
        return count;
    }
};
