class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build the adjacency list: vector of vectors of pairs (neighbor, weight)
        // Size it to n + 1 since nodes are 1-indexed
        vector<vector<pair<int, int>>> adjlist(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adjlist[u].push_back({v, w});
        }

        // 2. Distance array initialized to INT_MAX
        vector<int> time(n + 1, INT_MAX);
        
        // 3. Min-heap priority queue storing pairs of (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Base case: distance to source node k is 0
        time[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If we found a shorter path to this node already, skip processing
            if (cost > time[node]) continue;

            // Traverse neighbors
            for (auto& ele : adjlist[node]) {
                int nextNode = ele.first;
                int weight = ele.second;

                if (time[nextNode] > cost + weight) {
                    time[nextNode] = cost + weight;
                    pq.push({time[nextNode], nextNode});
                }
            }
        }

        // 4. Find the maximum time taken to reach any reachable node
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == INT_MAX) return -1; // A node is unreachable
            maxTime = max(maxTime, time[i]);
        }

        return maxTime;
    }
};