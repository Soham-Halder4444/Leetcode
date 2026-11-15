class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n-1][n-1])
            return -1;

        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1},  {1,0},   {1,1}
        };

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1; // visited

        int len = 1;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if(x == n-1 && y == n-1)
                    return len;

                for(auto it : dir) {
                    int nx = x + it.first;
                    int ny = y + it.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<n &&
                    grid[nx][ny] == 0) {

                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            len++;
        }

        return -1;
    }
};