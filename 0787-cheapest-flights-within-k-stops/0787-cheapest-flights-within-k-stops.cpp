class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for(int i = 0; i < flights.size(); i++){
            graph[flights[i][0]].push_back({
                flights[i][1], flights[i][2]
            });
        }

        queue<pair<int,vector<int>>> q;

        // dist[node][edges used]
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));

        dist[src][0] = 0;

        q.push({0, {src, 0}});

        while(!q.empty()){

            int prc = q.front().first;
            int d = q.front().second[0];
            int stop = q.front().second[1];

            q.pop();

            if(prc > dist[d][stop]){
                continue;
            }

            // Maximum allowed edges = k+1
            if(stop <= k){

                for(int i = 0; i < graph[d].size(); i++){

                    int next = graph[d][i].first;
                    int newCost = prc + graph[d][i].second;
                    int newStop = stop + 1;

                    if(newCost < dist[next][newStop]){

                        dist[next][newStop] = newCost;

                        q.push({
                            newCost,
                            {next, newStop}
                        });
                    }
                }
            }
        }

        int ans = INT_MAX;

        for(int i = 0; i <= k+1; i++){
            ans = min(ans, dist[dst][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};