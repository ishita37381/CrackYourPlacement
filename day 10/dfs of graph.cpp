class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(int start,vector<int> adj[],vector<int>&ans,int vis[]){
        vis[start]=1;
        ans.push_back(start);
        for(auto it:adj[start]){
            if(!vis[it]){
                solve(it,adj,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int vis[V]={0};
       int start=0;
       vector<int>ans;
       solve(start,adj,ans,vis);
       return ans;
    }
};
