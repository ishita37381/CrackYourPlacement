class Solution {
public:
int solve(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
    int n=prices.size();
    int profit=0;
    if(ind==n or cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    //buy
    if(buy==0){
      profit=max(solve(ind+1,0,cap,prices,dp),-prices[ind]+solve(ind+1,1,cap,prices,dp));
    }
    //sell
    if(buy==1){
      profit=max(solve(ind+1,1,cap,prices,dp),prices[ind]+solve(ind+1,0,cap-1,prices,dp));
    }
return dp[ind][buy][cap]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,0,k,prices,dp);
    }
};
