class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        int st=0;
        int e=s.length()-1;
        while(st<e){
            if(s[st]==s[e]){
                st++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};