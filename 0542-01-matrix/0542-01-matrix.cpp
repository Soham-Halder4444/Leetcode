class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&dist,vector<vector<int>>&mat,int d){
        dist[i][j]=min(d,dist[i][j]);
        int newd=d+1;
        if(j+1<mat[0].size() && mat[i][j+1]==1 && dist[i][j+1]>newd){
            dist[i][j+1] = newd;
            int nextd = newd;
            dfs(i, j+1, dist, mat, nextd);
        }
        if(i+1<mat.size() && mat[i+1][j]==1 && dist[i+1][j]>newd){
            dist[i+1][j] = newd;
            int nextd = newd;
            dfs(i+1,j,dist,mat,nextd);
        }
        if(j-1>=0 && mat[i][j-1]==1 && dist[i][j-1]>newd){
            dist[i][j-1] = newd;
            int nextd = newd;
            dfs(i,j-1,dist,mat,nextd);
        }
        if(i-1>=0 && mat[i-1][j]==1 && dist[i-1][j]>newd){
            dist[i-1][j] = newd;
            int nextd = newd;
            dfs(i-1,j,dist,mat,nextd);
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    int d=1;
                    if(j+1<=mat[0].size()-1 && mat[i][j+1]==1){
                        dfs(i,j+1,dist,mat,d);
                    }
                    if(i+1<=mat.size()-1 && mat[i+1][j]==1){
                        dfs(i+1,j,dist,mat,d);
                    }
                    if(j-1>=0 && mat[i][j-1]==1){
                        dfs(i,j-1,dist,mat,d);
                    }
                    if(i-1>=0 && mat[i-1][j]==1){
                        dfs(i-1,j,dist,mat,d);
                    }
                }
            }
        }
        return dist;
    }
};