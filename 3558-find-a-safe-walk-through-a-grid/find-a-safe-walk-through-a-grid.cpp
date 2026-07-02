class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        // max_health[i][j] stores the highest remaining health found so far for cell (i, j)
        vector<vector<int>> max_health(m, vector<int>(n, -1));
        
        // Max-heap stores: {remaining_health, row, col}
        priority_queue<vector<int>> pq;
        
        // Account for starting cell cost
        int start_health = health - grid[0][0];
        if (start_health <= 0) return false;
        
        pq.push({start_health, 0, 0});
        max_health[0][0] = start_health;
        
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int h = curr[0];
            int r = curr[1];
            int c = curr[2];
            
            // Reached the destination with at least 1 health remaining
            if (r == m - 1 && c == n - 1 && h >= 1) return true;
            
            // Skip if we already found a path that gets here with more health
            if (h < max_health[r][c]) continue;
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_health = h - grid[nr][nc];
                    
                    // Only explore this neighbor if it yields a higher health state
                    if (next_health > max_health[nr][nc] && next_health >= 1) {
                        max_health[nr][nc] = next_health;
                        pq.push({next_health, nr, nc});
                    }
                }
            }
        }
        
        return false;
    }
};