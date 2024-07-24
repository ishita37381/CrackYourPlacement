class Solution {
public:
void dfs(vector<vector<int>>& image, int sr, int sc, int color,int old){
    image[sr][sc]=color;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=sr+delrow[i];
        int ncol=sc+delcol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]!=color and image[nrow][ncol]==old ){
            dfs(image,nrow,ncol,color,old);
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        dfs(image,sr,sc,color,old);
        return image;
    }
};
