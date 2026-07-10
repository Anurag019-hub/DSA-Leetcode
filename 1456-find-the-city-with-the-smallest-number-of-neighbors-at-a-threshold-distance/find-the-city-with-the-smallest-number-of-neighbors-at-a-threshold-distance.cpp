class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,1e9));
       for(auto ele : edges){
         int start = ele[0];
         int end = ele[1];
         int wt = ele[2];
         matrix[start][end] = wt;
         matrix[end][start] = wt;
       }
// 1. FLOYD-WARSHALL ALGORITHM (Keep this intact)
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
    }
}

// 2. COUNT NEIGHBORS & FIND BEST CITY (Do not modify the matrix here!)
int ans = -1;
int mini = INT_MAX;

for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        // A city doesn't count itself, and must be within the threshold
        if (i != j && matrix[i][j] <= distanceThreshold) {
            cnt++;
        }
    }
    
    // If it's a tie, we want the greater city index (hence <=)
    if (cnt <= mini) {
        mini = cnt;
        ans = i;
    }
}

return ans;
    }
};