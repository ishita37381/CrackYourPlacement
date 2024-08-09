class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128,0);
         for (char c : t) {
            map[c]++;
        }
        int n=s.size();
        int m=t.size();
        int counter=m,begin=0,end=0,head=0;
        int len=INT_MAX;
        while(end<n){
            if(map[s[end++]]-- > 0){
                counter--;
            }
            while(counter==0){
                if(end-begin< len){
                    head=begin;
                    len=end-begin;
                }
                if(map[s[begin++]]++ ==0){
                    counter++;
                }
            }
        }
        return len==INT_MAX?"":s.substr(head,len);
    }
};
