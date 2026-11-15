class Solution {
public:
#include<set>
    void solve(vector<int>& nums,int i,vector<int>output,set<vector<int>>&s){
        sort(output.begin(),output.end());
        s.insert(output);
        if(i==nums.size()){
            return;
        }
        
        solve(nums,i+1,output,s);
        output.push_back(nums[i]);
        solve(nums,i+1,output,s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>output;
        solve(nums,0,output,s);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};