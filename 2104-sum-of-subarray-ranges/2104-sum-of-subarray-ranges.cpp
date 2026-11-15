class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1000000007;

        vector<int> left(n), right(n);
        vector<int> bleft(n), bright(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }
        //prev larger
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty())
                bleft[i] = -1;
            else
                bleft[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty())
                bright[i] = n;
            else
                bright[i] = st.top();

            st.push(i);
        }

        // Calculate contribution of every element
        long long lans = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            long long contribution =
                (1LL * (nums[i]) * leftCount ) * rightCount;

            lans = (lans + contribution);
        }
        long long rans = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - bleft[i];
            long long rightCount = bright[i] - i;
            long long contribution =
                (1LL * (nums[i]) * leftCount ) * rightCount;

            rans = (rans + contribution);
        }

        return rans-lans;
    }
};