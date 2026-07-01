class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q1;
        q1.push({sr,sc});
        vector<vector<int>> visited(m,vector<int>(n,0));
        while(!q1.empty()){
            int t = q1.size();
           
            for(int i=0;i<t;i++){
                 pair<int,int> curr = q1.front();
                 q1.pop();
                 int a =curr.first;
                 int b = curr.second;
                 int pre_col = image[a][b];
                 image[a][b] = color;
                 visited[a][b] = 1;
                 if(a>0  && image[a-1][b]==pre_col && visited[a-1][b]==0  ) q1.push({a-1,b});
                 if(a<m-1&& image[a+1][b]==pre_col && visited[a+1][b]==0 ) q1.push({a+1,b});
                 if(b>0 && image[a][b-1]==pre_col && visited[a][b-1]==0 ) q1.push({a,b-1});
                 if(b<n-1 && image[a][b+1]==pre_col && visited[a][b+1]==0 ) q1.push({a,b+1});
            }
        }
        return image;
    }
};