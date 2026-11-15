class Solution {
public:
    bool rotateString(string s, string goal) {
        string goal1=goal+goal;
        if(goal1.find(s)==string::npos){
            return 0;
        }
        return 1;
    }
};