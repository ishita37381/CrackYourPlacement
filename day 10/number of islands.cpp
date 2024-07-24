class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>> &vis,queue<pair<int,int>> &q,int i,int j,int n,int m)
    {

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();

            vis[curr.first][curr.second]=1;
            for(int i=0;i<4;i++)
            {
                int nr=curr.first+dx[i];
                int nc=curr.second+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    q.push({i,j});
                    bfs(grid,vis,q,i,j,n,m);
                }
            }
        }
        
        return count;
    }
};
