class Solution {
public:
    void dfs(int i,int j,int color,vector<vector<bool>>&visited,vector<vector<int>>&grid){
        int c=grid[i][j];
        grid[i][j]=color;
        visited[i][j]=true;
        if(j+1<grid[i].size() && grid[i][j+1]==c &&!visited[i][j+1]){
            dfs(i,j+1,color,visited,grid);
        }
        if(i+1<grid.size() && grid[i+1][j]==c &&!visited[i+1][j]){
            dfs(i+1,j,color,visited,grid);
        }
        if(j-1>=0 && grid[i][j-1]==c && !visited[i][j-1]){
            dfs(i,j-1,color,visited,grid);
        }
        if(i-1>=0 && grid[i-1][j]==c && !visited[i-1][j]){
            dfs(i-1,j,color,visited,grid);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(sr,sc,color,visited,image);
        return image;
    }
};