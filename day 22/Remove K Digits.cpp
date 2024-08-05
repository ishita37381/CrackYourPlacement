class Solution {
public:
    string removeKdigits(string num, int k) {
     stack<int>st;
     for(char ch:num){
        int value=ch-'0';
        while(!st.empty() and k>0 and st.top()>value){
            st.pop();
            k--;
        }
        st.push(value);
     }   
     while(k>0){
        st.pop();
        k--;
     }
     string ans="";
     while(!st.empty()){
        ans+=st.top()+'0';
        st.pop();
     }
      while (ans.size() > 0 && ans.back() == '0') ans.pop_back();
      reverse(ans.begin(), ans.end());

        return ans.size() > 0 ? ans : "0";
    }
};
