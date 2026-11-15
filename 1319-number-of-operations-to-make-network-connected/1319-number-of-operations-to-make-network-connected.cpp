class Solution {
public:
    void dfs(vector<bool>&vis,int i,vector<vector<int>>&g){
        vis[i]=true;
        for(auto node:g[i]){
            if(!vis[node]){
                dfs(vis,node,g);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>g(n);
        if(connections.size()<n-1){
            return -1;
        }
        for(int i=0;i<connections.size();i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool>vis(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,i,g);
            }
        }
        return cnt-1;
    }
};