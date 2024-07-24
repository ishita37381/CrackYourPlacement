class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V]={0};
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            bfs.push_back(temp);
            for(auto it:adj[temp]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                } 
            }
        }
        return bfs;
    }
};
