class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool is_safe(int node,vector<int>&color,int col,int n,bool graph[101][101]){
        for(int i=0;i<n;i++){
            if(graph[node][i] and color[i]==col)return 0;
        }
        return 1;
    }
    
    bool solve(bool graph[101][101],int m ,int n,vector<int>&color,int node){
        if(node==n)return 1;
        for(int i=1;i<=m;i++){
            if(is_safe(node,color,i,n,graph)){
                color[node]=i;
                if(solve(graph,m,n,color,node+1))return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
       vector<int>color(n+1);
       return solve(graph,m,n,color,0);
    }
};
