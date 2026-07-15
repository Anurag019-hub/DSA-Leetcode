class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {


//observations:
	// if all the nodes from node 1 go to the terminal node then th node is safe…


//intitution:
//so question is when not possible to connect it with terminal node… 
//so we can say that if cycle is present then only we can not do that…

//approach-01:
//we can make adjlist and indegree list for each ele
// check if there is cycle (we can do it by toposort bfs/dfs) if cycle is present ignore nodes present in cycle;

//Implementation:
int n = graph.size();
vector<vector<int>> adjList(n);//adjList will store the edges directed from another  node to current node 
vector<int> inDegree(n);//store the number of nodes are coming to that node
//traverse the graph and get all adjacent nodes of node…
for (int i = 0; i < n; i++) {
    for (int neighbor : graph[i]) { // "For every neighbor in graph[i]"
        adjList[neighbor].push_back(i);
        inDegree[i]++;
    }
}

//make a queue and put all the which are terminal (inDegree[i] == 0)
queue<int> bfs_queue;
for(int i=0;i<n;i++){
	if(inDegree[i]==0)
		 bfs_queue.push(i);
}

// after that we can check for cycle through topo sort if we take out node and remove the connection from its adjNode and if the indgeree become zero that mean there is no cycle…
vector<int> safeNode;
while(!bfs_queue.empty()){
	int curr_node = bfs_queue.front();
	safeNode.push_back(bfs_queue.front());
	bfs_queue.pop();
	for(int node: adjList[curr_node]){
		inDegree[node]--;
		if(inDegree[node]==0) // because there is no cycle and it can reach easily to terminal node..
			bfs_queue.push(node);
	}
}
sort(safeNode.begin(),safeNode.end());
return safeNode;

//TC - O(N^2);
//SC - O(3*N ~= N);
    }
};

