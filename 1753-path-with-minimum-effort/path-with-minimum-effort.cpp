class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int col = heights[0].size();
        vector<vector<int>> val(rows,vector<int>(col,INT_MAX));
        // Explicitly make it a Min-Heap using vector and greater comparison
priority_queue<pair<int, pair<int, int>>, 
               vector<pair<int, pair<int, int>>>, 
               greater<pair<int, pair<int, int>>>> pq;
        vector<pair<int,int>> pos = {{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({0,{0,0}});
        val[0][0] = 0;
       // 1. Initialize a 2D vector 'val' with INT_MAX, and val[0][0] = 0
// 2. Priority queue stores: {effort, {row, col}} using greater<> for a min-heap

while (!pq.empty()) {
    auto [effort, cell] = pq.top();
    int curr_x = cell.first;
    int curr_y = cell.second;
    pq.pop();
    
    // If we reached the bottom-right corner, this is the definitive answer
    if (curr_x == rows - 1 && curr_y == col - 1) {
        return effort;
    }
    
    // Skip if we have already found a path with lower effort to this cell
    if (effort > val[curr_x][curr_y]) continue;
    
    for (auto& ele : pos) {
        int next_x = curr_x + ele.first;
        int next_y = curr_y + ele.second;
        
        if (next_x >= 0 && next_x < rows && next_y >= 0 && next_y < col) {
            // The effort for the next jump is the MAX of the current path's effort
            // AND the absolute difference to the next cell
            int jump_effort = abs(heights[curr_x][curr_y] - heights[next_x][next_y]);
            int new_effort = max(effort, jump_effort);
            
            // Only push to queue if it's strictly better than what we found before
            if (new_effort < val[next_x][next_y]) {
                val[next_x][next_y] = new_effort;
                pq.push({new_effort, {next_x, next_y}});
            }
        }
    }
}
        return -1;
    }
};