class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int prev=ind-1;prev>=-1;prev--){
                int notake=dp[ind+1][prev+1];
                int take=0;
                if(prev==-1 or nums[ind]>nums[prev]){
                    take=1+dp[ind+1][ind+1];
                }
                dp[ind][prev+1]=max(take,notake);
            }
        }
        return dp[0][0];
    }
};
