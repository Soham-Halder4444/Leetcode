class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>& nums,vector<int>&output,int i){
        if(i==nums.size()){
            ans.push_back(output);
            return;
        }
        solve(ans,nums,output,i+1);
        output.push_back(nums[i]);
        solve(ans,nums,output,i+1);
        output.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(ans,nums,output,0);
        return ans;
    }
};