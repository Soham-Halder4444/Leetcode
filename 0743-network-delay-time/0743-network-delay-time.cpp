class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>g(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            g[u].push_back({v,w});
        }
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            int d=q.top().first;
            int n=q.top().second;
            q.pop();
            for(int i=0;i<g[n].size();i++){
                if(d+g[n][i].second<dist[g[n][i].first]){
                    q.push({d+g[n][i].second,g[n][i].first});
                    dist[g[n][i].first]=d+g[n][i].second;
                }
            }
        }
        int mini=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            mini=max(mini,dist[i]);
        }
        return mini;
    }
};