class Solution {
public:
    bool hasCycle(int curr, unordered_map<int, vector<int>>& edges, vector<int>& visited) {
        if (visited[curr] == 1) return true;  // Found a back-edge (cycle detected)
        if (visited[curr] == 2) return false; // Already fully processed, no need to re-check

        visited[curr] = 1; // Mark as processing

        for (int neighbor : edges[curr]) {
            if (hasCycle(neighbor, edges, visited)) {
                return true;
            }
        }

        visited[curr] = 2; // Mark as fully processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        unordered_map<int, vector<int>> edges;
        
        // Build adjacency list: course -> dependent courses
        for (auto& ele : prerequisites) {
            edges[ele[1]].push_back(ele[0]);
        }

        // Check each course for cycles
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(i, edges, visited)) {
                    return false; // If a cycle is found, finishing all courses is impossible
                }
            }
        }

        return true;
    }
};