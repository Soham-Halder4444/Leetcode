class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&time,vector<vector<int>>&grid,int&t){
        if(t>time[i][j]){
            return;
        }
        time[i][j]=min(t,time[i][j]);
        int t2=t+1;
        if(j+1<grid[i].size() && grid[i][j+1]==1){
            dfs(i,j+1,time,grid,t2);
        }
        if(i+1<grid.size() && grid[i+1][j]==1){
            dfs(i+1,j,time,grid,t2);
        }
        if(j-1>=0 && grid[i][j-1]==1){
            dfs(i,j-1,time,grid,t2);
        }
        if(i-1>=0 && grid[i-1][j]==1){
            dfs(i-1,j,time,grid,t2);
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>time(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    int t=0;
                    dfs(i,j,time,grid,t);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(time[i][j]!=INT_MAX && grid[i][j]==1){
                    ans=max(ans,time[i][j]);
                }
                else if(grid[i][j]==1 && time[i][j]==INT_MAX){
                    return -1;
                }
                else{
                    continue;
                }
            }
        }
        return ans;
    }
};