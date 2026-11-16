class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int max=m*n;
        int startingx=0;
        int endingx=m-1;
        int startingy=0;
        int endingy=n-1;
        int count=0;
        vector<int>ans;
        while(1){
            int y=startingy;
            while(y<=endingy){
                ans.push_back(matrix[startingx][y++]);
                count++;
            }
            startingx++;
            if(count==max){
                    break;
            }
            int x=startingx;
            while(x<=endingx){
                ans.push_back(matrix[x++][endingy]);
                count++;
            }
            endingy--;
            if(count==max){
                    break;
            }
            int z=endingy;
            while(z>=startingy){
                ans.push_back(matrix[endingx][z--]);
                count++;
            }
            endingx--;
            if(count==max){
                    break;
            }
            int w=endingx;
            while(w>=startingx){
                ans.push_back(matrix[w--][startingy]);
                count++;
            }
            startingy++;
            if(count==max){
                    break;
            }
        }
        return ans;
    }
};