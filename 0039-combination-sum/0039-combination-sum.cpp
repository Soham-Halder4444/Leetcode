class Solution {
public:
    void solve(vector<int>& candidates, int target,int index ,vector<int>output,set<vector<int>>&s){
        if(target<0 || index>=candidates.size()){
            return;
        }
        if(target==0){
            s.insert(output);
        }
        solve(candidates,target,index+1,output,s);
        int element=candidates[index];
        output.push_back(element);
        target=target-element;
        solve(candidates,target,index,output,s);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>output;
        solve(candidates,target,0,output,s);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};