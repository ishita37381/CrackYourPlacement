class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& dp) {
        if (n == 0 && m == 0) {
            return 1;
        }
        if (m < 0 or n < 0)
            return 0;
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int ans = solve(m - 1, n, dp) + solve(m, n - 1, dp);
        return dp[m][n] = ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, dp);
    }
};
