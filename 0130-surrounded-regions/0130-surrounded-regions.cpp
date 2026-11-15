class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j]='a';
        if(j+1<board[i].size() && board[i][j+1]=='O'){
            dfs(i,j+1,board);
        }
        if(i+1<board.size() && board[i+1][j]=='O'){
            dfs(i+1,j,board);
        }
        if(j-1>=0 && board[i][j-1]=='O'){
            dfs(i,j-1,board);
        }
        if(i-1>=0 && board[i-1][j]=='O'){
            dfs(i-1,j,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        int i=0;
        int j=0;
        while(j<n){
            if(board[i][j]=='O'){
                dfs(i,j,board);
            }
            j++;
        }
        i=m-1;
        j=0;
        while(j<n){
            if(board[i][j]=='O'){
                dfs(i,j,board);
            }
            j++;
        }
        j=0;
        i=1;
        while(i<m-1){
            if(board[i][j]=='O'){
                dfs(i,j,board);
            }
            i++;
        }
        j=n-1;
        i=1;
        while(i<m-1){
            if(board[i][j]=='O'){
                dfs(i,j,board);
            }
            i++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X' || board[i][j]=='O'){
                    board[i][j]='X';
                }
                else{
                    board[i][j]='O';
                }
            }
        }

    }
};