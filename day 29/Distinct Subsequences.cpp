class Solution {
public:
   int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
       if(j<0)return 1;
       if(i<0)return 0;
       int result=0;
       if(dp[i][j]!=-1)return dp[i][j];
     if(s[i]==t[j])
      { int take=solve(i-1,j-1,s,t,dp);
       int notake=solve(i-1,j,s,t,dp);
       result=take+notake;
       }
       else result=solve(i-1,j,s,t,dp);
     return   dp[i][j]=result;
    
   }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};
