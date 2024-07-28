class Solution {
public:
   bool canplace(vector<int>&stalls,int dist,int cows){
       int cnt=1;
       int last_pos=stalls[0];
       for(int i=1;i<stalls.size();i++){
           if(stalls[i]-last_pos>=dist){
               cnt++;
               last_pos=stalls[i];
           }
           if(cnt>=cows)return true;
       }
       return false;
   }
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls.back()-stalls.front();
        int best=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canplace(stalls,mid,k)){
                best=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return best;
    }
};
