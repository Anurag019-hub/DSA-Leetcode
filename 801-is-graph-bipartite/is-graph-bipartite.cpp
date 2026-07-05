class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<bool>visited(nodes,false);
        vector<bool>color(nodes);
        for(int j=0;j<nodes;j++)
        if(!visited[j])
       { queue<int> q1;
        q1.push(j);
        visited[j] = true;
        color[j]=false;
        while(!q1.empty()){
            int level_size = q1.size();
            for(int i=0;i<level_size;i++){
                 int curr = q1.front();
                bool curr_col = color[curr];
                q1.pop();
                for(auto ele:graph[curr]){
                    if(!visited[ele]){
                        visited[ele] = true;
                        q1.push(ele);
                        color[ele] = !curr_col;
                    }else{
                        if(color[ele]==curr_col) return false;
                    }
                }
            }
        }}
        return true;
    }
};