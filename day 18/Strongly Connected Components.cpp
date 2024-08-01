class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
	void revdfs(int node,vector<int>&vis,vector<vector<int>>&adjT){
	    vis[node] = 1; 
    for(auto it: adjT[node]) {
        if(!vis[it]) {
            revdfs(it, vis, adjT); 
        }
    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                //i to it
                //reverse
                adjT[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int top=st.top();
            st.pop();
            if(!vis[top]){
                cnt++;
                revdfs(top,vis,adjT);
            }
        }
        return cnt;
    }
};
