lass Solution {
 int f(int i,int j,vector<vector<int>>& A,vector<vector<int>>& dp)
    {
        if(i==0 && j==0) return A[0][0];
        if(i<0 || j<0) return INT_MAX;
        
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=min(f(i-1,j,A,dp),f(i,j-1,A,dp)) + A[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,A,dp);
    }
};
