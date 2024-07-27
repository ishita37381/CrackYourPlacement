class Solution {
public:
bool check(int start,int color[],vector<int>adj[]){
    color[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
               color[it]=!color[node];
               q.push(it);
            }
            else if(color[it]==color[node])return false;
        }
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0;i<V;i++){
	        color[i]=-1;
	    }
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	        if(check(i,color,adj)==false)return false;
	            
	        }
	    }
	    return true;
	    
	}

};
