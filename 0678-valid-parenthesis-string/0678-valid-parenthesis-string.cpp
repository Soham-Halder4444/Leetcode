class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else { // '*'
                low--;   // treat '*' as ')'
                high++;  // treat '*' as '('
            }

            // Even the maximum possible '(' count is negative
            if (high < 0)
                return false;

            // low cannot be negative
            low = max(low, 0);
        }

        // There must be a possibility of having 0 unmatched '('
        return low == 0;
    }
};