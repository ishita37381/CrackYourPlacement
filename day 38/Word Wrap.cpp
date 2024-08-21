int dp[500][2000];

class Solution {
public:
int solve(int ind, vector<int> &nums, int remSpaces, int k) {
        if(ind >= nums.size()) {
            return 0;
        }
        if(dp[ind][remSpaces] != -1) {
            return dp[ind][remSpaces];
        }
        int ans;
        if(nums[ind] > remSpaces) {
            ans = (remSpaces+1)*(remSpaces+1) + 
            solve(ind+1, nums, k-nums[ind]-1, k);
        }
        else{
            int includeInThisLine = solve(ind+1, nums, remSpaces-nums[ind]-1, k);
            
            int excludeFromThisLine = (remSpaces+1)*
            (remSpaces+1) + solve(ind+1, nums, k-nums[ind]-1, k);
            
            ans = min(includeInThisLine, excludeFromThisLine);
        }
        dp[ind][remSpaces] = ans;
        return dp[ind][remSpaces];
    }

    int solveWordWrap(vector<int>nums, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, k, k);
    } 
};
