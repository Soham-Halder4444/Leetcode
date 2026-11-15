class Solution {
public:
    void dfs(int node,unordered_map<int,list<int>>&adj,unordered_map<int,bool>&visited){
        visited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size=isConnected.size();
        unordered_map<int,bool>visited;
        unordered_map<int,list<int>>adj;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i==j){
                    continue;
                }
                if(isConnected[i][j]){ 
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<size;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,adj,visited);
            }
        }
        return cnt;
    }
};