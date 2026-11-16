class Solution {
public:
    #include<map>
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int,int> m;
        vector<int> ans;
        int repeated = -1, missing = -1;

        // Count frequencies
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                m[grid[i][j]]++;
            }
        }

        // Check from 1 to n*n
        for(int num=1; num<=n*n; num++){
            if(m[num] == 2) repeated = num;
            if(m[num] == 0) missing = num;
        }

        ans.push_back(repeated);
        ans.push_back(missing);
        return ans;
    }
};