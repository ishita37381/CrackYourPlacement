/*You are required to complete this method*/

class Solution{
  public:
  vector<int> nextSmallerElement(int arr[], int n)
{
   stack<int>s ;
   s.push(-1);
   vector<int>v(n);
   for(int i=n-1;i>=0;i--){
       int curr=arr[i];
       while(s.top()!=-1&&arr[s.top()]>=curr)
       s.pop();
       v[i]=s.top();
       s.push(i);
   }
   return v;
}
vector<int> prevSmaller(int arr[], int n) {
    stack<int>s ;
   s.push(-1);
   vector<int>v(n);
   for(int i=0;i<n;i++){
       int curr=arr[i];
       while(s.top()!=-1&&arr[s.top()]>=curr)
       s.pop();
       v[i]=s.top();
       s.push(i);
   }
   return v;
}
 int largestRectangle(int heights[],int n) {
 // int n=heights.size();
  vector<int> next(n);
  next=nextSmallerElement(heights, n);
  vector<int>prev(n);
  prev=prevSmaller(heights, n);
  int area=INT_MIN;
  for(int i=0;i<n;i++){
    int l=heights[i];
    if(next[i]==-1)
    next[i]=n;
    int b=next[i]-prev[i]-1;
    int newArea=l*b;
    area=max(area,newArea);
  }
  return area;
 }
    int maxArea(int M[MAX][MAX], int n, int m) {
      int area=largestRectangle(M[0],m);
      for(int i=1;i<n;i++){
          for(int j=0;j<m;j++){
              if(M[i][j]!=0)
              M[i][j]=M[i][j]+M[i-1][j];
              else
              M[i][j]=0;
          }
          area=max(area,largestRectangle(M[i],m));
      }
      return area;
    }
};
