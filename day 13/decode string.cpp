class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<string>str;
        stack<int>nums;
        string curr="";
        int cnt=0;
        int repeat=0;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                cnt=cnt*10+(s[i]-'0');
            }
            else if(isalpha(s[i])){
                curr=curr+s[i];
            }
            if(s[i]=='['){
                nums.push(cnt);
                str.push(curr);
                curr="";
                cnt=0;
            }
            if(s[i]==']'){
                repeat=nums.top();
                nums.pop();
                string temp=curr;
                for(int i=1;i<repeat;i++){
                    curr+=temp;
                }
                if(!str.empty())curr=str.top()+curr;
                str.pop();
            }
        }
        return curr;
        
    }
};
