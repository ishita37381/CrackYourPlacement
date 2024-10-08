class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int weight=it[2];
                if(dist[u]!=1e8 and dist[u]+weight<dist[v]){
                    dist[v]=dist[u]+weight;
                }
            }
        }
        //for nth iteration
        for(auto it:edges){
            int u=it[0];
                int v=it[1];
                int weight=it[2];
                if(dist[u]!=1e8 and dist[u]+weight<dist[v]){
                    return {-1};
                }
        }
        return dist;
    }
};
