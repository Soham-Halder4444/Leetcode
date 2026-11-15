class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>>&visited,vector<vector<int>>&grid,int&cnt,bool&move){
        visited[i][j]=true;
        cnt++;
        if(i==0||i==grid.size()-1||j==0||j==grid[0].size()-1){
            move=true;
        }
        if(j+1<grid[i].size() && grid[i][j+1]==1 &&!visited[i][j+1]){
            dfs(i,j+1,visited,grid,cnt,move);
        }
        if(i+1<grid.size() && grid[i+1][j]==1 &&!visited[i+1][j]){
            dfs(i+1,j,visited,grid,cnt,move);
        }
        if(j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1]){
            dfs(i,j-1,visited,grid,cnt,move);
        }
        if(i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j]){
            dfs(i-1,j,visited,grid,cnt,move);
        }
        if(move==true){
            cnt=0;
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    int cnt=0;
                    bool move=false;
                    dfs(i,j,visited,grid,cnt,move);
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};