//User function Template for C++

class Solution {
  public:
  bool check(string temp){
      int i=0;
      int j=temp.length()-1;
      while(i<=j){
          if(temp[i]!=temp[j]){
              return 0;
          }
          i++;j--;
      }
      return 1;
  }
  void solve(string s,vector<vector<string>>&res,vector<string>&t1,int ind){
      int n=s.length();
      if(ind==n){
          res.push_back(t1);
          return;
      }
      for(int i=ind;i<n;i++){
          string temp=s.substr(ind,i-ind+1);
          if(check(temp)){
              t1.push_back(temp);
              solve(s,res,t1,i+1);
              t1.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string S) {
       
        vector<vector<string>>res;
        vector<string>t1;
        solve(S,res,t1,0);
        return res;
    }
};
