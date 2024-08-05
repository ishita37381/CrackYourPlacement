

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str,int k,int start,string&ans){
        int n=str.length();
        if(n==start or k==0){
            ans=max(ans,str);
            return;
        }
        solve(str,k,start+1,ans);
        for(int i=start+1;i<n;i++){
            if(str[start]<str[i]){
                swap(str[i],str[start]);
                solve(str,k-1,start+1,ans);
                swap(str[i],str[start]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
      string ans="";
      solve(str,k,0,ans);
      return ans;
      
    }
};
