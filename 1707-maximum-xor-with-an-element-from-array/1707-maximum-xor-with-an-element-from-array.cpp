class Solution {
public:
     struct Node {
        Node* links[2];

        Node() {
            links[0] = links[1] = nullptr;
        }

        bool containsKey(int bit) {
            return links[bit] != nullptr;
        }

        Node* get(int bit) {
            return links[bit];
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }
    };

    class Trie {
    private:
        Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->containsKey(bit)) {
                    node->put(bit, new Node());
                }

                node = node->get(bit);
            }
        }

        int getMax(int num) {
            Node* node = root;
            int maxNum = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (node->containsKey(1 - bit)) {
                    maxNum |= (1 << i);
                    node = node->get(1 - bit);
                } else {
                    node = node->get(bit);
                }
            }

            return maxNum;
        }
    };
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> offlineQueries;

        for (int i = 0; i < queries.size(); i++) {
            offlineQueries.push_back({
                queries[i][0],
                queries[i][1],
                i
            });
        }

        sort(offlineQueries.begin(), offlineQueries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> ans(queries.size(), -1);
        Trie trie;
        int j = 0;

        for (auto& query : offlineQueries) {
            int x = query[0];
            int m = query[1];
            int idx = query[2];

            while (j < nums.size() && nums[j] <= m) {
                trie.insert(nums[j]);
                j++;
            }

            if (j > 0) {
                ans[idx] = trie.getMax(x);
            }
        }

        return ans;
    
    }
};