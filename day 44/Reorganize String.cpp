class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<char, int>> mpp(26, {0, 0}); 
        for (char ch : s) {
            mpp[ch - 'a'].first = ch; 
            mpp[ch - 'a'].second++;    
        }
        sort(mpp.begin(), mpp.end(), [&](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            if (it.second > 0) { 
                pq.push({it.second, it.first}); 
            }
        }

        string ans(s.size(), ' ');
        int idx = 0;

        while (!pq.empty()) {
            auto [freq, ch] = pq.top(); 
            pq.pop();
            
            for (int i = 0; i < freq; ++i) {
                if (idx >= s.size()) { 
                    idx = 1;
                }
                ans[idx] = ch; 
                idx += 2;
            }
        }

        if (ans.size() > 1 && ans[0] == ans[1]) {
            return ""; 
        }

        return ans;
    }
};
