class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int n = grid.size();
            int m = grid[0].size();
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            //traverse the neighbours
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=r+i;
                    int ncol=c+j;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
            
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code <
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] and grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    } // tc = n*m same for sc
};
