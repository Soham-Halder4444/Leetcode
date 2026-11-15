class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<char>>&grid){
        visited[i][j]=true;
        if(j+1<grid[i].size() && grid[i][j+1]=='1' &&!visited[i][j+1]){
            dfs(i,j+1,visited,grid);
        }
        if(i+1<grid.size() && grid[i+1][j]=='1' &&!visited[i+1][j]){
            dfs(i+1,j,visited,grid);
        }
        if(j-1>=0 && grid[i][j-1]=='1' && !visited[i][j-1]){
            dfs(i,j-1,visited,grid);
        }
        if(i-1>=0 && grid[i-1][j]=='1' && !visited[i-1][j]){
            dfs(i-1,j,visited,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return cnt;
    }
};