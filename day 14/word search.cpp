class Solution {
public:
bool find(vector<vector<char>>& board, vector<vector<int>>& vis, string& word,
              vector<pair<int,int>>& dir, int row, int col, int idx){
                if(idx==word.size())return true;
                if(row<0 or row>=board.size() or col<0 or col>=board[0].size() 
                 || vis[row][col] || board[row][col] != word[idx])return false;
                vis[row][col]=1;
                for(auto d:dir){
                    int nrow=row+d.first;
                    int ncol=col+d.second;
                    if(find(board,vis,word,dir,nrow,ncol,idx+1))return true;
                }
                vis[row][col]=0;
                return false;
              }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>dir={{1,0},{0,-1},{0,1},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] and find(board,vis,word,dir,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
