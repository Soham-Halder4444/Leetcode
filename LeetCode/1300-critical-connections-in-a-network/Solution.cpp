class Solution {
public:
    void dfs(int n,int &time,int parent,vector<vector<int>>&adj,vector<int>&low,vector<int>&dis,unordered_map<int,bool>&vis,vector<vector<int>>&ans){
        vis[n]=true;
        dis[n]=low[n]=time++;
        for(auto neigh:adj[n]){
            if(neigh==parent){
                continue;
            }
            if(!vis[neigh]){
                dfs(neigh,time,n,adj,low,dis,vis,ans);
                low[n]=min(low[n],low[neigh]);
                if(low[neigh]>dis[n]){
                    vector<int>temp;
                    temp.push_back(n);
                    temp.push_back(neigh);
                    ans.push_back(temp);
                }
            }
            else{
                low[n]=min(low[n],dis[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>low(n,INT_MAX);
        vector<int>dis(n,INT_MAX);
        int time=0;
        int parent=-1;
        unordered_map<int,bool>vis;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,time,parent,adj,low,dis,vis,ans);
            }
        }
        return ans;
    }
};