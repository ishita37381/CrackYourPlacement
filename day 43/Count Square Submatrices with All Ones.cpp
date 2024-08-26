class Solution {
private:
    int dp[301][301];
    int solve(int n, int m, vector<vector<int>>& matrix, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= m || matrix[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = solve(n, m, matrix, i, j + 1);
        int down = solve(n, m, matrix, i + 1, j);
        int diagonal = solve(n, m, matrix, i + 1, j + 1);
        dp[i][j] = 1 + min({right, down, diagonal});
        return dp[i][j];
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));

        int n = matrix.size();  
        int m = matrix[0].size(); 
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 1){
                    ans += solve(n, m, matrix, i, j);
                }
            }
        }

        return ans;
    }
};
