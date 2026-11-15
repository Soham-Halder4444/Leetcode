class Solution {
public:
    string minWindow(string s, string t){
        if (t.size() > s.size()) return "";

        vector<int> freq(128, 0);

        // Frequency required from t
        for (char c : t) {
            freq[c]++;
        }

        int l = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < s.size(); r++) {

            // If this character is still needed
            if (freq[s[r]] > 0) {
                required--;
            }

            freq[s[r]]--;

            // Window contains all characters of t
            while (required == 0) {

                // Update minimum window
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove s[l] from the window
                freq[s[l]]++;

                // If removing it makes the window invalid
                if (freq[s[l]] > 0) {
                    required++;
                }

                l++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};