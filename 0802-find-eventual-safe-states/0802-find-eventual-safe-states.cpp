class Solution {
public:
    bool dfs(int n, vector<int>& state,
             vector<vector<int>>& graph) {

        // Already confirmed safe
        if(state[n] == 2) {
            return true;
        }

        // Currently visiting or already found unsafe
        if(state[n] == 1) {
            return false;
        }

        state[n] = 1;

        for(int i = 0; i < graph[n].size(); i++) {

            if(!dfs(graph[n][i], state, graph)) {
                return false;
            }
        }

        // All neighbours are safe
        state[n] = 2;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        vector<int> ans;

        int n = graph.size();

        // 0 = Unvisited
        // 1 = Visiting / Unsafe
        // 2 = Safe
        vector<int> state(n, 0);

        for(int i = 0; i < n; i++) {

            if(dfs(i, state, graph)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};