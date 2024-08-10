class Solution {
public:
    int minDeletions(string s) {
         unordered_map<char, int> mp;
        int n = s.length(); 
        unordered_set<int> st; 
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int ans = 0;
        for(auto &it : mp) {
            int temp = it.second;
            while(temp > 0 and st.find(temp) != st.end()) {
                ans++; 
                temp--;
            }
            st.insert(temp);
        }
        
        return ans;
    }
};
