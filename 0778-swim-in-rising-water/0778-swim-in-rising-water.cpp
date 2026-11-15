class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid.size(),false));
        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > q;
        q.push({grid[0][0],{0,0}});
        int time=INT_MIN;
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        while(!q.empty()){
            int wt=q.top().first;
            time=max(time,wt);
            int i=q.top().second.first;
            int j=q.top().second.second;
            vis[i][j]=true;
            q.pop();
            if(i==n-1 && j==n-1){
                return time;
            }
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<n && y>=0 && y<n && vis[x][y]==false){
                    q.push({grid[x][y],{x,y}});
                }
            }
        }
        return -1;
    }
};