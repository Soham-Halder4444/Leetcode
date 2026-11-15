class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& output, vector<vector<int>>& ans) {
        if(target == 0){
            ans.push_back(output);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            // Skip duplicates at the same recursion depth
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break; // pruning
            output.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i+1, output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, target, 0, output, ans);
        return ans;
    }
};