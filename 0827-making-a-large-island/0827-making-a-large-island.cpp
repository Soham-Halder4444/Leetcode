class Solution {
public:
    void bfs(int&cnt,map<pair<int,int>,pair<int,int>>&parent,queue<pair<int,int>>&q,vector<vector<int>>&grid){
        if(q.empty()){
            return;
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        cnt++;
        for(int k=0;k<4;k++){
            int y=j+dy[k];
            int x=i+dx[k];
            if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==1 && parent.find({x,y})==parent.end()){
                parent[{x,y}]=parent[{i,j}];
                q.push({x,y});
                bfs(cnt,parent,q,grid);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        map<pair<int,int>,pair<int,int>> parent;
        map<pair<int,int>,int> count;
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && parent.find({i,j})==parent.end()){
                    queue<pair<int,int>>q;
                    parent[{i,j}]={i,j};
                    int cnt=0;
                    q.push({i,j});
                    bfs(cnt,parent,q,grid);
                    count[{i,j}]=cnt;
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    set<pair<int,int>>s;
                    int c=1;
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==1){
                            s.insert(parent[{x,y}]);
                        }
                    }
                    for(auto it:s){
                        c+=count[it];
                    }
                    ans=max(ans,c);
                }
            }
        }
        int nz=0;
        for(auto it:count){
            nz=max(nz,it.second);
        }
        return max(ans,nz);
    }
};