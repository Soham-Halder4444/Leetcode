class Solution {
public:
    void addsolution(vector<vector<string>>& ans, vector<vector<int>>& board, int n) {
    vector<string> temp;

    for (int row = 0; row < n; row++) {
        string s = "";

        for (int col = 0; col < n; col++) {
            if (board[row][col] == 1) {
                s.push_back('Q');
            }
            else {
                s.push_back('.');
            }
        }

        temp.push_back(s);
    }

    ans.push_back(temp);
}
    bool issafe(int row,int col,vector<vector<int>>&board,int n){
        int x=row;
        int y=col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n && y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>>&ans,vector<vector<int>>&board,int n){
        if(col==n){
            addsolution(ans,board,n);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,board,n)){
                board[row][col]=1;
                solve(col+1,ans,board,n);
                board[row][col]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<string>>ans;
        solve(0,ans,board,n);
        return ans;
    }
};