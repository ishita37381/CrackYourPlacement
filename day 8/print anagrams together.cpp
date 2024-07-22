class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& st) {
       vector<vector<string>> v;
       map<string,vector<string>>m;
       for(auto x:st){
           string t=x;
           sort(x.begin(),x.end());
           m[x].push_back(t);
       }
       for(auto x:m){
           v.push_back(x.second);
       }
       return v;
    }
};
