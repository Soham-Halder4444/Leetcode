class Solution {
public:
    #include<map>
    #include<set>
    struct cmp {
        bool operator()(const pair<char,int>& a,const pair<char,int>& b) const {
            if (a.second == b.second) 
                return a.first < b.first; // tie-breaker: ascending by char
            return a.second > b.second;   // descending by number
        }
    };
    string frequencySort(string s) {
        string ans="";
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        set<pair<char,int>, cmp> s1;
        for (auto &kv : m) {
            s1.insert(kv); 
        }
        for (auto p : s1) {
            int val=p.second;
            while(val){
                ans+=p.first;
                val--;
            }
        }
        return ans;
    }
};