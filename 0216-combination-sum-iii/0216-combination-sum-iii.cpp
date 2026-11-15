class Solution {
public:
    void solve(int num,int k,int n,vector<int>output,vector<vector<int>>&ans){
        if(k == 0) {
            if(n == 0)
                ans.push_back(output);
            return;
        }
        if(num > 9 || k < 0 || n < 0 || num>n || k*(2*num+(k-1))/2 > n)
            return;

        solve(num+1,k,n,output,ans);
        output.push_back(num);
        solve(num+1,k-1,n-num,output,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(1,k,n,output,ans);
        return ans;
    }
};