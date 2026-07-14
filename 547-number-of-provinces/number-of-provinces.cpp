class Solution {
public:
    void dfs(int node,vector<bool>&visited,vector<vector<int>>& isConnected,int nodes){
        for(int i=0;i<nodes;i++){
            if(isConnected[node][i]==1 && !visited[i]){
                //if connected and not visited  -> visit that node
                visited[i] = true;
                dfs(i,visited,isConnected,nodes);
            } 
        }
    }
    void bfs(int node,vector<bool>&visited,vector<vector<int>>& isConnected,int nodes){
        queue<int> ComponentAtSameLevel;
        ComponentAtSameLevel.push(node); // pushing ultimate parent of all connected node
        while(!ComponentAtSameLevel.empty()){
            int eleInSameLevel = ComponentAtSameLevel.size();//lenth of elements in same level
            for(int i=0;i<eleInSameLevel;i++){
                int curr_node = ComponentAtSameLevel.front();
                ComponentAtSameLevel.pop();
                 for(int j=0;j<nodes;j++){
                        if(isConnected[curr_node][j]==1 && !visited[j]){
                        //if connected and not visited  -> visit that node
                        visited[j] = true;
                        ComponentAtSameLevel.push(j);
                    } 
                 }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      // obsrvation - 01
      //if two nodes are connected then they are part of same provinces...
      // so the question can be simplified into find the number of unconnected graph
      //intitution - 01
      //we can tranvese the graph with a array of unvisited and if our node is unvisited then use traversal for that node....
      //going with traversal through bfs
      //implmentation
      int nodes = isConnected.size();
      int provinces =0; // store total unconnected graph
      vector<bool> visited(nodes,false);//initializing with no visited node
      for(int node=0;node<nodes;node++){
        if(!visited[node]){//if not visited increase provices and traverse graph from that node to all connected component.
            provinces++;
            visited[node] = true;
            // dfs(node,visited,isConnected,nodes);
            bfs(node,visited,isConnected,nodes);
        }
      }
      return provinces;
    }
};