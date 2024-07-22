class Solution {
public:
void solve(int total,int open,int close,string s,vector<string>&ans){
    if(s.size()==total){
        ans.push_back(s);
        return;
    }
    if(open>close){
        solve(total,open,close+1,s+')',ans);
        if(open<total/2){
            solve(total,open+1,close,s+'(',ans);
 }}
    else{
        solve(total,open+1,close,s+'(',ans);
    }
}
    vector<string> generateParenthesis(int n) {
        int total=2*n;
        vector<string>ans;
        solve(total,0,0,"",ans);
        return ans;
    }
};
