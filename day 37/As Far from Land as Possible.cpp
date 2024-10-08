class Solution {
public:

    bool isValid(int r,int c,int n,vector<vector<int>>& grid)
    {
        if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0)
            return true;
        return false;
    }

    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        
        if(q.size()==n*n)
            return -1;

        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,-1,0,1};

        int ans=0;

        while(!q.empty())
        {
            int sz=q.size();
            ans++;
            while(sz--)
            {
                int r=q.front().first,c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nr=r+dx[i],nc=c+dy[i];
                    if(isValid(nr,nc,n,grid)){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return ans-1;
    }
};
