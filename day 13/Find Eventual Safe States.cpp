class Solution {
public:
   bool dfs(int node,vector<int> adj[],vector<int>&path,vector<int>&vis,vector<int>&check){
    vis[node]=1;
    path[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,path,vis,check)){
                check[node]=0;
                return true;
            }
        }
        else if(path[it]){
            check[node]=0;
            return true;
        }
    }
    path[node]=0;
    check[node]=1;
    return false;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       int n=graph.size();
       vector<int>vis(n,0);
       vector<int>path(n,0);
       vector<int>check(n,0);
       vector<int>ans;
       vector<int>adj[n+1];
      for(int i=0; i<n; i++){
            adj[i].insert(adj[i].end(), graph[i].begin(), graph[i].end());
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,path,vis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]==1)ans.push_back(i);
        }
        return ans;
    }
};
