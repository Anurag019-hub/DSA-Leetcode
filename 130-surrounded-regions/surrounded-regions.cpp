class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if (m == 0 || n == 0) return;

        queue<pair<int, int>> q;

        // Step 1: Push all boundary 'O's into the queue
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') { board[i][0] = 'E'; q.push({i, 0}); }
            if (board[i][n - 1] == 'O') { board[i][n - 1] = 'E'; q.push({i, n - 1}); }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') { board[0][j] = 'E'; q.push({0, j}); }
            if (board[m - 1][j] == 'O') { board[m - 1][j] = 'E'; q.push({m - 1, j}); }
        }

        // Directions for moving Up, Down, Left, Right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: Run BFS to mark all border-connected 'O's as 'E'
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Check bounds and if it's an unvisited 'O'
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = 'E';
                    q.push({nr, nc});
                }
            }
        }

        // Step 3: Final pass to flip 'O' -> 'X' and 'E' -> 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Captured
                } else if (board[i][j] == 'E') {
                    board[i][j] = 'O'; // Safe
                }
            }
        }
    }
};