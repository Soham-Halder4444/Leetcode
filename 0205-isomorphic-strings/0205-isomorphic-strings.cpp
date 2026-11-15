class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
        string ans1="";
        string ans2="";
        for(int i=1;i<s.size();){
            if(s[i]==s[i-1] && t[i]==t[i-1]){
                ans1+=s[i];
                ans2+=t[i];
                i++;
            }
            else if(s[i]!=s[i-1] && t[i]!=t[i-1]){
                if(ans1.find(s[i])==ans2.find(t[i])){
                    ans1+=s[i];
                    ans2+=t[i];
                    i++;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        return 1; 
    }
};