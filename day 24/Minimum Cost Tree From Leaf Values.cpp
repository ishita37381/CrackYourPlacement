class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans=0;
        stack<int>st;
        st.push(INT_MAX);
        int n=arr.size();
        for(int i=0;i<n;i++){
           while(arr[i]>st.top())
			{
				int temp=st.top();
				st.pop();
				ans+=temp*min(arr[i],st.top());
			}
			st.push(arr[i]);
        }
        while(st.size()>=3){
            int curr=st.top();
            st.pop();
            ans+=curr*st.top();
        }
        return ans;
    }
};
