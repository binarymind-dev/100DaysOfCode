#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);

        for(auto& p : prerequisites)
            adj[p[1]].push_back(p[0]);

        function<bool(int)> hasCycle = [&](int node) -> bool {
            visited[node] = 1; // currently visiting
            for(int next : adj[node]){
                if(visited[next] == 1) return true;  // cycle
                if(visited[next] == 0 && hasCycle(next)) return true;
            }
            visited[node] = 2; // fully processed
            return false;
        };

        for(int i = 0; i < numCourses; i++)
            if(visited[i] == 0 && hasCycle(i)) return false;

        return true;
    }
};
