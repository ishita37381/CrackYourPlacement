// User function Template for C++

class Solution{
public:
void dfs(int row,int col,vector<vector<char>>&mat,vector<vector<int>>&vis,int delrow[],int delcol[]){
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
            dfs(nrow,ncol,mat,vis,delrow,delcol);
        }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //traverse boundaries
        //first row 
        for(int j=0;j<m;j++){
            if(!vis[0][j] and mat[0][j]=='O'){
                dfs(0,j,mat,vis,delrow,delcol);
            }
            //last row 
            if(!vis[n-1][j] and mat[n-1][j]=='O'){
                dfs(n-1,j,mat,vis,delrow,delcol);
            }
        }
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] and mat[i][0]=='O'){
                dfs(i,0,mat,vis,delrow,delcol);
            }
            //last col
            if(!vis[i][m-1] and mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis,delrow,delcol);
            }
        }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(!vis[i][j] and mat[i][j]=='O'){
                   mat[i][j]='X';
               }
           }
       }
        return mat;
    }
};
