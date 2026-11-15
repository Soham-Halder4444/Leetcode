class Solution {
public:
    int find(int x, unordered_map<int,int>& parent) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x], parent);
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> xp, yp, count, parent;

        int l = 1;

        for(int i = 0; i < stones.size(); i++) {
            int x = stones[i][0];
            int y = stones[i][1];

            if(xp.find(x) == xp.end() && yp.find(y) == yp.end()) {
                xp[x] = l;
                yp[y] = l;

                parent[l] = l;
                count[l] = 1;

                l++;
            }
            else if(xp.find(x) == xp.end()) {
                int id = find(yp[y], parent);

                xp[x] = id;
                count[id]++;
            }
            else if(yp.find(y) == yp.end()) {
                int id = find(xp[x], parent);

                yp[y] = id;
                count[id]++;
            }
            else {
                int a = find(xp[x], parent);
                int b = find(yp[y], parent);

                if(a == b) {
                    count[a]++;
                }
                else {
                    parent[b] = a;

                    count[a] += count[b] + 1;
                    count[b] = 0;

                    yp[y] = a;
                }
            }
        }

        int ans = 0;

        for(auto it : count) {
            if(it.second > 0)
                ans += it.second - 1;
        }

        return ans;
    }
};