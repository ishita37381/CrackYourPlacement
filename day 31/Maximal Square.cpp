class Solution {
public:
int solve(int i,int j,vector<vector<char>>& matrix,int n,int m,int& maxi,vector<vector<int>>&dp){
    if(i>=n or j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int right=solve(i,j+1,matrix,n,m,maxi,dp);
    int down=solve(i+1,j,matrix,n,m,maxi,dp);
    int dg=solve(i+1,j+1,matrix,n,m,maxi,dp);
    int curr=0;
    if(matrix[i][j]=='1'){
        curr=1+min(right,min(down,dg));
        dp[i][j]=curr;
        maxi=max(maxi,curr);
        return curr;
    }
    else return dp[i][j]=0;
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi=0;
        solve(0,0,matrix,n,m,maxi,dp);
        return maxi*maxi;
    }
};
