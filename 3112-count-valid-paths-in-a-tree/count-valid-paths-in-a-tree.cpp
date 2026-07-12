class Solution {
public:
    vector<bool> isPrime;
    
    void sieve(int n) {
        isPrime.assign(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }
    }

    // DFS to map out and find the size of non-prime components
    void dfs(int node, vector<vector<int>>& adj, vector<int>& componentNodes, vector<bool>& visited) {
        visited[node] = true;
        componentNodes.push_back(node);
        for (int neighbor : adj[node]) {
            if (!isPrime[neighbor] && !visited[neighbor]) {
                dfs(neighbor, adj, componentNodes, visited);
            }
        }
    }

    long long countPaths(int n, vector<vector<int>>& edges) {
        sieve(n);
        
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<long long> compSize(n + 1, 0);
        vector<bool> visited(n + 1, false);

        // Step 1: Precalculate the sizes of all non-prime components
        for (int i = 1; i <= n; i++) {
            if (!isPrime[i] && !visited[i]) {
                vector<int> componentNodes;
                dfs(i, adj, componentNodes, visited);
                for (int node : componentNodes) {
                    compSize[node] = componentNodes.size();
                }
            }
        }

        long long totalPaths = 0;

        // Step 2: For each prime node, check its neighboring non-prime components
        for (int i = 1; i <= n; i++) {
            if (isPrime[i]) {
                long long sumOfSizes = 0;
                for (int neighbor : adj[i]) {
                    if (!isPrime[neighbor]) {
                        long long size = compSize[neighbor];
                        // Paths that span across two different non-prime components via prime 'i'
                        totalPaths += size * sumOfSizes; 
                        // Paths that start at prime 'i' and end in this non-prime component
                        totalPaths += size; 
                        sumOfSizes += size;
                    }
                }
            }
        }

        return totalPaths;
    }
};