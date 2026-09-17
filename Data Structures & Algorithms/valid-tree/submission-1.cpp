class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (static_cast<int>(edges.size()) != n - 1) return false;

        std::vector<std::vector<int>> adj(n);
        for (std::vector<int> i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        std::vector<int> vis(n, 0);
        std::queue<std::pair<int,int>> q;
        q.push({0, -1});
        vis[0] = 1;
        int count{0};
        while(!q.empty()){
            auto [i, parent] = q.front();
            q.pop();      
            count++;
            for (int nb : adj[i]){
                if (!vis[nb]){
                    vis[nb] = 1;
                    q.push({nb, i});
                }
                else if (parent != nb){
                    return false;
                }    
                }
        }
        return count == n;
    }
};