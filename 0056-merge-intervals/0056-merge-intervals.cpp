class Solution {
public:
    #include<deque>
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        for (auto &interval : intervals) {
            if (ans.empty() || ans.back()[1] < interval[0]) {
                // no overlap, add new interval
                ans.push_back(interval);
            } else {
                // overlap, merge with last
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};