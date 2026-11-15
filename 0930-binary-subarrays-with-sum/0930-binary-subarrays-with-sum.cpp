class Solution {
public:
    #include<deque>
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) {
        int ans = 0;
        int zeros = 0;

        for (int x : nums) {
            if (x == 0) {
                zeros++;
                ans += zeros;
            }
            else {
                zeros = 0;
            }
        }

        return ans;
    }

    deque<int> q;
    int ans = 0;
    int prevOne = -1;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] == 1) {
            q.push_back(i);

            if (q.size() > goal) {
                prevOne = q.front();
                q.pop_front();
            }

            if (q.size() == goal) {
                ans += q.front() - prevOne;
            }
        }
        else {
            if (q.size() == goal) {
                ans += q.front() - prevOne;
            }
        }
    }

    return ans;
}
};