class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        deque<int> q;
        int ans = 0;
        int prevOdd = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] %2 == 1) {
                q.push_back(i);

                if (q.size() > k) {
                    prevOdd = q.front();
                    q.pop_front();
                }

                if (q.size() == k) {
                    ans += q.front() - prevOdd;
                }
            }
            else {
                if (q.size() == k) {
                    ans += q.front() - prevOdd;
                }
            }
        }

        return ans;
    }
};