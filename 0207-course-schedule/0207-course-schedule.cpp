class Solution {
public:
    bool dfs(int i,vector<list<int>>& adj,vector<bool>&visited,vector<bool>&adjvisited){
        visited[i]=true;
        adjvisited[i]=true;
        for(auto neighbour:adj[i]){
            if(!visited[neighbour]){
                bool checkfront=dfs(neighbour,adj,visited,adjvisited);
                if(checkfront){
                    return true;
                }
            }
            else if(adjvisited[neighbour]){
                return true;;
            }
        }
        adjvisited[i]=false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m=prerequisites.size();
        vector<list<int>> adj(numCourses);
        for(int i=0;i<m;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> adjvisited(numCourses, false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool ans=dfs(i,adj,visited,adjvisited);
                if(ans){
                    return false;
                }
            }
        }
        return true;
    }
};