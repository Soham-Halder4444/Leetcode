class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Destination reached
            if (row == n - 1 && col == m - 1) {
                return effort;
            }

            for (int i = 0; i < 4; i++) {

                int nr = row + dx[i];
                int nc = col + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {

                    int newEffort = max(
                        effort,
                        abs(heights[row][col] - heights[nr][nc])
                    );

                    if (newEffort < dist[nr][nc]) {

                        dist[nr][nc] = newEffort;

                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};