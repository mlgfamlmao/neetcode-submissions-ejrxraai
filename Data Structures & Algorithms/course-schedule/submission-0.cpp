class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> indeg(numCourses, 0);

        for (auto i : prerequisites){
            int course = i[0], pre = i[1];
            adj[pre].push_back(course);
            indeg[course]++;
        }
std::queue<int> q;
        for (int i{0}; i<numCourses; i++)
            if (indeg[i]==0) q.push(i);

        int finished{0};
        while(!q.empty()){
            int cur = q.front(); q.pop();
            finished++;
            for (int i : adj[cur]){
                indeg[i]--;
                if (indeg[i]==0) q.push(i);
            }
        }

        return finished == numCourses;
    }
};