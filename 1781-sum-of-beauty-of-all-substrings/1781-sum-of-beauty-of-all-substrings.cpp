class Solution {
public:
    int beautySum(string s){
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> arr(26, 0);
            for (int j = i; j < s.size(); j++) {
                arr[s[j] - 'a']++;

                int maxi = 0, mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (arr[k] > 0) {
                        maxi = max(maxi, arr[k]);
                        mini = min(mini, arr[k]);
                    }
                }
                ans += (maxi - mini);
            }
        }
        return ans;
    }
};