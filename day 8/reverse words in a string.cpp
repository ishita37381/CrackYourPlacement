class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.length();
        int i=0;
        while(i<n){
            while(i<n and s[i]==' ')i++;
            if(i>=n)break;
            int j=i+1;
            while(j<n and s[j]!=' ')j++;
            string sub=s.substr(i,j-i);
            if(res.length()==0)res=sub;
            else res=sub+" "+res;
            i=j+1;
        }
        return res;
    }
};
