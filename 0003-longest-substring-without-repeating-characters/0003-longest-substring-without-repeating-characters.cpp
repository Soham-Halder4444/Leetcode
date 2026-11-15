

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int hash[256];

        for(int i = 0; i < 256; i++)
            hash[i] = -1;

        int l = 0;
        int r = 0;
        int maxLen = 0;

        while(r < s.size()) {

            // Character has appeared before
            if(hash[s[r]] != -1) {

                // Move left only forward
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }

            // Update last occurrence
            hash[s[r]] = r;

            // Current window length
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};