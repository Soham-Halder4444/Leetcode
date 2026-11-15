class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> mp;

        // Store frequency
        for (int x : hand) {
            mp[x]++;
        }

        // Process cards in sorted order
        for (auto it : mp) {
            int card = it.first;

            // If this card is already used
            if (mp[card] == 0)
                continue;

            int freq = mp[card];

            // Try to create 'freq' groups starting from card
            for (int j = 0; j < groupSize; j++) {
                int current = card + j;

                if (mp[current] < freq)
                    return false;

                mp[current] -= freq;
            }
        }

        return true;
    }
};