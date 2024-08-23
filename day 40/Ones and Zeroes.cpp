class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int,int>>v;
        int tz=0;
        int to = 0;
        for(int i=0;i<strs.size();i++){
            int zers=0;
            int ones = 0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j] == '0') zers++;
                else ones++;
            }
            tz+=zers;
            to+=ones;
            v.push_back({zers,ones});
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 0;
        for(int k=0;k<v.size();k++){
            int tempzer = v[k].first;
            int tempone = v[k].second;
            for(int i=m;i>=tempzer;i--){
                for(int j=n;j>=tempone;j--){
                    dp[i][j] = max(dp[i][j] , 1+dp[i-tempzer][j-tempone]);
                }
            }
        }
        return dp[m][n];
    }
};
