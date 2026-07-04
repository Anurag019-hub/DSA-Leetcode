class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;
        int total_ones=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1) total_ones++;
                if (grid[i][j] == 1 && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool is_end = false;
                    int imi_ans = 0;
                    while (!q.empty()) {
                        imi_ans++;
                        auto [a, b] = q.front();
                        q.pop();

                        if (a - 1 >= 0 && !visited[a - 1][b] && grid[a - 1][b]==1 ) {
                            visited[a - 1][b]=true;
                            q.push({a - 1, b});
                        } else if (a == 0)
                            is_end = true;

                        if (a + 1 <= m - 1 && !visited[a + 1][b] && grid[a + 1][b]==1) {
                            q.push({a + 1, b});
                            visited[a + 1][b] = true;
                        } else if (a == m-1)
                            is_end = true;

                        if (b - 1 >= 0 && !visited[a][b - 1] && grid[a][b - 1]==1 ) {
                            q.push({a, b - 1});
                            visited[a][b - 1] = true;
                        } else if (b == 0)
                            is_end = true;

                        if (b + 1 <= n - 1 && !visited[a][b + 1] && grid[a][b + 1]==1) {
                            q.push({a, b + 1});
                            visited[a][b + 1] = true;
                        } else if (b == n-1)
                            is_end = true;
                    }
                    if (is_end)
                        ans += imi_ans;
                }
            }
        }
        return total_ones - ans;
    }
};