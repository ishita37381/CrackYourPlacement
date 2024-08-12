class Solution {
public:
    int minCost(string c, vector<int>& t) {
        int n = c.size();
        int mini = 0;
        int i = 0 , j = 1;
        while(j<n){
            if(c[i]==c[j]){
                mini += min(t[i],t[j]);
                if(t[i]<t[j]) i=j,j++;
                else j++;
            }
            else{
                i=j,
                j++;
            }
        }
        return mini;
    }
};
