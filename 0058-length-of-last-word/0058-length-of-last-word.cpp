class Solution {
public:
    int lengthOfLastWord(string s) {
        int size=s.length();
        int i=size-1;
        int cnt=0;
        while(s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            cnt++;
            i--;
        }
        return cnt;
    }
};