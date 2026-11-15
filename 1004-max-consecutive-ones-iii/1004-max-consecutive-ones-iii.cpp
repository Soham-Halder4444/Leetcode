class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
    int l = 0;
    int maxi = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == 0) {
            q.push(i);

            if (q.size() > k) {
                l = q.front() + 1;
                q.pop();
            }
        }

        maxi = max(maxi, i - l + 1);
    }

    return maxi;
    }
};