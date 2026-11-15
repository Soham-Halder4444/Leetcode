class Solution {
public:
    void dfs(unordered_map<string,vector<string>>&g,unordered_map<string,bool>&vis,vector<string>&temp,string node){
        vis[node]=true;
        for(auto n:g[node]){
            if(!vis[n]){
                temp.push_back(n);
                dfs(g,vis,temp,n);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string>acc;
        unordered_map<string,vector<string>>g;
        unordered_map<string,bool>vis;
        vector<vector<string>>ans;
        for(int i=0;i<accounts.size();i++){
            g[accounts[i][1]];
            for(int j = 2; j < accounts[i].size(); j++) {
                g[accounts[i][1]].push_back(accounts[i][j]);
                g[accounts[i][j]].push_back(accounts[i][1]);
                acc[accounts[i][j]]=accounts[i][0];
                vis[accounts[i][j]]=false;
            }
            acc[accounts[i][1]]=accounts[i][0];
            vis[accounts[i][1]]=false; 
        }
        for(auto &p : g){
            string node = p.first;
            if(!vis[node]){
                vector<string>temp;
                temp.push_back(acc[node]);
                temp.push_back(node);
                dfs(g,vis,temp,node);
                sort(temp.begin()+1, temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
};