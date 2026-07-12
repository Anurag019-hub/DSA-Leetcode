class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjList_red(n);
        vector<vector<int>> adjList_blue(n);
        
        for (auto ele : redEdges) {
            adjList_red[ele[0]].push_back(ele[1]);
        }
        for (auto ele : blueEdges) {
            adjList_blue[ele[0]].push_back(ele[1]);
        }
        
        // min_dis[node][0] -> min distance to node if next edge must be red
        // min_dis[node][1] -> min distance to node if next edge must be blue
        vector<vector<int>> min_dis(n, vector<int>(2, INT_MAX));
        min_dis[0][0] = 0;
        min_dis[0][1] = 0;
        
        queue<vector<int>> q1; // {dist, node, next_color}
        q1.push({0, 0, 1}); // Start at 0, next edge is red (1)
        q1.push({0, 0, 0}); // Start at 0, next edge is blue (0)
        
        while (!q1.empty()) {
            int dist = q1.front()[0];
            int node = q1.front()[1];
            int col = q1.front()[2];
            q1.pop();
            
            if (col == 1) { // Next edge must be red
                for (auto ele : adjList_red[node]) {
                    // Next expected color after taking red will be blue (0)
                    if (min_dis[ele][0] > dist + 1) {
                        min_dis[ele][0] = dist + 1;
                        q1.push({dist + 1, ele, 0});
                    }
                }
            } else { // Next edge must be blue
                for (auto ele : adjList_blue[node]) {
                    // Next expected color after taking blue will be red (1)
                    if (min_dis[ele][1] > dist + 1) {
                        min_dis[ele][1] = dist + 1;
                        q1.push({dist + 1, ele, 1});
                    }
                }
            }
        }
        
        // Consolidate the two color paths into a single result array
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int ans = min(min_dis[i][0], min_dis[i][1]);
            res[i] = (ans == INT_MAX) ? -1 : ans;
        }
        
        return res;
    }
};