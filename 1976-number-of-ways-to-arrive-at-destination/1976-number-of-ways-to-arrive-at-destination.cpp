class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);

        for(auto &r : roads) {
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }

        vector<long long> time(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        int mod = 1e9 + 7;

        time[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()) {

            auto [d,node] = pq.top();
            pq.pop();

            if(d > time[node]) continue;

            for(auto it : g[node]) {

                int adjNode = it.first;
                int wt = it.second;

                if(d + wt < time[adjNode]) {

                    time[adjNode] = d + wt;

                    ways[adjNode] = ways[node];

                    pq.push({time[adjNode],adjNode});
                }

                else if(d + wt == time[adjNode]) {

                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};