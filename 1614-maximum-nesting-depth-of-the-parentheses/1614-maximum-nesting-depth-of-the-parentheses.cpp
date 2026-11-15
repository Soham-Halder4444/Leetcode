class Solution {
public:
    int maxDepth(string s) {
        int val=0;
        int maxval=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                val++;
                maxval=max(maxval,val);
            }
            else if(s[i]==')'){
                val--;
            }
            else{
                continue;
            }
        }
        return maxval;
    }
};