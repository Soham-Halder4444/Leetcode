class Solution {
public:
    #include<stack>
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1000000007;

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
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
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // Calculate contribution of every element
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            long long contribution =
                (1LL * arr[i] * leftCount % MOD) * rightCount % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};