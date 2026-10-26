class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        
        int validIslands = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    long long islandSum = 0;

                    while (!q.empty()) {
                        auto [curr_r, curr_c] = q.front();
                        q.pop();
                        
                        islandSum += grid[curr_r][curr_c];

                        for (int d = 0; d < 4; ++d) {
                            int nr = curr_r + dr[d];
                            int nc = curr_c + dc[d];

                            if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
                                if (!visited[nr][nc] && grid[nr][nc] > 0) {
                                    visited[nr][nc] = true;
                                    q.push({nr, nc});
                                }
                            }
                        }
                    }

                    if (islandSum % k == 0) {
                        validIslands++;
                    }
                }
            }
        }

        return validIslands;
    }
};