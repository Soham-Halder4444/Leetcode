class Solution {
public:
    int strStr(string haystack, string C) {
        size_t pos = haystack.find(C);
        if (pos != string::npos) {
            return (int)pos;  // found at index
        }
        return -1; 
    }
};