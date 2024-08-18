class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool check(int n, int x, int y)
    {
        return x >= 0 and x < n and y >= 0 and y < n; 
    }

public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, queue<pair<int, pair<int, int>>> &q, int cx, int cy)
    {
        visited[cx][cy] = true;
        q.push({0, {cx, cy}});

        for(int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(check(int(grid.size()), nx, ny) and grid[nx][ny] == 1 and !visited[nx][ny])
                dfs(grid, visited, q, nx, ny);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = int(grid.size());
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(n, vector<bool> (n));

        bool found = false;
        for(int x = 0; x < n; ++x) 
        {
            for(int y = 0; y < n; ++y)
            {    
                if (grid[x][y] == 1 and !visited[x][y])
                {
                    found = true;
                    dfs(grid, visited, q, x, y);
                    break;
                }
            }

            if (found) break;
        }

        int ans = 10001;
        while(!q.empty())
        {
            int dist = q.front().first;
            int cx = q.front().second.first;
            int cy = q.front().second.second;
            q.pop();

            for(int i = 0; i < 4; ++i)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (check(n, nx, ny) and grid[nx][ny] == 0 and !visited[nx][ny])
                {
                    q.push({dist + 1, {nx, ny}});
                    visited[nx][ny] = true;
                }
                else if (check(n, nx, ny) and grid[nx][ny] == 1 and !visited[nx][ny])
                    ans = min(ans, dist);
            }
        }

        return ans;
    }
};
