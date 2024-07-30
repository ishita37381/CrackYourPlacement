class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k)continue;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                if(cost+wt<dist[adjNode] and stops<=k){
                    dist[adjNode]=cost+wt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
            }
            if(dist[dst]==INT_MAX)return -1;
            return dist[dst];
        
    }
};
