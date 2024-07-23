class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        int curr=0;
        int i=0;int j=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                if(j==m-1){
                    return i-j;
                }
                i++;j++;
            }
            else if(j!=0){
                i = i-j+1;
                j = 0;
            }
            else {
                i++;
                j=0;

            }
           
        }
        return -1;
    }
};
