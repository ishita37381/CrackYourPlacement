//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(M[a][b]==1)st.push(b);
            else st.push(a);
        }
        int candidate=st.top();
        st.pop();
        for(int j=0;j<n;j++){
            if(M[candidate][j]==1)return -1;
            
        }
        for(int i=0;i<n;i++){
            if(candidate!=i and M[i][candidate]==0)return -1;
        }
        return candidate;
    }
};
