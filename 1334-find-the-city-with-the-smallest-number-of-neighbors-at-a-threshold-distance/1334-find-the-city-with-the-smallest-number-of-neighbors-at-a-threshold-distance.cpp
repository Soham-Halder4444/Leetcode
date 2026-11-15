class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    matrix[i][j]=0;
                }
                else{
                    matrix[i][j]=1e9;
                }
            }
        }
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            matrix[u][v]=wt;
            matrix[v][u]=wt;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        vector<pair<int,int>>ans;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                if(matrix[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            ans.push_back({i,cnt});
            mini=min(mini,cnt);
        }
        int val;
        for(int i=0;i<ans.size();i++){
            if(ans[i].second==mini){
                val=ans[i].first;
            }
        }
        return val;
    }
};