class Solution {
public:
    #include<map>
    void solve(vector<vector<int>>& matrix,int m,int n,int i,int j,int value){
        if(i<0||i>=m||j<0||j>=n){
            return;
        }
        matrix[i][j]=0;
        if(value==1){
            //left
            solve(matrix,m,n,i,j-1,value);
        }
        else if(value==2){
            //right
            solve(matrix,m,n,i,j+1,value);
        }
        else if(value==3){
            //up
            solve(matrix,m,n,i-1,j,value);
        }
        else{
            //down
            solve(matrix,m,n,i+1,j,value);
        }
                    
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        map<int,vector<int>>z;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    z[i].push_back(j);
                }  
            }
        }
        int x,y;
        for(auto it:z){
            for(int col:it.second){
                x=it.first;
                y=col;
                solve(matrix,m,n,x,y-1,1);
                solve(matrix,m,n,x,y+1,2);
                solve(matrix,m,n,x-1,y,3);
                solve(matrix,m,n,x+1,y,4);
            }
            
        }
    }
};