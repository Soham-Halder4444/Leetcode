class Solution {
public:
    int solve(vector<vector<char>>& board,string word,vector<vector<int>>&visited,int i,int j,int k){
        if(i<board.size() && i>=0 && j<board[0].size() && j>=0 && k<word.size() && k>=0){
            if(visited[i][j]==0 && board[i][j]==word[k]){
                visited[i][j]=1;
            }
            else{
                return false;
            }
        }
        else{
            if(k==word.size()){
                return true;
            }
            return false;
        }
        int res=solve(board,word,visited,i,j-1,k+1)||solve(board,word,visited,i,j+1,k+1)||solve(board,word,visited,i-1,j,k+1)||solve(board,word,visited,i+1,j,k+1);
        visited[i][j]=0;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int res=solve(board,word,visited,i,j,0);
                if(res>0){
                    return true;
                }
            }
        }
        return false;
    }
};