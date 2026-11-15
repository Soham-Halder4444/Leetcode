class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return 0;
        }
        vector<int> v1(26,0); 
        vector<int> v2(26,0); 
        for(int i=0;i<s.size();i++){
            v1[s[i]-'a']++;
            v2[t[i]-'a']++;
        }
        for(int i=0;i<=25;i++){
            if(v1[i]!=v2[i]){
                return 0;
            }
        }
        return 1;
    }
};